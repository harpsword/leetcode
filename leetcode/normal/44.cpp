#include <iostream>
#include <vector>
#include<string>
#include <set>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n1 = s.length();
        int n2 = p.length();
        // const int InfInt = 1e9;
        vector<vector<bool>> dp(n1+1, vector<bool>(n2+1, false));
        // 初始条件
        dp[0][0] = true;
        if (p[0]=='*' && n2==1) return true;
        bool first_star = true;
        // 注意此处的初始化
        for (int j=1; j!=n2+1; ++j){
            if (p[j-1]=='*' && first_star){
                for (int i=0; i!=n1+1;++i) dp[i][j] = true;
                
            } else first_star = false;
        }
        for (int i=1; i!=n1+1; ++i){
            for (int j=1; j!=n2+1; ++j){
                if (s[i-1]==p[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else if (p[j-1]=='?') {
                    dp[i][j] = dp[i-1][j-1];
                }else if (p[j-1]=='*'){
                    // 用*来代替从 k到i的序列
                    for (int k=0; k<=i;++k){
                        if (dp[k][j-1]){
                            dp[i][j] = true;
                            break;
                        }
                    }
                } else dp[i][j] = false;
            }
        }
        return dp[n1][n2];
    }
};

int main(){
    Solution s = Solution();
    string ss = "ho";
    string p = "**ho";
    bool b = s.isMatch(ss, p);
    return 1;
}