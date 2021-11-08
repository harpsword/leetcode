#include <iostream>
#include <vector>
#include<string>
#include <set>
using namespace std;

class Solution {
public:
    long uniquePaths(long m, long n) {
        vector<vector<long>> dp(m+1, vector<long>(n+1, 0));
        dp[0][0] = 1;
        vector<int> movex = {0, -1};
        vector<int> movey = {-1, 0};
        for (int i=0; i!=m; ++i)
            for (int j=0; j!=n; ++j){
                if (i==0 && j==0) dp[i][j] = 1;
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