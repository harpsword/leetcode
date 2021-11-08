#include <iostream>
#include <vector>
#include<string>
#include <set>

using namespace std;

// dp[i][j]表示s1的前i个字符与s2的前j个字符 与 s3的前i+j个字符的匹配结果

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        if (n1+n2!=n3) return false;
        vector<vector<bool>> dp(n1+2, vector<bool>(n2+2, false));
        dp[0][0] = true;
        for (int j=1; j!=n2+1; ++j) dp[0][j] = ((s2[j-1]==s3[j-1]) && dp[0][j-1]);
        for (int i=1; i!=n1+1; ++i) dp[i][0] = ((s1[i-1]==s3[i-1]) && dp[i-1][0]);
        string tmp1{""}, tmp2{""};
        for (int i=1; i!=n1+1; ++i){
            for (int j=1; j!=n2+1; ++j){
                tmp1 = s1.substr(i-1, 1);
                tmp2 = s2.substr(j-1, 1);
                if ((tmp1+tmp2==s3.substr(i+j-2, 2)) || (tmp2+tmp1==s3.substr(i+j-2, 2))) dp[i][j] = dp[i-1][j-1];
                if (tmp1==s3.substr(i+j-1, 1)) dp[i][j] =dp[i-1][j] || dp[i][j];
                if (tmp2==s3.substr(i+j-1, 1)) dp[i][j] =dp[i][j-1] || dp[i][j];
            }
        }
        return dp[n1][n2];

    }
};

int main(){
    Solution s = Solution();
    cout << s.isInterleave("aabcc", "dbbca", "aadbbbaccc");
    return 0;
}