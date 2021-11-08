#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<deque>
#include<map>

using namespace std;

class Solution {
public:
    int countOrders(int n) {
        long before = 1;
        if (n == 1) return 1;
        long now = 1;
        const long big = 1000000007;
        for (int i = 2; i <= n; i++){
            int j = i - 1;
            now = ((2 * j + 1 + j * (2*j+1)) * before) % big;
            before = now;
        }
        return now;
    }
};