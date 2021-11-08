#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<unordered_set>
#include<algorithm>
// 动态规划
using namespace std;

class Solution {
public:
    string shortestSuperstring(vector<string>& A) {
        int n = A.size();
        vector<vector<int>> distance(n, vector<int>(n, 0));
        for (int i=0; i!=n; ++i){
            for (int j=0;j!=n;++j){
                distance[i][j] = 0;
                if (i==j) continue;
                string a = A[i];
                string b = A[j];
                for (int k=min(a.size(), b.size()); k>=0; k--){
                    // cout << a.substr(a.size()-k) << " " << b.substr(0, k) << endl;
                    if (k==0) {
                        distance[i][j] = b.size();
                        break;
                    }
                    if (a.substr(a.size()-k) == b.substr(0, k)){
                        distance[i][j] = b.size() - k;
                        break;
                    }
                }
            }
        }
        int number_state = (1 << n);
        constexpr int InfDis = 1e9;
        vector<vector<int>> dp(number_state, vector<int>(n, InfDis)), parent(number_state, vector<int>(n, -1));
        for (int i=0; i!=n; ++i) dp[1<<i][i] = A[i].length();

        for (int s = 1; s<(1<<n); ++s){
            for (int j=0; j<n; ++j){
                // 未访问过j则跳过
                if (!(s & (1<<j))) continue;
                int ps = s & ~(1<<j); 
                for (int i=0; i<n; ++i){
                    if (dp[ps][i]+distance[i][j] < dp[s][j]){
                         // 更新 dp[s][j] = min(dp[s-2^j][i]+distance[i][j])
                        dp[s][j] = dp[ps][i] + distance[i][j];
                        parent[s][j] = i;
                    }
                }
            }
        }
        auto it = min_element(begin(dp.back()), end(dp.back()));
        int j = it - begin(dp.back());
        int s = (1 << n) - 1;
        string ans;
        while (s) {
            int i = parent[s][j];
            if (i < 0) ans = A[j] + ans;
            else ans = A[j].substr(A[j].length() - distance[i][j]) + ans;
            s &= ~(1 << j);
            j = i;
        }
        return ans;
    }
    
}; 

int main(){
    vector<string> sss = {"catg","ctaagt","gcta","ttca","atgcatc"};
    Solution s = Solution();
    string ttt =  s.shortestSuperstring(sss);
}