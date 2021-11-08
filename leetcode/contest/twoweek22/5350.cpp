
#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<deque>
#include<map>

using namespace std;


class Solution {
    map<int, int> store;
public:
    int getKth(int lo, int hi, int k) {
        vector<int> index;
        map<int, int> value;
        for (int i = lo; i <= hi; i++){
            index.push_back(i);
            value[i] = calVal(i);
        }
        sort(index.begin(), index.end(), [&](int i, int j)-> bool{
            if (value[i] < value[j] || (value[i]==value[j] && i < j)) return true;
            else return false;
            // if (index[i][1]<index[j][1] || (index[i][1]==index[j][1] && index[i][0]<index[j][0])) return true;
            // else return false;
        });
        return index[k-1];
    }

    int calVal(int v){
        int tmp;
        if (store.find(v)!=store.end()) return store[v];
        else if (v == 1) return 0;
        else {
            if (v % 2 == 0) tmp = calVal(v/2) + 1;
            else tmp = calVal(3 * v + 1) + 1;
            store[v] = tmp;
            return tmp;
        }
    }
};

int main(){
    Solution s = Solution();
    cout << s.getKth(1, 1000, 777);
    return 1;
}