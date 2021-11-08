#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        map<char,vector<int>> mp;
        for(auto v:votes){
            for(int i = 0; i < v.size();i++){
                mp[v[i]].resize(v.size());
                mp[v[i]][i]++;
            }      
        }
        string res = votes[0];
        sort(res.begin(),res.end(),[&](char a, char b){
            return mp[a]> mp[b] || mp[a] == mp[b] && a < b;
        });
         return res;  
    }
};