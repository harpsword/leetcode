#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
    vector<int> result;
public:

    void searchleft(vector<int>& nums, int target, int l, int r)
    {
        int mid_indx = (l+r)/2;
        int mid = nums[mid_indx];
        if (mid < target) searchleft(nums, target, mid_indx+1, r);
        else if (mid==target) {
            if (mid_indx>l && nums[mid_indx-1]==target) searchleft(nums, target, l, mid_indx-1);
            else result[0] = mid_indx;
        }
    }

    void searchright(vector<int>& nums, int target, int l, int r)
    {
        int mid_indx = (l+r)/2;
        int mid = nums[mid_indx];
        if (mid > target) searchright(nums, target, l, mid_indx-1);
        else if (mid==target) {
            if (mid_indx<r && nums[mid_indx+1]==target) searchright(nums, target, mid_indx+1, r);
            else result[1] = mid_indx;
        }
    }


    void search(vector<int>& nums, int target, int l, int r){
        if (l>r) return;
        int mid_indx = (l+r)/2;
        int mid = nums[mid_indx];
        if (mid > target) search(nums, target, l, mid_indx-1);
        else if (mid < target) search(nums, target, mid_indx+1, r);
        else {
            if (mid_indx > l && nums[mid_indx-1]==target) searchleft(nums, target, l, mid_indx-1);
            else result[0] = mid_indx;
            if (mid_indx < r && nums[mid_indx+1]==target) searchright(nums, target, mid_indx+1, r);
            else result[1] = mid_indx;
        }
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        result.push_back(-1);
        result.push_back(-1);
        search(nums, target, 0, nums.size()-1);
        return result;
    }
};