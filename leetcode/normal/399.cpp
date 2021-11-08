#include<iostream>
#include<set>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<map>
// 思路错误，这一题并不能使用并查集
using namespace std;


class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        set<string> char_set;
        map<string, string> father;
        // 结果的分数表示，分子与分母
        map<pair<string, string>, double> true_value;
        for (int i=0; i!=equations.size();i++){
            vector<string> p = equations[i];
            bool p1 = char_set.find(p[0])==char_set.end();
            bool p2 = char_set.find(p[1])==char_set.end();
            if (p1) char_set.insert(p[0]);
            if (p2) char_set.insert(p[1]);
            true_value.insert(pair<pair<string, string>, double>(pair<string, string>(p[0], p[1]), values[i]));
        }
        for (string p:char_set) father.insert(pair<string, string>(p, p));
        for (vector<string> p: equations){
            father[p[0]] = get_father(p[1], father);
        }
        vector<double> result;
        for (vector<string>& q:queries){
            bool p1 = char_set.find(q[0]) == char_set.end();
            bool p2 = char_set.find(q[1]) == char_set.end();
            if (p1 || p2){
                result.push_back(-1.0);
            }else {
                if (get_father(q[0], father) != get_father(q[1], father)){
                    result.push_back(-1.0);
                }else{
                    double v1 = get_value(q[0], father, true_value);
                    double v2 = get_value(q[1], father, true_value);
                    result.push_back(v1/v2);
                }
            }
        }
        return result;
    }

    string get_father(string s, map<string, string>& father){
        if (father[s] == s) return s;
        return get_father(father[s], father);
    }

    double get_value(string s, map<string, string>& father, map<pair<string, string>, double>& true_value){
        if (father[s] == s) return 1.0;
        if (true_value.count(pair<string, string>(s, father[s]))) {
            return true_value[pair<string, string>(s, father[s])] * get_value(father[s], father, true_value);
        }else if (true_value.count(pair<string, string>(father[s], s))){
            return 1.0 / true_value[pair<string, string>(father[s], s)] * get_value(father[s], father, true_value);
        }
        return 1.0;
    }
};