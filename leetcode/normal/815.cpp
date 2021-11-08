#include<iostream>
#include<set>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;
// BFS 解法

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if (S==T) return 0;
        int n = routes.size();
        map<int, vector<int>> child;
        // 第一次遇到建立vector<int>并添加route id，第二次遇到添加相关的route id
        vector<int> start_route;
        set<int> end_route;
        for (int i=0; i!=routes.size(); ++i){
            for (int j:routes[i]){
                if (child.count(j)==0){
                    child.insert({j, vector<int>()});
                    child[j].push_back(i);
                } else {
                    child[j].push_back(i);
                }
                if (j==S) start_route.push_back(i);
                if (j==T) end_route.insert(i);
            }
        }
        vector<int> visited(501, 0);
        queue<int> q;
        for (int i:start_route){
            if (!visited[i]) {
                q.push(i);
                visited[i] = 1;
            }
        }
        int step = 1;
        // cout << q.size() << endl;
        while(!q.empty()){
            int s = q.size();
            while (s--){
                int p = q.front();
                // cout << p << endl;
                q.pop();
                // check and add mark it to visited
                if (end_route.count(p)) return step;
                for (int i: routes[p]){
                    for (int j: child[i]){
                        // cout << j << " ";
                        if (!visited[j]){
                            q.push(j);
                            visited[j] = 1;
                        }
                    }
                }
            }
            step++;
        }
        return -1;
    }
};

int main(){
    Solution s = Solution();
    vector<vector<int>> dd = {{10,13,22,28,32,35,43},{2,11,15,25,27},{6,13,18,25,42},{5,6,20,27,37,47},{7,11,19,23,35},{7,11,17,25,31,43,46,48},{1,4,10,16,25,26,46},{7,11},{3,9,19,20,21,24,32,45,46,49},{11,41}};
    return s.numBusesToDestination(dd, 37, 43);
}