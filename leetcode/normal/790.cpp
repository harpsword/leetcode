#include <iostream>
#include <vector>
#include <set>
#include<algorithm>

using namespace std;

class Solution {
public:
    int numTilings(int N) {
        if (N==0) return 0;
        vector<long> dp(N+4, 0);
        dp[0] = 1;
        dp[1] = 2;
        dp[2] = 5;
        const long d = 1e9+7;
        for (int i=3; i<N; ++i){
            dp[i] = (2*dp[i-1] + dp[i-3]) % d;
        }
        return dp[N-1];
    }
};