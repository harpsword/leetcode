#include<iostream>
#include<set>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
using namespace std;

// 刚开始默认所有字符之间互斥，

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        if (equations.size()==0) return true;
        map<int, int> father;
        for (int i=(int)'a'; i<=(int)'z';i++) father.insert(pair<int, int>(i,i));
        for (auto s: equations){
            int a = (int) s[0];
            int b = (int) s[3];
            if (s[1]=='='){
                unionSet(father, a, b);
            }
        }
        for (auto s: equations){
            int a = (int) s[0];
            int b = (int) s[3];
            if (s[1]=='!'){
                a = find(father, a);
                b = find(father, b);
                if (a==b) return false;
            }
        }
        return true;
    }

    void unionSet(map<int, int>& father, int a, int b){
        int tmpa, tmpb;
        tmpa = find(father, a);
        tmpb = find(father, b);
        father[tmpa] = father[tmpb];
    }

    int find(map<int, int>& father, int a){
        if (a==father[a]) return a;
        father[a] = find(father, father[a]);
        return father[a];
    }
};

int main(){
    vector<string> A={"f==a","a==b","f!=e","a==c","b==e","c==f"};
    Solution s = Solution();
    cout << s.equationsPossible(A);
    cout << endl;
    return 1;
}