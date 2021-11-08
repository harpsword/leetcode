#include<iostream>
#include<set>
#include<vector>
// 检查有无环路即可
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 入度
        vector<set<int>> rely(numCourses, set<int>());
        vector<set<int>> to(numCourses, set<int>());
        if (prerequisites.size() ==0) return true;
        for (auto p : prerequisites){
            rely[p[0]].insert(p[1]);
            to[p[1]].insert(p[0]);
        }
        set<int> finished;
        while (finished.size()<numCourses)
        {
            bool find{false};
            int this_time{-1};
            for(int i=0;i!=numCourses;i++){
                if (rely[i].size()==0 && finished.find(i) == finished.end()){
                    this_time = i;
                    finished.insert(this_time);
                    find = true;
                    // delete this_time in rely
                    for (int p:to[this_time]){
                        rely[p].erase(this_time);
                    }
                }
            }
            if (!find) return false;
        }
        return true;
        

    }
};

int main(){
    Solution s = Solution();
    int i = 3;
    vector<vector<int>> m = {{1,0},{1,2},{0,1}};
    return s.canFinish(i, m);
}