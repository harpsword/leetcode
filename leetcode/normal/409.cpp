#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<deque>
#include<map>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        using pci =pair<char,int>;
        map<char, int> count;
        for (char c:s){
            if (count.find(c) == count.end()){
                count[c] = 1;
            }else {
                count[c]++;
            }
        }
        int r = 0;
        int odd_value = 0;
        for (auto iter=count.begin(); iter!=count.end(); iter++){
            if (iter->second % 2 == 0) r += iter->second;
            else r += iter->second - 1;
        }
        if (r != s.size()) r++;
        return r;
    }
};