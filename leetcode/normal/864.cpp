#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<map>

using namespace std;

// 迷宫拿钥匙，找到所有钥匙就ok
// 典型BFS或者变长DFS


class Solution {
public:
    struct State
    {
        int i, j;
        int state;
    };
    
    bool isEmptyCell(char& ch){
        return ch == '.';
    }
    bool isWall(char& ch){
        return ch=='#';
    }
    bool isStart(char& ch){
        return ch=='@';
    }
    bool isLower(char& ch){
        // Key
        return ch >= 'a' && ch <='z';
    }
    bool isUpper(char& ch){
        // Lock
        return ch>='A' && ch<='Z';
    }
    int getState(const State& s){
        return ((s.i << 16) | (s.j << 10)) | s.state;
    }
    int shortestPathAllKeys(vector<string>& grid) {
        int l = grid.size();
        if (l==0) return 0;
        int r = grid[0].size();
        map<char, int> value;
        int i = 0;
        for (char s='a'; s<='f';++s){
            value.insert({s, 1 << i});
            value.insert({s-32, 1 << i});
            i++;
        }
        int FinishState = 0;
        int start_i, start_j;
        for (int i=0; i!=l;++i){
            for (int j=0; j!=r; ++j){
                if (isStart(grid[i][j])) {
                    start_i = i;
                    start_j = j;
                }
                if (isLower(grid[i][j])) {
                    FinishState = FinishState | value[grid[i][j]];
                }
            }
        }
        
        queue<State> q;
        set<int> visited;
        State start_state = State();
        start_state.i = start_i;
        start_state.j = start_j;
        start_state.state = 0;
        visited.insert(getState(start_state));
        q.push(start_state);
        
        vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int steps{0};
        while (!q.empty()){
            int s = q.size();
            while (s--){
                State p = q.front();
                q.pop();
                // check
                if (p.state==FinishState) return steps;
                for (i=0; i!=direction.size();++i){
                    State tmp = State();
                    tmp.i = p.i + direction[i][0];
                    tmp.j = p.j + direction[i][1];
                    tmp.state = p.state;
                    if (tmp.i>=l || tmp.i<0 || tmp.j >= r || tmp.j<0) continue;
                    if (isWall(grid[tmp.i][tmp.j])) continue;
                    // cout << grid[tmp.i][tmp.j] << endl;
                    // cout << ((p.state & value[grid[tmp.i][tmp.j]])==0) << endl;
                    // cout << (p.state & value[grid[tmp.i][tmp.j]]==0) << endl;
                    // for example :{"@Aa"}
                    // A
                    // 1
                    // 0
                    // 优先级的原因，== 优先级高于&
                    if (isUpper(grid[tmp.i][tmp.j]) && (!(p.state & value[grid[tmp.i][tmp.j]]))){
                        continue;
                    }
                    if (isLower(grid[tmp.i][tmp.j])){
                        tmp.state = p.state | value[grid[tmp.i][tmp.j]];
                    }
                    if (visited.count(getState(tmp))) continue;
                    if (tmp.state==FinishState) return steps+1;
                    visited.insert(getState(tmp));
                    q.push(tmp);
                }
            }
            steps++;
        }

        return -1;

    }
};

int main(){
    Solution s = Solution();
    // vector<string> ss = {"@.a.#","###.#","b.A.B"};
    vector<string> ss = {"@Aa"};
    return s.shortestPathAllKeys(ss);

}