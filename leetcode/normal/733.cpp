#include<iostream>
#include<set>
#include<vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int l = image.size();
        int r = image[0].size();

        set<int> visited;

        int start_id = sr * r + sc;
        visited.insert(start_id);
        dfs(sr, sc, image, visited, l, r);
        int tmpi, tmpj;
        for (auto i=visited.begin();i!=visited.end();i++){
            tmpj = (*i) % r;
            tmpi = ((*i) - tmpj) / r;
            image[tmpi][tmpj] = newColor;
        }
        return image;
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
                if (image[i][j] == image[tmpi][tmpj] && visited.find(new_node_id)==visited.end()){
                    visited.insert(new_node_id);
                    dfs(tmpi, tmpj, image, visited, l, r);
                }
            }
        }
    }
};


int main(){
    vector<vector<int>> m(3, vector<int>(3, 0));
    m[0][0] = 1;
    m[0][1] = 1;
    m[0][2] = 1;
    m[1][0] = 1;
    m[1][1] = 1;
    m[2][0] = 1;
    m[2][2] = 1;
    Solution s = Solution();
    vector<vector<int>> r = s.floodFill(m, 1, 1, 2);

    for (auto i: r){
        for (auto j: i){
            cout << j << " ";
        }
        cout << endl;
    }

    return 1;
}