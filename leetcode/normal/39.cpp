#include <iostream>
#include <vector>
#include<string>
#include <set>
using namespace std;

// 留着
// 注意输出结果为无顺序的

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // long n = candidates.size();
        vector<unsigned long long> dp(target+1, 0);
        vector<vector<vector<int>>> result(target+1, vector<vector<int>>());
        dp[0] = 1;
        vector<int> tmp;
        result[0].push_back(tmp);
        for (long i=1; i<=target; ++i){
            for (long j:candidates){
                if (i-j>=0) {
                    dp[i] += dp[i-j];
                    for (auto k:result[i-j]){
                        k.push_back(j);
                        result[i].push_back(k);
                    }
                }
            }
        }
        return result[target];
    }
};

int main(){
    Solution s = Solution();
    vector<int> ii{2, 3, 6, 7};
    vector<vector<int>> tmp = s.combinationSum(ii, 7);
    return 0;
}