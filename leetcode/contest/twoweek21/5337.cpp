#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<deque>
#include<map>

using namespace std;

class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size() + 1;
        map<char, vector<int>> stat{
            {'a', vector<int>(n)},
            {'e', vector<int>(n)},
            {'i', vector<int>(n)},
            {'o', vector<int>(n)},
            {'u', vector<int>(n)}
        };
        n--;
        for (int i = 0; i!=n; i++){
            if (stat.find(s[i]) == stat.end()) {
                for (auto iter_s: stat){
                    iter_s.second[i+1] = iter_s.second[i];
                }
            }else {
                stat[s[i]][i+1] = stat[s[i]][i] + 1; 
            }
        }
        vector<int> dp(n+1, 0);

        for (int i = 0; i != n; i++){
            if (stat.find(s[i])==stat.end()) dp[i+1] = dp[i] + 1;
            else {
                int last_len = dp[i];
                
            }
        }

    }
};