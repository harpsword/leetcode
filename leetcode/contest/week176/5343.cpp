#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& target) {
        int s = target.size();
        long sum = 0;
        for (int i:target){
            sum += i;
        }

        for (int i = 0; i!=s ; i++){
            auto maxPosition = max_element(target.begin(), target.end());
            if (*maxPosition==1) return true;
            int beforeMax = *maxPosition;
            if (*maxPosition < s) return false;
            sum -= *maxPosition;
            
            *maxPosition = *maxPosition - sum;
            if (*maxPosition <= 0) return false;
            sum += *maxPosition;
            if (beforeMax != sum) return false;
        }
        return true;
    }
};


int main(){
    Solution s = Solution();
    vector<int> input = {1, 1, 1, 1, 11, 16};
    bool i = s.isPossible(input);
    cout << i;
    return 1;
}