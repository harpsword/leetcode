#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<deque>
#include<map>

using namespace std;

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> hangSmallestValue(m, 100000);
        vector<int> liebiggestValue(n, 0);
        for (int i = 0; i != m; i++)
            for (int j = 0; j!=n; j++){
                if (hangSmallestValue[i] > matrix[i][j]) hangSmallestValue[i] = matrix[i][j];
                if (liebiggestValue[j] < matrix[i][j]) liebiggestValue[j] = matrix[i][j];
            }

        vector<int> r;
        for (int i = 0; i!=m; i++)
            for (int j=0; j!=n; j++)
                if (hangSmallestValue[i]==matrix[i][j] && liebiggestValue[j]==matrix[i][j]) r.push_back(matrix[i][j]);
        return r;

    }
};