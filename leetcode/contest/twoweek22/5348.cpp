
#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<deque>
#include<map>

using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        set<int> have;
        int count=0;
        for (int i:arr2){
            for (int j = -d; j <= d; j++)
                if (have.find(i+j)==have.end()) have.insert(i+j);
        }

        for (int i:arr1){
            if (have.find(i)==have.end()) count++;
        }
        return count;
    }
};

int main(){
    Solution s = Solution();
    vector<int> a{4, 5, 8}, b{10, 9, 1, 8};
    cout << s.findTheDistanceValue(a, b, 2);
    return 1;
}