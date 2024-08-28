

#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<deque>
#include<map>

using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int r = 0;
        vector<int> color_first(101, -1);
        for (int i = 0; i != colors.size(); i++) {

            for (int j = 0; j != color_first.size(); j++) {
                int v = color_first[j];
                if (v != -1 && colors[i] != j) {
                    r = max(r, abs(v - i));
                }
            }
            if (color_first[colors[i]] == -1) {
                color_first[colors[i]] = i;
            }
        }
        return r;
    }
};