#include<iostream>
#include<set>
#include<vector>
// 遍历每一个0，尝试将该0改为1，计算最大岛屿面积，完成遍历后返回最大值。
// 该方法原理上可行，但是超时
using namespace std;

class Solution {
public:

    int largestIsland(vector<vector<int>>& grid) {
        vector<int> x = {-1, 1, 0, 0};
        vector<int> y = {0, 0, -1, 1};
        int l = grid.size();
        int r = grid[0].size();
        int result{0};
        bool nozero{true};
        bool non_zero_need_change{true};
        for (int i=0; i<l; i++){
            for (int j=0; j<r; j++){
                int doit = 0;
                for (int k=0; k!=4; k++){
                    int tmpi = i + x[k];
                    int tmpj = j + y[k];
                    if (tmpi >= 0 && tmpi < l && tmpj >= 0 && tmpj < r && grid[tmpi][tmpj]==1){
                        doit ++;
                    }
                }
                if (grid[i][j]==0) nozero = false;
                if (grid[i][j] ==0 && doit>=2){
                    grid[i][j] = 1;
                    int m = maxIsland(grid, l, r);
                    if (m>result) result = m;
                    grid[i][j] = 0;
                    non_zero_need_change = false;
                }
            }
        }
        if (nozero) return l * r;
        if (non_zero_need_change) return maxIsland(grid, l, r) + 1;
        return result;
    }

    int maxIsland(vector<vector<int>>& grid, int l, int r){
        set<int> visited;
        int max_value{0};
        for (int i=0;i<l; i++){
            for (int j=0;j<r; j++){
                int t = dfs(grid, i, j, l, r, visited);
                if (t>max_value) max_value =t;
            }
        }
        return max_value;
    }

    int dfs(vector<vector<int>>& grid, int i, int j, int l, int r, set<int>& visited){
        if (i<0 || i>=l || j<0 || j>=r) return 0;
        if (visited.find(i*r+j)!=visited.end()) return 0;
        visited.insert(i*r+j);
        if (grid[i][j]==0) return 0;
        return 1+dfs(grid, i-1, j, l, r, visited) + dfs(grid, i+1, j, l, r, visited) + 
                    dfs(grid, i, j-1, l, r, visited) + dfs(grid, i, j+1, l, r, visited);
    }
};


int main(){
    vector<vector<int>> m(2, vector<int>(2, 0));
    m = {{1,1},{0,1}};
    Solution s = Solution();
    cout << s.largestIsland(m);
}