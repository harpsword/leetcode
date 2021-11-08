#include <iostream>
#include <vector>
#include<string>
#include <set>
#include <algorithm>
using namespace std;

// dp[i] 表示到第i天的最少花费
// dp[days[i]] = min(dp[days[i]], dp[max(days[i]-effect_days[k], 0)]+costs[k]); k=0,1,2
// 对于不在days[i]内的天数a来说，dp[a]=dp[a-1]
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366, 1e9);
        dp[0] = 0;
        sort(days.begin(), days.end());
        vector<int> effect_days = {1, 7, 30};
        int max_value{0};
        for (int i=0; i!=days.size();++i){
            if (i==0){
                for (int j=1; j<days[i];++j) dp[j] = dp[j-1];
            }else{
                for (int j=days[i-1]+1; j<days[i];++j) dp[j] = dp[j-1];
            }
            for (int k=0; k!=3; ++k){
                dp[days[i]] = min(dp[days[i]], dp[max(days[i]-effect_days[k], 0)]+costs[k]);
            }
        }
        return dp[*(days.end()-1)];
    }
};

int main(){
    Solution s = Solution();
    vector<int> i1 = {1,2,3,4,6,8,9,10,13,14,16,17,19,21,24,26,27,28,29};
    vector<int> i2 = {3, 14, 50};
    cout << s.mincostTickets(i1, i2);
    return 0;
}