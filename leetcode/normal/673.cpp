#include <iostream>
#include <vector>
#include<string>
#include <set>
using namespace std;

// dp[i] 表示以nums[i]为子序列最后一个元素的最大 上升子序列长度
// dp[i] = 1 + max(dp[j], with nums[j] < nums[i] and j < i)
// 简单的解法为n^2
// number_max[i] 表示以nums[i]为子序列最后一个元素的最大 上升子序列的数量

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n==0 || n==1) return n;
        vector<int> dp(n, 1);
        vector<int> number_max(n, 1);
        for (int i=1; i!=n; ++i){
            for (int j=0;j!=i; ++j){
                if (nums[i] > nums[j] && dp[i] < dp[j]+1) {
                    dp[i] = dp[j]+1;
                    number_max[i] = number_max[j];
                } else if (dp[i]==dp[j]+1) number_max[i]+=number_max[j];
            }
        }
        int max_value{0};
        int max_count{0};
        for (int i=0; i!=n;++i){
            if (dp[i]>max_value){
                max_value = dp[i];
                max_count = number_max[i];
            } else if (dp[i]==max_value){
                max_count += number_max[i];
            }
        }
        return max_count;
    }
};