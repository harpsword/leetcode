#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> value = nums;
        sort(value.begin(), value.end());
        map<int, int> small_number;

        int before_value = -1;
        for (int i =0; i!=value.size(); i++){
            int v = value[i];
            if (before_value==-1){
                before_value = v;
                small_number.insert(pair<int, int>(v, 0));
            }else {
                if (before_value != v){
                    before_value = v;
                    small_number.insert(pair<int, int>(v, i));
                }
            }
        }

        for (int i =0; i!=value.size(); i++){
            value[i] = small_number[nums[i]];
        }
        return value;

    }
};