#include <iostream>
#include <vector>
#include <set>

using namespace std;


class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<int>> dp(m, vector<int>(n,0));
        if (N==0) return 0;
        vector<vector<int>> tmp;
        dp[i][j] = 1;
        vector<int> movex = {1, 0, -1, 0};
        vector<int> movey = {0, 1, 0, -1};
        int count{0};
        int big = 1e9+7;
        for (int k=0; k!=N; ++k){
            tmp = dp;
            for (int x=0; x!=m; ++x)
                for (int y=0; y!=n; ++y){
                    if (tmp[x][y]>0){
                        dp[x][y]-=tmp[x][y];
                        for (int l = 0; l!=4; ++l){
                            int tmpx = x + movex[l];
                            int tmpy = y + movey[l];
                            if (tmpx < 0|| tmpx>=m || tmpy<0 || tmpy>=n){
                                count+=tmp[x][y];
                                count%=big;
                            }else{
                                dp[tmpx][tmpy]+=tmp[x][y];
                                dp[tmpx][tmpy]%=big;
                            }
                        }
                    }
                }
        }
        return count;
    }
};

int main(){
    Solution s = Solution();
    int rr = s.findPaths(2, 2, 2, 0, 0);
    return 0;
}