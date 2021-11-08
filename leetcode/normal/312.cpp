#include<iostream>
#include<set>
#include<vector>
#include<algorithm>

// dp[i][j]表示从nums[i]到nums[j]的气球都已经被消除的最大收益
// 计算时从消除一个气球开始，到消除n个气球结束
// 转移方程解释为 从i到j的j-i+1个气球中 随机寻找一个气球最为最后消除的气球，那么这些气球可以被分为两个部分(或者一个部分)，
// 单个部分的气球被消除的最大收益以及被提前将计算了(消除气球的个数小于j-i+1)
// 所以收益为两个部分的收益+ nums[l]*nums[i-1]*nums[j+1]
// l取值为i到j
using namespace std;

class Solution {
public:
    int get_value(vector<int>& nums, int i){
        if (i<0 || i>=nums.size()) return 1;
        else return nums[i];
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return nums[0];
        if (n==0) return 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i=0; i!=n; ++i){
            if (i==0) dp[i][i] = nums[0] * nums[1];
            else if (i==n-1) dp[i][i] = nums[i] * nums[i-1] * 1;
            else dp[i][i] = nums[i-1] * nums[i] * nums[i+1];
        }
        for (int k=2; k<=n; ++k){
            for (int i=0; i!=n; ++i){
                int j = i + k -1;
                if (j>=n) continue;
                int tmp{0};
                for (int l=i; l<=j; ++l){
                    if (l==i) tmp = dp[l+1][j];
                    else if (l==j) tmp = dp[i][l-1];
                    else tmp = dp[i][l-1]+dp[l+1][j];
                    tmp += get_value(nums, i-1)*nums[l]*get_value(nums, j+1);
                    dp[i][j] = max(tmp, dp[i][j]);
                }
            }
        }
        return dp[0][n-1];
    }
};

int main(){
    vector<int> ii = {3, 1, 5, 8};
    Solution s = Solution();
    int v = s.maxCoins(ii);
    return 0;
}