#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<deque>
#include<map>
#include <cmath>

using namespace std;


class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int r = 0;
        for (int i: nums){
            r += sumDivisors(i);
        }
        return r;
    }

    int sumDivisors(int a){
        int count = 2;
        int r = a + 1;
        for (int i = 2; i <= static_cast<int>(sqrt(static_cast<float>(a))); i++){
            if (a % i == 0) {
                if (count >= 4) return 0;
                if (a / i == i) {
                    count++;
                    r += i;
                }else {
                    count += 2;
                    r = r + i + (a / i);
                }
            }
        }
        if (count == 4) return r;
        else return 0;
    }
};