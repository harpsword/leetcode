#include<iostream>
#include<vector>

using namespace std;
// Easy

class NumMatrix {
    vector<vector<int>> sum_v;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n!=0){
            int m = matrix[0].size();
            if (m==0){
                vector<int> tmp;
                sum_v.push_back(tmp);
            }else{
                for (int i=0; i!=n; ++i)
                {
                    vector<int> tmp_s;
                    for (int j=0; j!=m; ++j){
                        if (i==0){
                            if (j==0) tmp_s.push_back(matrix[i][j]);
                            else tmp_s.push_back(matrix[i][j]+tmp_s[j-1]);
                        }else {
                            if (j==0) tmp_s.push_back(matrix[i][j]+sum_v[i-1][j]);
                            else tmp_s.push_back(matrix[i][j]+tmp_s[j-1]+sum_v[i-1][j]-sum_v[i-1][j-1]);
                        }
                    }
                    sum_v.push_back(tmp_s);
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 == 0 && col1==0){
            return sum_v[row2][col2];
        }else if (row1==0){
            return sum_v[row2][col2]-sum_v[row2][col1-1];
        }else if (col1==0){
            return sum_v[row2][col2]-sum_v[row1-1][col2];
        }else {
            return sum_v[row2][col2]-sum_v[row2][col1-1]-sum_v[row1-1][col2]+sum_v[row1-1][col1-1];
        }
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */