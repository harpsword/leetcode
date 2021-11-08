#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<deque>
#include<map>

using namespace std;

class Solution {
public:
    string sortString(string s) {
        if (s.size()==0) return "";
        map<char, int> stats;

        for (char c : s){
            if (stats.find(c) == stats.end()){
                stats[c] = 1;
            }else stats[c]++;
        }

        int count = 0;
        string output = "";
        set<char> used;
        while (count < s.size())
        {
            used.clear();
            for (auto iter_s = stats.begin(); iter_s != stats.end(); iter_s++){
                output = output + iter_s->first;
                count++;
                used.insert(iter_s->first);
            }
            for (char c : used){
                if (stats[c]==1){
                    stats.erase(c);
                }else stats[c]--;
            }

            used.clear();
            for (auto iter_s = stats.rbegin(); iter_s != stats.rend(); iter_s++){
                output = output + iter_s->first;
                count++;
                used.insert(iter_s->first);
            }
            for (char c : used){
                if (stats[c]==1){
                    stats.erase(c);
                }else stats[c]--;
            }

        }
        
        
        return output;
    }
};


int main(){

    map<char, int> ttt;
    ttt['a'] = 1;
    cout << ttt['a'];
    return 1;
}