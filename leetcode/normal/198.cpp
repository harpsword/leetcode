#include <iostream>
#include <vector>
#include <set>

using namespace std;

// dp[i] 表示第i家被抢劫的最大利润
// 转移方程: dp[i] = max(dp[i-2], dp[i-3]) + nums[i]; i>=3
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return 0;
        if (n==1) return nums[0];
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = nums[1];
        int result = dp[0] > dp[1] ?dp[0]:dp[1];
        for (int i=2; i<n; ++i){
            if (i==2) dp[i] = dp[i-2] + nums[i];
            else dp[i] = max(dp[i-2], dp[i-3]) + nums[i];
            if (dp[i]>result) result = dp[i];
        }
        return result;
    }
};