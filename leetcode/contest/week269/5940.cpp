#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<deque>
#include<map>
#include<algorithm>

using namespace std;


class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minIndex = -1;
        int maxIndex = -1;
        int min = 100001;
        int max = -100001;
        for (int i = 0; i != nums.size(); i++) {
            int v = nums[i];
            if (v > max) {
                max = v;
                maxIndex = i;
            }
            if (v < min) {
                min = v;
                minIndex = i;
            }
        }
        int left, right;
        if (minIndex < maxIndex) {
            left = minIndex;
            right = maxIndex;
        } else {
            left = maxIndex;
            right = minIndex;
        }
        int r = left + 1 + nums.size() - right;
        if (right + 1 < r) {
            r = right +1;
        }
        if (nums.size() - left < r) {
            r = nums.size() - left;
        }
        return r;
    }
};

int main() {
    vector<int> input{52724,12510,62112};
    Solution s = Solution{};
    int r = s.minimumDeletions(input);
    return 1;
}
