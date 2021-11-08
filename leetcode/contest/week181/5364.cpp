
#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<deque>
#include<map>

using namespace std;

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> output;
        for (int i = 0; i!=nums.size(); i++){
            output.insert(index[i]+output.begin(), nums[i]);
        }
        return output;
    }
};