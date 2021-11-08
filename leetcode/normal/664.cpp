#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        if (n==0) return 0;
        if (n==1) return 1;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int k=0; k!=n; ++k){
            for (int i=0; i!=n; ++i){
                int j = i + k;
                if (j>=n) continue;
                if (i==j) dp[i][j] = 1;
                else dp[i][j] = 1e6;
                for (int l=i; l<j; ++l)
                    dp[i][j] = min(dp[i][j], dp[i][l]+dp[l+1][j]-(s[i]==s[j]));
            }
        }
        return dp[0][n-1];
    }
};

int main(){
    string is = "aaabbb";
    Solution s = Solution();
    int r = s.strangePrinter(is);
    return 0;
}