#include <iostream>
#include <vector>
#include<string>
#include <set>
using namespace std;

// DP

class Solution {
public:
    bool isMatch(string s, string p) {
        int n1 = s.length();
        int n2 = p.length();
        // const int InfInt = 1e9;
        vector<vector<bool>> dp(n1+1, vector<bool>(n2+1, false));
        // 初始条件
        dp[0][0] = true;
        for (int i=1; i!=n2+1; ++i)
            if (p[i-1]=='*') dp[0][i] = dp[0][i-2];
        for (int i=1; i!=n1+1; ++i){
            for (int j=1; j!=n2+1; ++j){
                if (s[i-1]==p[j-1] || p[j-1]=='.'){
                    dp[i][j] = dp[i-1][j-1];
                }else if (p[j-1]=='*'){
                    if (j>=2){
                        // *表示至少一个字符
                        if (s[i-1]==p[j-2] || p[j-2]=='.') dp[i][j] = dp[i-1][j];
                        // *表示没有字符或者 a*表示无字符
                        if (dp[i][j-2] || dp[i][j-1]) dp[i][j] = true;
                    }
                }
            }
        }
        return dp[n1][n2];
    }
};

int main(){
    Solution s = Solution();
    string ss = "aaa";
    string p = "a*";
    bool b = s.isMatch(ss, p);
    return 1;
}