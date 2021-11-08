#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         auto l = nums.size();
//         for (int i=0; i!=l; i++){
//             if (nums[i]==target) return i;
//         }
//         return -1;
//     }
// };

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int length = nums.size();
        int l = 0; 
        int r = length - 1;
        while (l<=r)
        {
            int mid = (l+r)/2;
            if (nums[mid]==target) return mid;
            else if (nums[mid]>target) r = mid - 1;
            else if (nums[mid]<target) l = mid + 1;
        }
        return -1;
    }
};

int main(){
    Solution s = Solution();
    vector<int> nums = {5};
    cout << s.search(nums, 1);
}