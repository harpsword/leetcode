#include <iostream>
#include <vector>
#include<string>
#include <set>
using namespace std;


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m==0) return 0;
        int n = grid[0].size();
        if (n==0) return 0;
        vector<vector<int>> dp(m+1, vector<int>(n+1, 1e9));
        // dp[0][0] = grid[0][0];
        vector<int> movex = {0, -1};
        vector<int> movey = {-1, 0};
        for (int i=0; i!=m; ++i)
            for (int j=0; j!=n; ++j){
                if (i==0 && j==0) dp[i][j] = grid[0][0];
                else{
                    for (int k=0; k!=2; ++k){
                        int tmpx = i + movex[k];
                        int tmpy = j + movey[k];
                        if (tmpx < 0 || tmpy < 0) continue;
                        dp[i][j] = min(dp[i][j], dp[tmpx][tmpy]);
                    }
                    dp[i][j] += grid[i][j];
                }
            }
        return dp[m-1][n-1];
    }
};