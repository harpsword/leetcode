#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<unordered_set>

using namespace std;

// 并查集

class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        vector<int> father(n, -1);
        for (int i=0; i!=n; ++i){
            for (int j=0; j!=n; ++j){
                if (i==j) continue;
                if (graph[i][j]){
                    unionSet(father,i,j);
                }
            }
        }
        vector<int> count(n, 0);
        int m = initial.size();
        vector<int> record, record_set_size;
        for (int i: initial){
            int fi = find(father, i);
            record.push_back(fi);
            record_set_size.push_back(-father[fi]);
            count[fi]++;
        }
        int best_value=-1;
        vector<int> delete_node;
        for (int i=0; i!=m; ++i){
            int fi = record[i];
            int tmp_v = record_set_size[i];
            if (count[fi]>1) tmp_v = 0;
            if (tmp_v > best_value){
                delete_node.clear();
                delete_node.push_back(initial[i]);
                best_value = tmp_v;
            } else if (tmp_v==best_value) delete_node.push_back(initial[i]);
        }
        int min_node = n;
        for (int i:delete_node)
            if (i<min_node){
                min_node = i;
            }
        return min_node;
    }

    void unionSet(vector<int>& father, int i, int j){
        int fi = find(father, i);
        int fj = find(father, j);
        if (fi == fj) return ;
        if (father[fi] > father[fj]){
            swap(fi, fj);
        }
        // i属于的集合大于j属于的集合
        father[fi] += father[fj];
        father[fj] = fi;
    }

    int find(vector<int>& father, int i){
        if (father[i]<0) return i;
        father[i] = find(father, father[i]);
        return father[i];
    }
};

int main(){
    Solution s = Solution();
    vector<vector<int>> g = {{1,0,0,0},{0,1,0,0},{0,0,1,1},{0,0,1,1}};
    vector<int> initial = {3, 1};
    return s.minMalwareSpread(g, initial);
}