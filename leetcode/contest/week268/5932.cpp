#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<deque>
#include<map>

using namespace std;


class RangeFreqQuery {
    vector<vector<int>> value_count;
public:
    RangeFreqQuery(vector<int>& arr) {
        value_count = vector<vector<int>>(10000, vector<int>{});
        for (int i = 0; i != arr.size(); i++) {
            int v = arr[i] - 1;
            value_count[v].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
       const vector<int> &arr = value_count[value - 1];
        auto l = lower_bound(arr.begin(), arr.end(), left);
        auto r = upper_bound(arr.begin(), arr.end(), right);
        return r - l;
    }
};


/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */