#include <iostream>
#include <vector>
#include <set>

using namespace std;
// dp[i] 表示到i处的最大利润
// 转移方程: dp[i] = max(dp[i-1], prices[i]-price[k]+dp[k-2], prices[i]-min_prices_before)
// 其中 3 <= k < i; 
// 第一项表示没有动作
// 第二项表示第k天买入第i天卖出的利润加上之前操作的利润之和
// 第三项表示之前最便宜的一天买入，今天卖出的利润
// 可以通过第i天计算max_before=dp[k-2] - price[k]，用于第i+1天的计算，来减少时间复杂度
// 注意max_before初始值应该为负无穷

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n+1, 0);
        if (n==0|| n==1) return 0;
        else if (n==2) return max(prices[1]-prices[0], 0);
        int a = max(prices[2]-prices[1], prices[2]-prices[0]);
        int b = max(prices[1]-prices[0], 0);
        dp[1] = max(prices[1]-prices[0], 0);
        dp[2] = max(a, b);
        if (n==3) return dp[2];
        int max_before = -1e9;
        int min_before = min(prices[0], prices[1]);
        min_before = min(min_before, prices[2]);
        for (int i=3; i!=n; i++){
            if (min_before > prices[i]) min_before = prices[i];
            dp[i] = max(prices[i]-min_before, max(dp[i-1], max_before+prices[i]));
            if (i>=3){
                max_before = max(max_before, dp[i-2]-prices[i]);
            }
        }
        return dp[n-1];
    }
};