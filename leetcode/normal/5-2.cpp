#include <iostream>
#include <vector>
#include <string>

using namespace std;


// 算法存在问题：这个算法会把所有的回文子串记录下来，导致内存溢出

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(1, 1));

        int max_len, max_end;
        max_len = 1;
        max_end = 0;
        
        for (int i = 1; i != n; i++){
            if (s[i-1]==s[i]) {
                dp[i].push_back(2);
                if (2 > max_len) {
                    max_len = 2;
                    max_end = i;
                }
            }
            for (int l: dp[i-1]){
                if (i-1-l>=0 && s[i-1-l] == s[i]) {
                    if (l+2+2 <= max_len) break;
                    dp[i].push_back(l+2);
                    if (l+2 > max_len){
                        max_len = l+2;
                        max_end = i;
                    }
                }
            }
        }
        return s.substr(max_end - max_len + 1, max_len);
    }
};

int main(){

    Solution s = Solution();
    cout << s.longestPalindrome("bbbb");
    return 1;
}