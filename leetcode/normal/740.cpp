#include <iostream>
#include <vector>
#include <set>
#include<algorithm>

using namespace std;

// 先排序
// dp[i] 表示到第i个元素的最大收益
// dp[i] = max(nums[k]+nums[i]*same_number, dp[i-1]), 其中k是满足nums[k]与nums[i]的差值大于1情况下的最大值
// same_number为到i位置有多少个相同的nums[i]
// 可以理解为当前元素被主动删除获得利益 与 不进行任何操作 两种
// 当前元素被主动删除时则需要进行计算 之前获取的利益与本次能获取的利益(注意相同元素的存在)
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n==0) return 0;
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        int same_number = 1;
        for (int i=1; i!=n; ++i){
            if (nums[i]==nums[i-1]) same_number++;
            else same_number=1;
            int before = 0;
            for (int k=i-1; k>=0; --k){
                if (abs(nums[i]-nums[k])>1) {
                    before = dp[k];
                    break;
                }
            }
            dp[i] = max(before+nums[i]*same_number, dp[i-1]);
        }
        return dp[n-1];
    }
};

int main(){
    Solution s = Solution();
    vector<int> nums = {3, 4, 2};
    return s.deleteAndEarn(nums);
}