#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:

    bool isOK(vector<int>& A, vector<int>& B, int l, int s){
        for (int i=s; i<l; ++i){
            if (A[i]>A[i-1] && B[i]>B[i-1]) continue;
            else return false;
        }
        return true;
    }

    int minSwap(vector<int>& A, vector<int>& B) {
        int count{0};
        int n = A.size();
        vector<int> dp(n+1, 1e9);
        dp[0] = 0;
        for (int i=1; i!=n; ++i){
            if (A[i]>A[i-1] && B[i]>B[i-1]) dp[i] = dp[i-1];
            else {
                int min_index{0};
                for (int j=1; j<=i; ++j){
                    swap(A[j], B[j]);
                    if (isOK(A, B, i, j)) {
                        if (dp[j-1]+1<dp[i]) {
                            dp[i] = dp[j-1] + 1;
                        }
                    }
                    swap(A[j], B[j]);
                }
            }
        }
        return dp[n-1];
    }
};

int main(){
    Solution s = Solution();
    vector<int> a = {0, 7, 8, 10, 10, 11, 12, 13, 19, 18};
    vector<int> b = {4, 4, 5, 7, 11, 14, 15, 16, 17, 20};
    int r = s.minSwap(a, b);
    return 0;
}