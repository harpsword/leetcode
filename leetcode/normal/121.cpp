#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int InfPrice = 1e9;
        int min_price = InfPrice;
        int max_profit = 0;
        for (int i: prices){
            if (i < min_price) min_price = i;
            if (i - min_price > max_profit) max_profit = i - min_price;
        }
        return max_profit;
    }
};