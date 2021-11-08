#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<deque>
#include<map>

using namespace std;



class Solution {
public:
	int maxJumps(vector<int>& arr, int d) {
		int n = arr.size();
		vector<int> dp(n, 1);
        vector<int> index(n, 0);
        for (int i = 0; i!=n; i++) index[i] = i;
        sort(index.begin(), index.end(), [&](int &a, int &b){
            return arr[a] < arr[b] ? true : false;
        });

        for (int i = 0; i != n; i++){
            if (i!=0){
                // left
                for (int j = index[i]-1; j >= index[i]-d; j--){
                    if (j < 0 || j >= n) continue;
                    if (arr[j] >= arr[index[i]]) break;
                    dp[index[i]] = max(dp[index[i]], dp[j] + 1);
                }
                for (int j = index[i] + 1; j <= index[i] + d; j++){
                    if (j < 0 || j >= n) continue;
                    if (arr[j] >= arr[index[i]]) break;
                    dp[index[i]] = max(dp[index[i]], dp[j] + 1);
                }
            }
        }
        int max_v = 0;
        for (int i: dp) max_v = max(max_v, i);
        return max_v;
	}
};

int main(){
    Solution s = Solution();
    vector<int> input = {6,4,14,6,8,13,9,7,10,6,12};
    int r = s.maxJumps(input, 2);
    return 1;
}
