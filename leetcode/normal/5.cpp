#include <iostream>
#include <vector>
#include <string>

using namespace std;

// if s[i]==s[j], dp[i][j] = dp[i+1][j-1]
// else dp[i][j] = false

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n+1, vector<bool>(n+1, false));
        int max_len{1};
        int max_i{0}, max_j{0};

        for (int k=1; k<=n; k++){
            if (k==1){
                for (int i=0; i!=n; ++i) dp[i][i] = true;
            }else {
                for (int i=0; i!=n; ++i){
                    int j = i + k -1;
                    if (j>=n) continue;
                    if (s[i]!=s[j]) dp[i][j] = false;
                    else {
                        if (k==2) dp[i][j] = true;
                        else dp[i][j] = dp[i+1][j-1];
                    }
                    if (dp[i][j] && k > max_len){
                        max_i = i;
                        max_j = j;
                        max_len = k;
                    }
                }
            }
        }
        return s.substr(max_i, max_len);
    }
};