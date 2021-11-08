#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<deque>
#include<map>

using namespace std;

class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<double> prob(n+1, 0);
        queue<int> q;
        q.push(1);
        map<int, vector<int>> to;
        for (auto i : edges){
            int f = i[0]; int t_i = i[1];
            if (to.find(f) == to.end()) to[f] = vector<int>{t_i};
            else to[f].push_back(t_i);

            f = i[1];
            t_i = i[0];
            if (to.find(f) == to.end()) to[f] = vector<int>{t_i};
            else to[f].push_back(t_i);
        }

        int t_count = 0;
        prob[1] = 1.0;
        set<int> visited;
        visited.insert(1);
        while (!q.empty() && t_count < t){
            int kk = q.size();
            for (int i = 0; i!=kk; i++){
                int currentNode = q.front();
                q.pop();

                int to_size = 0;
                for (int k : to[currentNode]){
                    if (visited.find(k) == visited.end()){
                        // 未访问过
                        to_size++;
                    }
                }
                for (int k : to[currentNode]){
                    if (visited.find(k) == visited.end()){
                        // 未访问过
                        visited.insert(k);
                        prob[k] = prob[currentNode] / (double)to_size;
                        q.push(k);
                    }
                }
                if (to_size!=0) prob[currentNode] = 0;
            }
            t_count++;
        }
        return prob[target];
    }
};

int main(){

    Solution s = Solution();
    vector<vector<int>> input = {
        {2, 1},
        {3, 2},
        {4, 1},
        {5, 1},
        {6, 4},
        {7, 1},
        {8, 7}
    };
    cout << s.frogPosition(8, input, 7, 7);
    return 1;
}