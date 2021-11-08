#include <iostream>
#include <vector>
#include<string>
#include <set>
using namespace std;

// 倒过来计算

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dg) {
        int n=dg.size(),m=(n==0)?0:dg[0].size();
        int dp[n+5][m+5];
        for(int i=0;i<=n;++i) dp[i][m]=INT_MAX;
        for(int i=0;i<=m;++i) dp[n][i]=INT_MAX;
        for(int i=n-1;i>=0;--i)
            for(int j=m-1;j>=0;--j){
                if(i==n-1&&j==m-1) dp[i][j]=max(1,1-dg[i][j]);
                else dp[i][j]=max(1,min(dp[i+1][j],dp[i][j+1])-dg[i][j]);
            }
        return dp[0][0];
    }
};