#include <iostream>
#include <vector>
#include <set>

using namespace std;

class NumArray {
    vector<int> sum;
public:
    NumArray(vector<int>& nums) {
        for (int i:nums){
            if (sum.empty()) sum.push_back(i);
            else sum.push_back(*(sum.end()-1) + i);
        }
    }
    
    int sumRange(int i, int j) {
        if (i==0) return sum[j];
        else return sum[j] - sum[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */


