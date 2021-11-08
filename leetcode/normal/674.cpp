#include <iostream>
#include <vector>
#include<string>
#include <set>
using namespace std;


class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        if (n==0 || n==1) return n;
        vector<int> dp(n, 1);
        int max_value{0};
        for (int i=1; i!=n; ++i){
            if (nums[i]>nums[i-1]) dp[i] = dp[i-1] + 1;
            else dp[i] = 1;
            if (dp[i]>max_value) max_value = dp[i];
            // cout << dp[i] << " ";
        }
        return max_value;
    }
};

