#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<deque>
#include<map>

using namespace std;


class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int, int> count;
        for (int i: arr){
            if (count.find(i)==count.end()) count[i] = 1;
            else count[i]++;
        }
        int n = arr.size();
        int output = 0;
        int deleted = 0;

        vector<int> count_v(count.size(), 0);
        int index = 0;
        for (auto i = count.begin(); i!=count.end(); i++){
            count_v[index++] = i->second;
        }
        sort(count_v.begin(), count_v.end(), [](int &a, int &b){
            return a > b ? true:false;
        });

        for (auto i = count_v.begin(); i!=count_v.end(); i++){
            output++;
            deleted += *i;
            if (deleted * 2>=n) break;
        }
        return output;
    }
};

int main(){
    Solution s = Solution();
    vector<int> input{9,77,63,22,92,9,14,54,8,38,18,19,38,68,58,19};
    int r = s.minSetSize(input);
    cout << r;
    return 1;
}