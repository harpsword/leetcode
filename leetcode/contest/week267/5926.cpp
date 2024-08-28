
#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<deque>
#include<map>

using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int value = 0;
        for (int i = 0; i != tickets.size(); i ++) {
            if (i <= k) {
                value += min(tickets[i], tickets[k]);
            } else {
                value += min(tickets[i], tickets[k]-1);
            }
        }
        return value;
    }
};