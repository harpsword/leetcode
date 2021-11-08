#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    long knightDialer(long N) {
        vector<long> dp(10, 1);
        const long mod = 1e9 + 7;
        vector<vector<long>> jump={{4, 6}, {6, 8}, {7, 9},{4, 8},{0, 3, 9},{},{0, 1, 7}, {2, 6}, {1, 3},{2, 4}};
        for (long i=1; i<N; ++i){
            vector<long> tmp;
            tmp = dp;
            for (long j=0; j!=10; ++j){
                dp[j]-=tmp[j];
                for (long k:jump[j]){
                    dp[k]+=tmp[j];
                }
            }
            for (int j=0; j!=10; ++j) dp[j]%=mod;
        }
        long s{0};
        for (long i:dp){
            s += i;
            s%=mod;
        }
        return s;
    }
};

int main(){
    Solution s = Solution();
    long ss = s.knightDialer(4);
    return 0;
}