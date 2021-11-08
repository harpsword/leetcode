#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<deque>
#include<map>

using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        map<int, vector<int>> stats;
        for (auto s : reservedSeats){
            if (stats.find(s[0])==stats.end()) stats[s[0]] = vector<int>{s[1]};
            else stats[s[0]].push_back(s[1]);
        }

        int count = 0;
        int output = 0;
        set<int> test;
        vector<set<int>> testI{
            {2, 3, 4, 5},
            {4, 5, 6, 7},
            {6, 7, 8, 9}
        };
        for (auto p: stats){
            count++;
            test.clear();
            for (int i:p.second) test.insert(i);
            
            for (int i = 0; i < 3; i++){
                bool pd = true;
                for (int j: testI[i]){
                    if (test.find(j)!=test.end()) {
                        pd = false;break;
                    }
                }
                if (pd){
                    for (int j:testI[i]) test.insert(j);
                    output++;
                }
            }

        }
        return output + (n - count) * 2;
    }
};