#include <iostream>
#include <vector>
#include<string>
#include <set>
using namespace std;

// dp[i] 表示以nums[i]为子序列最后一个元素的最大 上升子序列长度

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n==0 || n==1) return n;
        vector<int> dp(n, 1);
        int max_value{0};
        for (int i=1; i!=n; ++i){
            for (int j=0;j!=i; ++j){
                if (nums[i] > nums[j] && dp[i] < dp[j]+1) dp[i] = dp[j]+1;
            }
            if (dp[i]>max_value) max_value = dp[i];
            // cout << dp[i] << " ";
        }
        return max_value;
    }
};