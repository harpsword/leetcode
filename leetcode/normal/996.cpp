#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<unordered_set>
#include<algorithm>
#include<math.h>
// 动态规划
// Not Finished
using namespace std;

// 和的开方结果为整数 表示两个加数之间存在连接，最后结果为哈密尔顿路径数量
// 注意：1, 2, 3与3,2,1为两条路径
// https://leetcode.com/problems/number-of-squareful-arrays/

class Solution {
public:
    int numSquarefulPerms(vector<int>& A) {
        sort(begin(A), end(A)); 
        int n = A.size();
        vector<vector<int>> distance(n, vector<int>(n, 0));
        for (int i=0; i!=n; ++i){
            for (int j=0; j!=n; ++j){
                if (i==j) continue;
                int tmp = A[i] + A[j];
                int r = sqrt(tmp);
                if (r*r==tmp) distance[i][j] = 1;
            }
        }
        vector<vector<int>> dp(1 << n, vector<int>(n, 0));
        // For the same numbers, only the first one can be the starting point.
        for (int i = 0; i < n; ++i)
            if (i == 0 || A[i] != A[i - 1])
                dp[(1 << i)][i] = 1;
        int ans = 0;
        for (int s = 0; s < (1 << n); ++s)
            for (int i = 0; i < n; ++i) {
                if (!dp[s][i]) continue;
                for (int j = 0; j < n; ++j) {
                    if (!distance[i][j]) continue;
                    // j至今未被访问
                    if (s & (1 << j)) continue;
                    // Only the first one can be used as the dest.
                    // 前一个节点(相同大小)被访问了
                    if (j > 0 && !(s & (1 << (j - 1))) && A[j - 1] == A[j]) continue;
                    dp[s | (1 << j)][j] += dp[s][i];
                }
            }
        for (int i=0; i<n; ++i){
            ans += dp[(1<<n)-1][i];
        }
        return ans;
    }
};