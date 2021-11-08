#include <iostream>
#include <vector>
#include<string>
#include <set>
using namespace std;

// dp[i][j]表示s的前i个字符与t的前j个字符进行操作，所拥有的子序列数量
class Solution {
public:
    long numDistinct(string s, string t) {
        long n1 = s.size();
        long n2 = t.size();
        vector<vector<long>> dp(n1+2, vector<long>(n2+2, 0));
        for (long i=0; i<=n1;++i) dp[i][0] = 1;
        for (long i=1; i<=n1; ++i){
            for (long j=1; j<=min(i, n2); ++j){
                if (s[i-1]==t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n1][n2];
    }
};

int main(){
    Solution s = Solution();
    string is = "rabbbit";
    string it = "rabbit";
    cout << s.numDistinct(is, it);
    return 0;
}