#include<iostream>
#include<set>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
using namespace std;

//每个email视为一个个体，
// 输入的每一个小集合可以视为 email之间相关

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, string> father;
        map<string, string> name;
        set<string> visited;
        for (auto account: accounts){
            if (account.size()==1) continue;
            for (int i=1;i!=account.size();i++){
                if (visited.find(account[i])==visited.end()){
                    visited.insert(account[i]);
                    father.insert(pair<string, string>(account[i], account[1]));
                    name.insert(pair<string, string>(account[i], account[0]));
                } else{
                    unionSet(father, account[i], account[1]);
                }
            }
        }
        vector<vector<string>> result;
        set<string> father_visited;
        map<string, int> result_map;
        for (auto s:visited){
            string f = find(father, s);
            if (father_visited.find(f) == father_visited.end()){
                father_visited.insert(f);
                vector<string> tmp;
                tmp.push_back(name[f]);
                tmp.push_back(s);
                result.push_back(tmp);
                result_map.insert(pair<string, int>(f, result.size()-1));
            }else{
                result[result_map[f]].push_back(s);
            }
        }
        return result;
    }

    void unionSet(map<string, string>& father, string a, string b){
        a = find(father, a);
        b = find(father, b);
        father[a] = father[b];
    }

    string find(map<string, string>& father, string a){
        if (a==father[a]) return a;
        father[a] = find(father, father[a]);
        return father[a];
    }
};