#include<iostream>
#include<set>
#include<queue>
#include<vector>

using namespace std;


class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        int n = nums.size();
        vector<int> r;

        for (int i = 0; i < n; i=i+2){
            for (int j = 0; j != nums[i]; j++)
                r.push_back(nums[i+1]);
        }
        return r;
    }
};