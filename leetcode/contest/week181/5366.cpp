#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<deque>
#include<map>
#include <cmath>

using namespace std;


class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (m==1 && n==1) return true;

        int i = 0;
        int j = 0;
        bool isOK = true;
        vector<vector<int>> directions{
            {0, 0}, // 填充0这个位置
            {2, 3},
            {0, 1},
            {2, 1},
            {3, 1},
            {0, 2},
            {0, 3},
        };
        
        vector<vector<int>> steps{
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1},
        };

        for (int start_d:directions[grid[0][0]]){
            int current_direction = start_d;
            i = steps[current_direction][0];
            j = steps[current_direction][1];
            if (i < 0 || i >= m || j < 0 || j >= n) continue;

            bool testOK = false;
            while (true)
            {
                vector<int> d_set = directions[grid[i][j]];
                testOK = false;
                for (int k=0; k!=2; k++)
                    if (opposite(d_set[k])==current_direction){
                        testOK = true;
                        current_direction = d_set[1-k];
                        break;
                    }
                if (!testOK) break;
                if (i == m-1 && j == n-1) return true;

                i += steps[current_direction][0];
                j += steps[current_direction][1];
                if (i < 0 || i >= m || j < 0 || j >= n) {
                    testOK = false;
                    break;
                }
            }
        }
        
        return false;
    }

    int opposite(int d){
        if (d == 0 || d == 1) return 1 - d;
        else if (d == 2) return 3;
        else return 2;
    };

};


int main(){

    Solution s = Solution();
    vector<vector<int>> input = {{1, 2, 1}, {1, 2, 1}};
    // 
    cout << s.hasValidPath(input);
    return 1;
}