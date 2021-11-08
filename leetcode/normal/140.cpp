#include <iostream>
#include <vector>
#include<string>
#include <set>

// 一个问题是int直接爆了
// 第二个问题是构造输出时会发生递归层数过多直接爆炸
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> result;
        long n = s.size();
        if (n==0) return result;
        vector<long> dp(n, 0);
        vector<vector<long>> info(n, vector<long>());
        vector<vector<long>> size_info(n, vector<long>());

        for (long i=0; i!=n; ++i){
            long size = i + 1;
            for (string& tt:wordDict){
                if (size<tt.size()) continue;
                if (!(size==tt.size())) {
                    if (!dp[i-tt.size()]) continue;
                    if (s.substr(size-tt.size(), tt.size())==tt) {
                        dp[i] += dp[i-tt.size()];
                        info[i].push_back(i-tt.size());
                        size_info[i].push_back(tt.size());
                    }
                }else {
                    if (s.substr(size-tt.size(), tt.size())==tt) {
                        dp[i]+=1;
                        info[i].push_back(-1);
                        size_info[i].push_back(tt.size());
                    }
                }
            }
        }
        if (dp[n-1]==0) return result;
        long count = 0;
        for (long i=0; i!=dp[n-1]; ++i) result.push_back("");
        makeup(s, result, dp, info, size_info, 0, dp[n-1], n-1);
        return result;
    }

    void makeup(string& s, vector<string>& result, vector<long>& dp, vector<vector<long>> info, vector<vector<long>> size_info, long l, long r, long node){
        long left = l;
        for (long i=0;i!=info[node].size();++i){
            if (info[node][i]==-1){
                result[left] = s.substr(0, size_info[node][i]);
                left++;
                continue;
            }
            makeup(s, result, dp, info, size_info, left, dp[info[node][i]]+left, info[node][i]);
            for (long j=left; j!=r; j++){
                result[j] = result[j] + " " + s.substr(info[node][i]+1, size_info[node][i]);
            }
            left += dp[info[node][i]];
        }
    }
};

int main(){
    string s = "leetcode";
    vector<string> dict = {"leet", "code"};
    Solution ss = Solution();
    vector<string> ad=  ss.wordBreak(s, dict);
    return 1; 
}