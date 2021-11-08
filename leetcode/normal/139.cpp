#include <iostream>
#include <vector>
#include<string>
#include <set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        if (n==0) return false;
        vector<bool> dp(n, false);

        for (int i=0; i!=n; ++i){
            int size = i + 1;
            for (string& tt:wordDict){
                if (size<tt.size()) continue;
                if (!(size==tt.size())) {
                    if (!dp[i-tt.size()]) continue;
                }
                if (s.substr(size-tt.size(), tt.size())==tt) dp[i] = true;
            }
        }
        return dp[n-1];
    }
};

int main(){
    string s = "leetcode";
    vector<string> dict = {"leet", "code"};
    Solution ss = Solution();
    bool ad=  ss.wordBreak(s, dict);
    return 1; 
}