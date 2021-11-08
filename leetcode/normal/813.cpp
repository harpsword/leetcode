#include<iostream>
#include<set>
#include<vector>
// #include<algorithm>
// 先检查有无环路
using namespace std;

// dp[i] 表示0到i的元素经过k次分组后的均值之和

class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int n = A.size();
        vector<double> ss(n+1, 0);
        ss[0] = A[0];
        for (int i=1; i!=n; ++i) ss[i] = ss[i-1] + A[i];

        vector<double> dp(n+1, 0);
        for (int i=0; i!=n; ++i) dp[i] = ss[i] / (i+1);
        vector<double> tmp;

        for (int k=2; k<=K; ++k){
            tmp = dp;
            for (int i=k-1; i!=n; ++i){
                dp[i] = 0;
                for (int j=k-2; j<=i-1; ++j){
                    dp[i] = max(dp[i], tmp[j]+(ss[i]-ss[j])/(i-j));
                }
            }
        }
        return dp[n-1];
    }
};

int main(){
    Solution s = Solution();
    vector<int> A = {9,1,2,3,9};
    double r = s.largestSumOfAverages(A, 3);
    return 0;
}