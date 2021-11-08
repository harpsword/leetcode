#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        map<int, int> dp;
        int sum{0};
        for (int i:nums) sum+=i;
        if (S>sum || S<-sum) return 0;

        for (int i=-sum; i<=sum; ++i) dp.insert(pair<int,int>(i, 0));
        dp[0] = 1;
        map<int, int> tmp;
        for (int i:nums){
            tmp = dp;
            for (int j=-sum; j<=sum; ++j) dp[j] = 0;
            for ( int j=-sum; j<=sum; ++j){
                if (tmp[j]){
                    if (j+i<=sum) dp[j+i]+=tmp[j];
                    if (j-i>=-sum) dp[j-i]+=tmp[j];
                }
            }
        }
        return dp[S];
    }
};

int main(){
    Solution s = Solution();
    vector<int> ii = {1, 1, 1, 1, 1};
    int ss = s.findTargetSumWays(ii, 3);
    return 0;
}