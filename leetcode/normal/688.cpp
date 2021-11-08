#include <iostream>
#include <vector>
#include <set>

using namespace std;

// 简单模拟既可
class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<double>> prob(N, vector<double>(N, 0));
        prob[r][c] = 1;
        vector<int> movex = {1, 2, 2, 1, -1, -1, -2, -2};
        vector<int> movey = {-2, -1, 1, 2, -2, 2, 1, -1};
        vector<vector<double>> tmp;
        for (int k = 0; k!=K; ++k){
            tmp = prob;
            for (int i=0; i!=N; ++i)
                for (int j=0; j!=N;++j){
                    if (tmp[i][j]>0){
                        prob[i][j]-=tmp[i][j];
                        for (int l=0; l!=8; ++l){
                            int tmpx = i + movex[l];
                            int tmpy = j + movey[l];
                            if (tmpx<0 || tmpx>=N || tmpy<0 || tmpy>=N) continue;
                            prob[tmpx][tmpy] += 1.0/8.0*tmp[i][j];
                        }
                    }
                }
        }
        double p{0};
        for (int i=0; i!=N; ++i)
            for (int j=0; j!=N; ++j)
                p+=prob[i][j];
        return p;
    }
};
