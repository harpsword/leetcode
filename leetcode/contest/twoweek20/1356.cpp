#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<deque>
#include<map>

using namespace std;


class Solution {
    map<int, int> count;
public:

    int calcul(int a){
        int original_a = a;
        if (count.find(a) != count.end()) return count[a];
        else {
            int t = 0;
            int tmp = 0;
            while (a > 0)
            {
                tmp = a % 2;
                if (tmp == 1) t++;
                a = a / 2;
                if (count.find(a) != count.end()){
                    t = t + count[a];
                    count[original_a] = t;
                    return t;
                }
            }
            count[original_a] = t;
            return t;
        }
        return 0;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&] (const int &a, const int &b) -> bool {
            int a_c = calcul(a);
            int b_c = calcul(b);
            // cout << a << " " << a_c << " ; " << b << " " << b_c << endl;
            if (a_c < b_c || (a_c == b_c && a < b)) return true;
            else return false;
        });
        return arr;
    }
};

int main(){
    vector<int> input = {0,1,2,3,4,5,6,7,8};
    Solution s = Solution();
    input = s.sortByBits(input);
    for (int i: input)
        cout << i << " ";
    return 1;
}