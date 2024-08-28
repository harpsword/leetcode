#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<deque>
#include<map>
#include<algorithm>

using namespace std;


// 并查集模板
class UnionFind {
public:
    vector<int> parent;
    vector<int> size;
    int n;
    // 当前连通分量数目
    int setCount;

public:
    UnionFind(int _n): n(_n), setCount(_n), parent(_n), size(_n, 1) {
        // iota(parent.begin(), parent.end(), 0);
    }

    int findset(int x) {
        return parent[x] == x ? x : parent[x] = findset(parent[x]);
    }

    bool unite(int x, int y) {
        x = findset(x);
        y = findset(y);
        if (x == y) {
            return false;
        }
        if (size[x] < size[y]) {
            swap(x, y);
        }
        parent[y] = x;
        size[x] += size[y];
        --setCount;
        return true;
    }

    bool connected(int x, int y) {
        x = findset(x);
        y = findset(y);
        return x == y;
    }
    void isolate(int x) {
        if(x != parent[x]){
            parent[x] = x;
            size[x] = 1;
            ++setCount;
        }
    }
};

bool cmp(const vector<int>& a, const vector<int>& b){
    return a[2]<b[2];
}

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& ms, int fp) {
        sort(ms.begin(), ms.end(), cmp);
        int m = ms.size();
        UnionFind uf(n);
        uf.unite(fp, 0);
        for(int i=0; i<m; i++){
            int j = i+1;
            while(j < m) {
                if(ms[i][2] != ms[j][2]){
                    break;
                }
            }
            for(int k=i;k<j;k++){
                uf.unite(ms[k][0], ms[k][1]);
            }
            for(int k=i;k<j;k++){
                if(!uf.connected(ms[k][0], 0)){
                    uf.isolate(ms[k][0]);
                    uf.isolate(ms[k][1]);
                }
            }
            i=j-1;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(uf.connected(i, 0)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};