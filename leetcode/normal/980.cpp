#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<unordered_set>
#include<algorithm>
// 动态规划
using namespace std;


class Solution {
    int mx[4] = {0, 0, 1, -1}, my[4] = {1, -1, 0, 0};
    int l, r;
public:
    int node_id(int i, int j){
        return r * i + j;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        l = grid.size();
        if (l==0) return 0;
        r = grid[0].size();
        int n = l * r;
        int FinishState = 0;
        int end_i, end_j;
        for (int i=0; i!=l; ++i){
            for (int j=0; j!=r; ++j){
                if (grid[i][j]==0 || grid[i][j] == 1){
                    FinishState |= (1<<node_id(i, j));
                }
                if (grid[i][j]==2){
                    end_i = i; end_j = j;
                }
            }
        }
        return dp(grid, FinishState, end_i, end_j);
    }

    int dp(vector<vector<int>>& grid, int State, int node_i, int node_j){
        // State 中已经将 (node_i, node_j)的访问记录除去
        if (grid[node_i][node_j] == 1) return State == 0;
        int ans = 0;
        for (int i=0; i!=4; i++){
            int tmp_i = node_i + mx[i];
             int tmp_j = node_j + my[i];
            if (tmp_i < 0 || tmp_i >=l || tmp_j < 0 || tmp_j >=r) continue;
            if (grid[tmp_i][tmp_j]==-1) continue;
            // 查看(tmp_i, tmp_j)是否是已经访问过的节点
            if (!((1 << node_id(tmp_i, tmp_j)) & State)) continue;
            // 计算节点(tmp_i, tmp_j)处的解的数量，注意此时的State计算为除去 节点(tmp_i, tmp_j)的访问记录
            ans += dp(grid, State ^ (1 << node_id(tmp_i, tmp_j)), tmp_i, tmp_j);
        }
        return ans;
    }
};

int main(){
    // vector<vector<int>> I = {{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
    vector<vector<int>> I = {{1, 0, 0}, {0, 0, 2}};
    Solution s = Solution();
    int ttt =  s.uniquePathsIII(I);
}