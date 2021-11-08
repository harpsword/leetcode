#include <iostream>
#include <vector>
#include <set>
#include<algorithm>

using namespace std;
// Idea有问题
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp1(n+1, vector<int>(n+1, 0));
        vector<vector<int>> dp2(n+1, vector<int>(n+1, 0));
        vector<vector<bool>> valid(n+1, vector<bool>(n+1, false));
        valid[0][0] = true;
        if (grid[0][0]) dp1[0][0] = 1;
        vector<int> move1i = {-1, 0};
        vector<int> move1j = {0, -1};
        for (int i=0; i!=n; ++i){
            for (int j=0; j!=n; ++j){
                if (i==0 && j==0) continue;
                for (int k=0; k!=2; ++k){
                    int tmpi = i + move1i[k];
                    int tmpj = j + move1j[k];
                    if (tmpi < 0 || tmpi >= n || tmpj < 0 || tmpj >=n) continue;
                    dp1[i][j] = max(dp1[tmpi][tmpj], dp1[i][j]);
                    valid[i][j] = valid[i][j] || dp1[tmpi][tmpj];
                }
                if (grid[i][j]==1) dp1[i][j]++;
                else if (grid[i][j]==-1){
                    dp1[i][j] = 0;
                    valid[i][j] = false;
                }
            }
        }

        vector<int> move2i = {1, 0};
        vector<int> move2j = {0, 1};
        for (int i=n-1; i>=0; --i){
            for (int j=n-1; j>=0; --j){
                if (i==n-1 && j==n-1) continue;
                for (int k=0; k!=2; ++k){
                    int tmpi = i + move2i[k];
                    int tmpj = j + move2j[k];
                    if (tmpi < 0 || tmpi >= n || tmpj < 0 || tmpj >=n) continue;
                    dp2[i][j] = max(dp2[tmpi][tmpj], dp2[i][j]);
                }
                if (grid[i][j]==1) dp2[i][j]++;
                else if (grid[i][j]==-1){
                    dp2[i][j] = 0;
                }
            }
        }
        int result{0};
        int tmp_v{0};
        for (int i=0; i!=n-1; ++i)
            for (int j=0; j!=n-1; ++j){
                tmp_v = dp1[i][j] + dp2[i][j];
                if (grid[i][j]==1) tmp_v--;
                result = max(result, tmp_v);
            }
        return result;
    }
};