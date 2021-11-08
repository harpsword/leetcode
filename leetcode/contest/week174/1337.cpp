#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<deque>
#include<map>

using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        if (m==0) return {};
        int n = mat[0].size();
        vector<int> output(m, 0);
        for (int i = 0; i != m; i++)
            for (int j = 0; j != n; j++){
                if (mat[i][j]==1) output[i]++;
                else break;
            }

        vector<int> index;
        for (int i = 0; i!= m; i++) index.push_back(i);
        sort(index.begin(), index.end(), [&](size_t a, size_t b){
            if (output[a] < output[b] || (output[a]==output[b] && a < b)) return true;
            else return false;
        });

        return vector<int>(index.begin(), index.begin()+k);
    }
};