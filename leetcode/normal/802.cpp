#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
// 先检查有无环路
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // 入度
        int numCourses = graph.size();
        vector<set<int>> rely(numCourses, set<int>());
        vector<set<int>> to(numCourses, set<int>());
        vector<int> result, empty_R;
        if (graph.size() ==0) return empty_R;
        for (int i=0;i!=numCourses; i++){
            for (int j: graph[i]){
                rely[i].insert(j);
                to[j].insert(i);
            }
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
            if (!find) {
                sort(result.begin(), result.end());
                return result;
            }
        }
        sort(result.begin(), result.end());
        return result;
        

    }
};

int main(){
    Solution s = Solution();
    int i = 3;
    vector<vector<int>> m = {{1,0},{1,2},{0,1}};
    vector<int> ss = s.eventualSafeNodes(m);
    return 1;
}