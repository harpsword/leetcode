#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        // 关键在于定义搜索过程中的状态
        // 状态定义为 current node , visited node(binary code)
        // 1 << n; 为 2^n，比如 1 << 1 = 00001
        int n = graph.size();
        const int FinishState = (1 << n) - 1;
        unordered_set<int> visited;
        queue<pair<int, int>> q;
        for (int i=0; i!=n; i++){
            q.push(pair<int, int>(i, 1 << i));
        }
        int step = 0;
        while (!q.empty())
        {
            int s = q.size();
            while (s--)
            {
                auto p = q.front();
                q.pop();
                int node = p.first;
                int state = p.second;
                if (state == FinishState) return step;
                int key = (node << 16) | state;
                if (visited.count(key)) continue;
                visited.insert(key);
                for (int i : graph[node]){
                    q.push({i, state | (1<<i)});
                }
            }
            step++;
        }
        return -1;
    }
};
