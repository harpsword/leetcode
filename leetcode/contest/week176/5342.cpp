#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int s = events.size();
        if (s == 0) return 0;
        sort(events, 0, s-1);

        // for (auto i: events){
        //     cout << i[0] << " " << i[1] << endl;
        // }
        int current_day = 1;
        int count = 0;
        for (int i=0; i!=s; i++){
            if (i==0) {
                current_day = events[0][0];
                count = 1;
            }else {
                if (events[i-1][0]==events[i][0] && current_day < events[i][1]) {
                    current_day++;
                    count++;
                }else if (events[i-1][0] > events[i][0] && current_day < events[i][1]) {
                    current_day++;
                    count++;
                }else if (events[i-1][0] < events[i][0] && current_day < events[i][1]){
                    current_day = max(current_day+1, events[i][0]);
                    count++;
                }
            }
        }
        return count;
    }

    void sort(vector<vector<int>>& a, int s, int e){
        int mids = a[(s+e)/2][0];
        int mide = a[(s+e)/2][1];
        int i = s;
        int j = e;

        vector<int> tmp;
        while (i < j){
            while (judge(a[i][0], a[i][1], mids, mide)) i++;
            while (judge(mids, mide, a[j][0], a[j][1])) j--;
            if (i <= j){
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
                i++; 
                j--;
            }
        }
        if (i < e) sort(a, i, e);
        if (j > s) sort(a, s, j);
    }

    bool judge(int a1, int a2, int b1, int b2){
        // true means [a1, a2] first, [b1, b2] next
        if (a1 < b1) {
            if (a2 <= b2) return true;
            else return false;
        }
        else if (a1 > b1) {
            if (a2 < b2) return true;
            else if (a2 > b2) return false;
            else return false;
        }
        else if (a1 == b1) return a2 < b2;
        return false;
    }
};


int main(){
    Solution s = Solution();
    // [[1,5],[1,5],[1,5],[2,3],[2,3]]
    vector<vector<int>> input = {{1,5}, {1, 5}, {1, 5}, {2, 3}, {2, 3}};
    cout << s.maxEvents(input);
    return 1;
}