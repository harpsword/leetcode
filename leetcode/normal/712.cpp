#include <iostream>
#include <vector>
#include<string>
#include <set>
using namespace std;

// dp[i][j] 表示Word1的前i个字符 与 word2的前j个字符 需要的最小删除字符ascii值之和
// 注意初始值的设置 
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        vector<vector<int>> dp(n1+2, vector<int>(n2+2, 0));
        for (int i=1; i<=n1; ++i) dp[i][0] = dp[i-1][0]+(int)s1[i-1];
        for (int j=1; j<=n2; ++j) dp[0][j] = dp[0][j-1] + (int)s2[j-1];
        for (int i=1; i<=n1; ++i)
            for (int j=1; j<=n2; ++j){
                if (s1[i-1]==s2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else dp[i][j] = min(dp[i-1][j]+(int)s1[i-1], dp[i][j-1]+(int)s2[j-1]) ;
            }
        return dp[n1][n2];
    }
};

int main(){
    Solution s = Solution();
    string is = "sea";
    string it = "eat";
    cout << s.minimumDeleteSum(is, it);
    return 0;
}