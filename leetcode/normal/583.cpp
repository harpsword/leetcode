#include <iostream>
#include <vector>
#include<string>
#include <set>
using namespace std;

// dp[i][j] 表示Word1的前i个字符 与 word2的前j个字符 需要的最少删除次数
// 注意初始值的设置 dp[i][0] = i; dp[0][j]=j
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1+2, vector<int>(n2+2, 0));
        for (int i=1; i<=n1; ++i) dp[i][0] = i;
        for (int j=1; j<=n2; ++j) dp[0][j] = j;
        for (int i=1; i<=n1; ++i)
            for (int j=1; j<=n2; ++j){
                if (word1[i-1]==word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else dp[i][j] = min(dp[i-1][j], dp[i][j-1]) +1;
            }
        return dp[n1][n2];
    }
};

int main(){
    Solution s = Solution();
    string is = "sea";
    string it = "eat";
    cout << s.minDistance(is, it);
    return 0;
}