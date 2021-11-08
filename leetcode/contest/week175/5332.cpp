
#include <iostream>
#include <vector>
#include <set>

using namespace std;


class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<int> have;
        for (int i: arr){
            have.insert(i);
        }
        int zero_count = 0;
        for (int i: arr){
            if (i==0) {
                zero_count ++;
                continue;
            }
            if (have.find(i * 2)!=have.end()){
                return true;
            }
            if (i % 2 == 0){
                if (have.find(i / 2)!= have.end()) return true;
            }
        }
        if (zero_count >= 2) return true;
        return false;
    }
};


int main(){
    Solution s = Solution();
    vector<int> input = {10, 2, 5, 3};
    cout << s.checkIfExist(input) << endl;
    return 0;
}