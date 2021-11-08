#include <iostream>
#include <vector>
#include<string>
#include <set>
using namespace std;

// dp[i] 表示面值i能否用所有硬币实现

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,1e9);
        int min_coins = 1e9;
        dp[0] = 0;
        for (int i:coins) if (i<min_coins) min_coins = i;
        for (int i=min_coins; i<=amount; ++i){
            for (int coin:coins){
                if (i>=coin) dp[i] = min(dp[i], dp[i-coin]+1);
            }
        }
        if (dp[amount]!=1e9) return dp[amount];
        else return -1;
    }
};