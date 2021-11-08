#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    vector<int> closestDivisors(int num) {
        vector<int> v1 = closestD(num+1);
        vector<int> v2 = closestD(num+2);
        int diff1 = abs(v1[0]-v1[1]);
        int diff2 = abs(v2[0]-v2[1]);
        if (diff1 < diff2) return v1;
        return v2;

    }

    vector<int> closestD(int num){
        int mid = (int) sqrt((float)num);
        vector<int> v(2, 0);
        for (int i = mid; i>=1; i--){
            if (num % i == 0){
                v[0] = i;
                v[1] = num / i;
                return v;
            }
        }
    }
};