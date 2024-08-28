#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<deque>
#include<map>
#include<algorithm>

using namespace std;


class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b) {
        return a[2] < b[2];
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(), cmp);
        vector<int> father(n+1, 0);
        for (int i =0;  i != n; i++) {
            father[i] = i;
        }
        father[0] = 0;
        father[firstPerson] = 0;
        int i = 0;
        while (i < meetings.size()) {
            int j = i;
            int current_time = meetings[j][2];
            int record_j = j;
            while (j < meetings.size() && meetings[j][2] == current_time)
            {
                int a = meetings[j][0];
                int b = meetings[j][1];
                if (father[find(father, a)] == 0 || father[find(father, b)] == 0) {
                    father[find(father, a)] = 0;
                    father[find(father, b)] = 0;
                }
                father[find(father, a)] = father[find(father, b)];
                // union2(father, meetings[j][0], meetings[j][1]);
                j++;
                i++;
            }
            j = record_j;
            int father_0 = find(father, 0);
            while (j < meetings.size() && meetings[j][2] == current_time) {
                int a = meetings[j][0];
                int b = meetings[j][1];
                if (father[find(father, a)] == 0 || father[find(father, b)] == 0) {
                    father[find(father, a)] = 0;
                    father[find(father, b)] = 0;
                } else {
                    father[a] = a;
                    father[b] = b;
                }


                // int l = meetings[j][0];
                // int father_l = find(father, l);
                // if (father_l != father_0) {
                //     isolate(father, meetings[j][0]);
                //     isolate(father, meetings[j][1]);
                // }
                j++;
            }
        }
        vector<int> result;
        int father_0 = find(father, 0);
        for (int i = 0; i!= n; i++) {
            if (find(father, i) == father_0) {
                result.push_back(i);
            }
        }
        return result;
    }

    void isolate(vector<int>& father, int i) {
        if (i != father[i]) {
            father[i] = i;
        }
    }

    void union2(vector<int>& father, int i, int j) {
        int father_i = find(father, i);
        int father_j = find(father, j);
        father[father_j] = father_i;
    }

    int find(vector<int>& father, int i) {
        if (father[i] == i) {
            return i;
        }
        father[i]=  find(father, father[i]);
        return father[i];
    }
};



int main() {
    vector<vector<int>> input{
        // {1, 2, 5},
        // {2, 3, 8},
        // {1, 5, 10},
      {3, 1, 3},
      {1, 2, 2},
      {0, 3, 3}, 
    };
    Solution s = Solution{};
    vector<int> r = s.findAllPeople(4, input, 33);
    return 1;
}
