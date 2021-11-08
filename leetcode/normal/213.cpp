#include <iostream>
#include <vector>
#include <set>

using namespace std;
// 环状分布的房子，强盗抢劫难度更高
// 简化：可以分为两种情况
// 不抢劫第一个房子
// 不抢劫最后一个房子
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return 0;
        if (n==1) return nums[0];
        vector<int> one(nums.begin()+1, nums.end()), two(nums.begin(), nums.end()-1);
        int a = rob2(one);
        int b = rob2(two);
        return a > b? a:b;
    }

    int rob2(vector<int>& nums) {
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