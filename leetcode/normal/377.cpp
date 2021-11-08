#include <iostream>
#include <vector>
#include<string>
#include <set>
using namespace std;

// dp[i] 表示组成i有多少种方案

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        long n = nums.size();
        vector<unsigned long long> dp(target+1, 0);
        dp[0] = 1;
        for (long i=1; i<=target; ++i){
            for (long j:nums){
                if (i-j>=0) dp[i] += dp[i-j];
            }
        }
        // for (long i:dp) cout << i << " ";
        return dp[target];
    }
};