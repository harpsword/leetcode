#include <iostream>
#include <vector>
#include<string>
#include <set>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        if (m==0) return 0;
        if (m==1) return triangle[0][0];
        vector<vector<int>> dp(m+1, vector<int>(m+1, 1e9));
        vector<int> movey = {-1, 0};
        for (int i=0; i!=m; ++i)
            for (int j=0; j<=i; ++j){
                if (i==0 && j==0) dp[0][0] = triangle[0][0];
                else {
                    for (int k=0; k!=2; ++k){
                        int tmpx = i - 1;
                        int tmpy = j + movey[k];
                        if (tmpx < 0 || tmpy < 0 || tmpy > i) continue;
                        dp[i][j] = min(dp[i][j], dp[tmpx][tmpy]);
                    }
                    dp[i][j] += triangle[i][j];
                }
            }
        int r = 1e9;
        for (int i=0; i!=m; ++i) r = min(r, dp[m-1][i]);
        return r;
    }
};