#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<deque>
#include<map>
#include<cmath>

using namespace std;

class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        for (int i = 1; i != n; i++)
        {
            if (s[dp[i-1]]==s[i]) dp[i] = dp[i-1] + 1;
            if (s[0]==s[i]) dp[i] = max(dp[i], 1);
        }
        return s.substr(0, dp[n-1]);
        
    }
};

int main(){
    string input = "acccbaaacccbaac";
    Solution s = Solution();
    cout << s.longestPrefix(input);
    return 1;
}