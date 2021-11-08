#include<iostream>
#include<vector>
#include<set>
// 找有几个岛屿
// 将每个空格看做一个节点，每个节点最多有四个连接，问题转化为寻找有多少个连通分量
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int l = grid.size();
        if (l==0) return 0;
        int r = grid[0].size();
        int node_n = l * r;
        if (node_n==0) return 0;

        set<int> visited;
        int count{0};

        for (int i=0; i<l; i++){
            for (int j=0; j<r; j++){
                int node_id = i * r + j;
                if (grid[i][j] == '0')
                    visited.insert(node_id);
            }
        }
        
        while (visited.size()<node_n)
        {
            int rooti{0}, rootj{0};
            bool find{false};
            for (int i=0; i<l; i++){
                for (int j=0; j<r; j++){
                    int node_id = i * r + j;
                    if (visited.find(node_id)==visited.end()){
                        visited.insert(node_id);
                        rooti = i;
                        rootj = j;
                        find = true;
                        break;
                    }
                }
                if (find) break;
            }
            dfs(grid, visited, rooti, rootj, l, r);

            count++;
        }
        return count;   
    }

    void dfs(vector<vector<char>>& grid, set<int>& visited, int i, int j, int l, int r){
        vector<int> x = {-1, 1, 0, 0};
        vector<int> y = {0, 0, -1, 1};
        int tmpi, tmpj;
        int new_node_id;
        for (int ii=0; ii < 4; ii++){
            tmpi = i + x[ii];
            tmpj = j + y[ii];
            new_node_id = tmpi * r + tmpj;
            if (tmpi>=0 && tmpi < l && tmpj >= 0 && tmpj<r){
                if (grid[tmpi][tmpj]=='1' && visited.find(new_node_id) == visited.end()){
                    visited.insert(new_node_id);
                    dfs(grid, visited, tmpi, tmpj, l, r);
                }
            }

        }
    }

};


int main(){
    vector<vector<int>> m(4, vector<int>(5, 0));
    m[0][0] = 1;
    m[0][1] = 1;
    m[1][0] = 1;
    m[1][1] = 1;

    m[2][3] = 1;
    m[2][4] = 1;
    m[3][3] = 1;
    m[3][4] = 1;
    Solution s = Solution();
    cout << s.maxAreaOfIsland(m);
}