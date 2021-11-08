#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<deque>
#include<map>

using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> dp1(n+1, 0), dp2(n+1, 0);

        set<char> tmp;
        set<char> tmpIn;
        for (int i = 0; i != n; i++){
            if (tmp.find(s[i])==tmp.end()) tmp.insert(s[i]);
            if (tmp.size()==3) {
                int new_one = 0;
                tmpIn.clear();
                tmpIn.insert(s[i]);
                for (int j = i - 1; j >= 0; j--){
                    if (s[j] == s[i]) break;
                    if (tmpIn.find(s[j]) == tmpIn.end()) tmpIn.insert(s[j]);
                    if (tmpIn.size() == 3) new_one++;
                }
                dp1[i] = dp1[i-1] + new_one;
                dp2[i] = dp1[i] + dp2[i-1];
            }
        }
        return dp2[n-1];
    }
};


int main()
{
    Solution s = Solution();
    cout << s.numberOfSubstrings("ababc");
    return 1;
}
