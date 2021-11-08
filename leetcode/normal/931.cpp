#include <iostream>
#include <vector>
#include <set>
#include<algorithm>

using namespace std;


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 1e9));
        for (int i=0; i!=n; ++i) dp[0][i] = A[0][i];
        vector<int> change = {-1, 0, +1};
        for (int i=1; i!=n; ++i)
            for (int j=0; j!=n; ++j){
                for (int k:change){
                    int bj = j + k;
                    if (bj <0 || bj >=n) continue;
                    dp[i][j] = min(dp[i][j], dp[i-1][bj]+A[i][j]);
                }
            }
        int min_v = 1e9;
        for (int v:dp[n-1]) min_v = min(min_v, v);
        return min_v;
    }
};

int main(){
    Solution s = Solution();
    vector<vector<int>> iA = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int v = s.minFallingPathSum(iA);
    return 0;
}