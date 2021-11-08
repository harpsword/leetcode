#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        for (int i = 0; i != m; i++){
            if (grid[i][0] < 0) {
                count = count + (m - i) * n;
                break;
            }
            for (int j = 0; j!=n; j++){
                if (grid[i][j] < 0){
                    count = count + n - j;
                    break;
                }
            }
        }
        return count;
    }
};

int main(){
    Solution s = Solution();
    vector<vector<int>> input = {{4, 3, 2, -1}, {3, 2, 1, -1}, {1, 1, -1, -2}, {-1, -1, -2, -3}};
    cout << s.countNegatives(input);
    return 1;
}