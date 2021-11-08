#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {

        vector<int> results(num_people, 0);

        int cost_now = 1;
        while (candies > 0)
        {
            for (int i=0; i!=num_people; i++){
                if (candies <= cost_now){
                    results[i] += candies;
                    candies = 0;
                    break;
                }else{
                    results[i] += cost_now;
                    candies -= cost_now;
                    cost_now++;
                }
            }
        }
        return results;
    }
};

int main(){
    Solution s = Solution();

    vector<int> output = s.distributeCandies(100000000, 1000);
    cout << "ok" << endl;
    return 1;
}