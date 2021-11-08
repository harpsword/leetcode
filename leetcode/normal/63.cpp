#include <iostream>
#include <vector>
#include<string>
#include <set>
using namespace std;

// [[1]] 这种地图的输出结果为0
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (m==0) return 0;
        int n = obstacleGrid[0].size();
        if (n==0) return 0;
        vector<vector<long>> dp(m+1, vector<long>(n+1, 0));
        dp[0][0] = 1;
        vector<int> movex = {0, -1};
        vector<int> movey = {-1, 0};
        for (int i=0; i!=m; ++i)
            for (int j=0; j!=n; ++j){
                if (obstacleGrid[i][j]==1) dp[i][j] = 0;
                else if (i==0 && j==0) dp[i][j] = 1;
                else{
                    for (int k=0; k!=2; ++k){
                        int tmpx = i + movex[k];
                        int tmpy = j + movey[k];
                        if (tmpx < 0 || tmpy < 0) continue;
                        dp[i][j] += dp[tmpx][tmpy];
                    }
                }
            }
        return dp[m-1][n-1];
    }
};
