#include <iostream>
#include <vector>
#include<string>
#include <set>
using namespace std;
// Idea 错误
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        if (m==0) return 0;
        int n = dungeon[0].size();
        if (n==0) return 0;
        vector<vector<int>> minHealth(m+1, vector<int>(n+1, 0));
        vector<vector<int>> currentHealth(m+1, vector<int>(n+1, 0));

        for (int i=0; i!=m; ++i)
            for (int j=0; j!=n; ++j){
                if (i==0 && j==0) {
                    minHealth[0][0] = dungeon[0][0];
                    currentHealth[0][0] = dungeon[0][0];
                }else if (i==0){
                    currentHealth[i][j] = currentHealth[i][j-1] + dungeon[i][j];
                    minHealth[i][j] = min(minHealth[i][j-1], currentHealth[i][j]);
                }else if (j==0){
                    currentHealth[i][j] = currentHealth[i-1][j] + dungeon[i][j];
                    minHealth[i][j] = min(minHealth[i-1][j], currentHealth[i][j]);
                }else {
                    int curr1 = currentHealth[i][j-1]+dungeon[i][j];
                    int min1 = min(minHealth[i][j-1], curr1);
                    int curr2 = currentHealth[i-1][j]+dungeon[i][j];
                    int min2 = min(minHealth[i-1][j], curr2);
                    if (min1 > min2 || ((min1==min2)&&(curr1>curr2))){
                        // [i][j-1] -> [i][j]
                        currentHealth[i][j] = curr1;
                        minHealth[i][j] = min1;
                    }else {
                        currentHealth[i][j] = curr2;
                        minHealth[i][j] = min2;
                    }
                }
            }
        if (minHealth[m-1][n-1]>0) return 1;
        else return -minHealth[m-1][n-1] + 1;
    }
};

int main(){
    Solution s = Solution();
    vector<vector<int>> ii = {{1, -3, -3}, {0, -2, 0}, {-3, -3, -3}};
    int jj = s.calculateMinimumHP(ii);
    return 0;
}