#include<iostream>
#include<set>
#include<vector>
// 先对地图内的所有岛屿进行访问编号，可以得到
// IslandSizeRecord, 岛屿编号与岛屿大小对应的表
// record,每个坐标与其岛屿编号的表
// 遍历每一个0，可以通过其邻居内的岛屿编号来计算该0变1后的新岛屿大小。
// 时间复杂度 N^2
using namespace std;

class Solution {
public:

    int largestIsland(vector<vector<int>>& grid) {
        
        int l = grid.size();
        int r = grid[0].size();
        vector<vector<int>> record(l, vector<int>(r, 0));
        vector<int> IslandSizeRecord;
        IslandSizeRecord.push_back(0);
        set<int> visited;
        int node_class_index = 1;
        int tmpi, tmpj;
        for (int i=0;i!=l;i++){
            for (int j=0; j!=l;j++){
                if (visited.find(i*r+j)==visited.end() && grid[i][j]==1){
                    set<int> tmp_visited;
                    tmp_visited.insert(i*r+j);
                    dfs(i, j, grid, tmp_visited, l, r);
                    for (int k:tmp_visited){
                        tmpj = k % r;
                        tmpi = (k - tmpj) / r;
                        record[tmpi][tmpj] = node_class_index;
                        visited.insert(k);
                    }
                    IslandSizeRecord.push_back(tmp_visited.size());
                    node_class_index++;
                }
            }
        }
        vector<int> x = {-1, 1, 0, 0};
        vector<int> y = {0, 0, -1, 1};
        int return_i = 0;
        for (int i=0; i!=l; i++){
            for (int j=0; j!=r; j++){
                if (grid[i][j]==1) continue;
                set<int> tmp_class_index;
                int tmp{1};
                for (int k=0; k!=4; k++){
                    int tmpi = i + x[k];
                    int tmpj = j + y[k];
                    if (tmpi >= 0 && tmpi < l && tmpj >= 0 && tmpj < r && grid[tmpi][tmpj]==1){
                        tmp_class_index.insert(record[tmpi][tmpj]);
                    }
                }
                for (auto k:tmp_class_index){
                    tmp+=IslandSizeRecord[k];
                }
                if (tmp>return_i) return_i = tmp;
            }
        }
        for (auto size : IslandSizeRecord){
            if (size>return_i) return_i = size;
        }
        return return_i;
    }

    void dfs(int i, int j, vector<vector<int>>& image, set<int>& visited, int l, int r){
        vector<int> x = {-1, 1, 0, 0};
        vector<int> y = {0, 0, -1, 1};
        int tmpi, tmpj;
        int new_node_id;
        for (int ii=0; ii < 4; ii++){
            tmpi = i + x[ii];
            tmpj = j + y[ii];
            new_node_id = tmpi * r + tmpj;
            if (tmpi>=0 && tmpi < l && tmpj >= 0 && tmpj<r){
                if (image[i][j] == 1 && image[tmpi][tmpj]==1 && visited.find(new_node_id)==visited.end()){
                    visited.insert(new_node_id);
                    dfs(tmpi, tmpj, image, visited, l, r);
                }
            }
        }
    }
};


int main(){
    vector<vector<int>> m(2, vector<int>(2, 0));
    m = {{1,1},{0,1}};
    Solution s = Solution();
    cout << s.largestIsland(m);
}