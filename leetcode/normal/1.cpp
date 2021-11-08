#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> countM;
        using pii=pair<int, int>;

        for (int i : nums){
            auto iter = countM.find(i);
            if ( iter == countM.end()){
                countM.insert(pii(i, 1));
            }else {
                iter->second++;
            }
        }
        vector<int> chooseInt;
        for (int i : nums){
            auto iter = countM.find(target-i);
            if (i==target-i){
                if (iter->second >= 2){
                    chooseInt.push_back(i);
                    chooseInt.push_back(i);
                    break;
                }
            }
            else if (iter != countM.end()){
                chooseInt.push_back(i);
                chooseInt.push_back(target-i);
                break;
            }
        }
        int used = -1;
        vector<int> results;

        for (int i: chooseInt){
            for (int j=0; j!=nums.size(); j++){
                if (nums[j] == i && j != used){
                    results.push_back(j);
                    used = j;
                    break;
                }
            }
        }
        return results;
    }
};

int main(){
    Solution s =  Solution();
    vector<int> i = {3, 2, 4};
    vector<int> r = s.twoSum(i, 6);
    return 1;
}