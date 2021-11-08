#include <iostream>
#include <vector>
#include<string>
#include <set>
#include<algorithm>
using namespace std;

// 可以转换为背包大小为sum/2的背包问题，只要刚好得到sum/2的背包，那么则可以完成二分
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum{0};
        for (int i:nums) sum+=i;
        if (sum%2==1) return false;
        vector<bool> dp(sum/2+2, false);
        dp[0] = true;
        for (int j:nums){
            vector<bool> tmp{dp};
            for (int i=1; i<=sum/2; ++i)
                if (i>=j) dp[i] = dp[i] || tmp[i-j];
            if(dp[sum/2]) return true;
        }
        if (dp[sum/2]) return true;
        else return false;
    }
};