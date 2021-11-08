#include <iostream>
#include <vector>
#include <set>

using namespace std;
// dp[i] 定义： 以元素nums[i]结尾的最大子串和

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 0);
        dp[0] = nums[0];
        int max_value = dp[0];
        for (int i=1; i<n; ++i){
            dp[i] = max(nums[i], nums[i]+dp[i-1]);
            if (dp[i] > max_value) max_value = dp[i];
        }
        return dp[n-1];
    }
};