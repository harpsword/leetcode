#include<iostream>
#include<vector>
// failed
using namespace std;


class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int count{0};
        int l = grid.size();
        int r = grid[0].size();
        vector<vector<int>> grid2(l, vector<int>(r, 0));
        for (int i=0; i!=l; i++)
            for (int j=0; j!=r; j++){
                grid2[l-1-i][r-1-j] = grid[i][j];
            }
        int r1= search(grid);
        int r2 = search(grid2);
        if(r1 > r2)
            return r1;
        else
        {
            return r2;
        }
    }

    int search(vector<vector<int>>& grid) {
        int l = grid.size();
        int r = grid[0].size();
        vector<vector<int>> f(l, vector<int>(r, 0));
        vector<vector<int>> left(l, vector<int>(r, 0)), upper(r, vector<int>(l, 0));
        int count{0};
        for (int i=0; i!=l; i++){
            for (int j=0; j!=r; j++){
                if (grid[i][j]==1){
                    if (i==0 && j==0){
                        // add left
                        f[i][j] = 1;
                        left[i][j] = 1;
                        upper[j][i] = 1;
                    }else if(i==0 && j!=0){
                        left[i][j] = left[i][j-1] + 1;
                        upper[j][i] = 1;
                        f[i][j] = f[i][j-1] + 1;
                    }else if(i!=0 && j==0){
                        left[i][j] = 1;
                        upper[j][i] = upper[j][i-1] + 1;
                        f[i][j] = f[i-1][j] + 1;
                    }else{
                        left[i][j] = left[i][j-1] + 1;
                        upper[j][i] = upper[j][i-1] + 1;
                        if (grid[i-1][j] == 1 || grid[i][j-1]==1){
                            f[i][j] = f[i-1][j-1] + 1 + left[i][j-1] + upper[j][i-1];
                        }else f[i][j] = 1;
                        
                    }
                    if (f[i][j]>count) count = f[i][j];
                }else if (grid[i][j] == 0){
                    left[i][j] = 0;
                    upper[j][i] = 0;
                }
            }
        }
        return count;
    }
};

int main(){
    vector<vector<int>> m(2, vector<int>(2, 0));
    m[0][0] = 1;
    m[0][1] = 1;
    m[1][0] = 1;
    Solution s = Solution();
    cout << s.maxAreaOfIsland(m);
}