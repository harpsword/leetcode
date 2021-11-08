#include<iostream>
#include<set>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
using namespace std;
// 二分图，当做颜色问题

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        set<int> visited;
        int n = graph.size();
        if (n<=2) return true;
        vector<int> color(n, -1);
        while (visited.size()<n){
            for (int i=0; i!=n;i++){
                if (visited.find(i)==visited.end()){
                    if (!dfs(graph, visited, i, 0, color)){
                        return false;
                    }
                }
            }
        }
        return true;
    }

    bool dfs(vector<vector<int>>& graph, set<int>& visited, int node, int firstcolor, vector<int>& color){
        visited.insert(node);
        color[node] = firstcolor;
        for (auto i:graph[node]){
            if (visited.find(i)==visited.end()){
                bool p = dfs(graph, visited, i, 1-firstcolor, color);
                if (!p) return false;
            }else{
                if(firstcolor==color[i]) return false;
            }
        }
        return true;
    }
};


int main(){
    vector<vector<int>> A={{2,3,5,6,7,8,9},{2,3,4,5,6,7,8,9},{0,1,3,4,5,6,7,8,9},{0,1,2,4,5,6,7,8,9},{1,2,3,6,9},{0,1,2,3,7,8,9},{0,1,2,3,4,7,8,9},{0,1,2,3,5,6,8,9},{0,1,2,3,5,6,7},{0,1,2,3,4,5,6,7}};
    Solution s = Solution();
    cout << s.isBipartite(A);
    return 1;
}