
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>

using namespace std;


class Solution {
public:
    int minSteps(string s, string t) {
        map<char, int> ss, tt;
        for (char c : s){
            
            if (ss.find(c)==ss.end()){
                ss.insert(pair<char, int>(c, 1));
            }else {
                ss[c]++;
            }
            // cout << c << " " << ss[c] << endl;
        }
        for (char c: t){
            if (tt.find(c)==tt.end()){
                tt.insert(pair<char, int>(c, 1));
            }else {
                tt[c]++;
            }
        }

        int count = 0;
        for (auto iter : ss){
            if (tt.find(iter.first)==tt.end()){
                count += iter.second;
            }else {
                if (tt[iter.first] < iter.second) {
                    count = count + iter.second - tt[iter.first];
                }
            }
            // cout << iter.first << " " << iter.second << endl;
            // cout << iter.first << " " << count << endl;
            // cout << "----------" << endl;
        }
        return count;
    }
};

int main(){
    Solution s = Solution();
    string i1 = "bab", i2 = "aba";
    cout << s.minSteps(i1, i2) << endl;
    return 0;
}
