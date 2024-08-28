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
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> result(nums.size(), 0);
        vector<long> sum(nums.size()+2, 0);
        long sumA = 0;

        for (int i=0; i != nums.size(); i++) {
            sumA += nums[i];
            sum[i+1] = sumA;
        }
        sum[nums.size()+1] = sumA;
        int v = 2 * k + 1;
        for (int i = 0; i != nums.size(); i++) {
            if (i - k < 0 || i + k >= nums.size()) {
                result[i] = -1;
            } else {
                result[i] = (sum[i+k+1] - sum[i-k])/v;
            }
        }
        return result;
    }
};

int main() {
    vector<int> input{7,4,3,9,1,8,5,2,6};
    Solution s = Solution{};
    vector<int> r = s.getAverages(input, 0);
    return 1;
}
