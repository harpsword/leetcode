#include<iostream>
#include<set>
#include<queue>
#include<vector>

using namespace std;


class Solution {
public:
    int subtractProductAndSum(int n) {
        vector<int> number;
        
        while (n > 0)
        {
            number.push_back(n % 10);
            n = n / 10;
        }
        int s=0;
        int c = 1;
        for (int i : number){
            s += i;
            c *= i;
        }
        return c - s;
        
    }
};