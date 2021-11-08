#include<iostream>
#include<set>
#include<vector>
// 先检查有无环路
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // 入度
        vector<set<int>> rely(numCourses, set<int>());
        vector<set<int>> to(numCourses, set<int>());
        vector<int> result, empty_R, full_R;
        for (int i=0;i!=numCourses;i++) full_R.push_back(i);
        if (prerequisites.size() ==0) return full_R;
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
                    // 当前删除的节点很容易产生新的入度为0的节点
                    // 所以在该节点指向的节点中寻找新的入度为0的节点可以很好的提高效率
                    while (rely[this_time].size()==0 && finished.find(this_time)==finished.end())
                    {
                        finished.insert(this_time);
                        result.push_back(this_time);
                        find = true;
                        // delete this_time in rely
                        for (int p:to[this_time]){
                            rely[p].erase(this_time);
                        }
                        for (int p:to[this_time]){
                            if (rely[p].size()==0) {
                                this_time = p;
                                break;
                            }
                        }
                    }
                }
            }
            if (!find) return empty_R;
        }
        return result;
        

    }
};

int main(){
    Solution s = Solution();
    int i = 3;
    vector<vector<int>> m = {{1,0},{1,2},{0,1}};
    vector<int> ss = s.findOrder(i, m);
    return 1;
}