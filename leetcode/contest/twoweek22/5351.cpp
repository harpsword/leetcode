
#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<deque>
#include<map>

using namespace std;

class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int size = slices.size();
        int n = size / 3;
        vector<vector<int>> dp(2*size+1, vector<int>(n+1, 0));
        for (int i = 1; i <= n; i++){
            if (i == 1){
                for (int j = 0; j <= size; j++) 
                    dp[j][i] = get_value(slices, j + 1);
            }else {
                for (int j = 0; j <= size; j ++){
                    dp[j][i] = dp[j][i-1] + get_value(slices, j + i * 3 -2 + 2);
                    dp[j][i] = max(dp[j][i], dp[j+3][i-1] + get_value(slices, j+1));
                }
            }
        }
        int r = 0;
        for (int j = 0; j <= size; j++)
            r = max(r, dp[j][n]);
        return r;
    }

    int get_value(vector<int>& slices, int i){
        return slices[i % slices.size()];
    }
};

int main(){
    Solution s = Solution();
    vector<int> input{1, 2, 3, 4, 5, 6};
    cout << s.maxSizeSlices(input);
    return 1;
}