#include<iostream>
#include<vector>
#include<set>

using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        set<int> visited;
        int count{0};

        while (visited.size() < M.size()){
            // select first node to visit
            int root{0};
            for(int i=0; i!=M.size();i++)
                if (visited.find(i)==visited.end()){
                    root = i;
                    break;
                }
            visited.insert(root);
            dfs(M, visited, root);
            count++;
        }
        return count;
    };

    void dfs(vector<vector<int>>& M, set<int>& visited, int node){
        // node: node's id, [0, size-1]
        for(int i=0; i!=M.size(); i++)
        {
            if (M[node][i]==1 && visited.find(i)==visited.end()){
                visited.insert(i);
                dfs(M, visited, i);
            }
        }
    }
};

int main(){
    return 0;
}