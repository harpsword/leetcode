#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<deque>
#include<map>

using namespace std;

class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        long count = 0;
        long countL = 0;

        int output = 0;
        for (int i = 0; i != light.size(); i++){
            count += (i+1);
            countL += light[i];
            if (count == countL) output++;
        }
        return output;
    }
};