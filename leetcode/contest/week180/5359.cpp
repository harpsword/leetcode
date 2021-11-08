
#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<deque>
#include<map>

using namespace std;

// 动态规划方法， 
// 该方法存在问题，有更好的解法：贪心法

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<long long> dp(k+1, 0);
        vector<long> speedSum(k+1, 0);
        vector<int> efficiencySmall(k+1, 100000000);
        int weight = 1;
        for (int j = 1; j<=n; j++){
            for (int i = k; i >= 1; i--)
            {
                long long tmp = (speedSum[i - weight] + speed[j-1]) * small(efficiencySmall[i-weight], efficiency[j-1]);
                if (tmp > dp[i]) {
                    dp[i] = tmp;
                    speedSum[i] = speedSum[i-weight] + speed[j-1];
                    efficiencySmall[i] = small(efficiencySmall[i-weight], efficiency[j-1]);
                };
                tmp = speed[j-1] * efficiency[j-1];
                if (tmp > dp[i]){
                    dp[i] = tmp;
                    speedSum[i] = speed[j-1];
                    efficiencySmall[i] = efficiency[j-1];
                }
            }
        }
        return dp[k] % 1000000007; 
    }

    int small(int a, int b){
        return a < b ? a:b;
    }
};

int main()
{
    vector<int> s_in = {2,10,3,1,5,8};
    vector<int> e_in = {5,4,3,9,7,2};
    Solution s = Solution();
    int v = s.maxPerformance(6, s_in, e_in, 2);
    cout << v;
    return 1;
}
