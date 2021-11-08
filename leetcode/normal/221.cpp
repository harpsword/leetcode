#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (n==0) return 0;
        int m = matrix[0].size();
        if (m==0) return 0;
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        int max_square = 0;
        for (int i=0; i!=n; ++i)
            for (int j=0; j!=m; ++j){
                if (matrix[i][j]=='1'){
                    if (i==0 || j==0) dp[i][j] = 1;
                    else {
                        dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]))+1;
                    }
                    if (dp[i][j]*dp[i][j]>max_square) 
                        max_square = dp[i][j] * dp[i][j];
                }
            }
        return max_square;
    }
};