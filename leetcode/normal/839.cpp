#include<iostream>
#include<set>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<map>
// N^2*W
// 先根据字符串匹配结果建立无向图
// 无向图中的连通分量即结果
using namespace std;


class Solution {
public:
    int numSimilarGroups(vector<string>& A) {
        int count{0};
        int n = A.size();
        if (n==0) return 0;
        vector<vector<int>> to(n, vector<int>());
        for (int i = 0;i!=n;i++)
            for(int j=0;j!=i;j++){
                if (similar(A[i], A[j])){
                    to[i].push_back(j);
                    to[j].push_back(i);
                }
            }
        set<int> visited;
        int result{0};
        while (visited.size()<n){
            for (int i=0;i!=n;i++){
                if (visited.find(i)==visited.end()){
                    dfs(i, to, visited);
                    break;
                }
            }
            result++;
        }
        return result;
    }

    void dfs(int node, vector<vector<int>>& to, set<int>& visited){
        visited.insert(node);
        for (int next_node: to[node]){
            if (visited.find(next_node) == visited.end())
                dfs(next_node, to, visited);
        }
    }

    bool similar(string& A, string& B){
        int count{0};
        for (int i=0;i!=A.size();i++){
            if (A[i]!=B[i]){
                count++;
                if (count>2) return false;
            }
        }
        return true;
    }
};