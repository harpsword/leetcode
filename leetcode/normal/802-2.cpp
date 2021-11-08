#include<iostream>
#include<set>
#include<vector>
#include<queue>
#include<algorithm>
// 先检查有无环路
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int numCourses = graph.size();
        // 入度
        vector<set<int>> rely(numCourses, set<int>());
        vector<set<int>> to(numCourses, set<int>());
        vector<int> result, empty_R;
        if (graph.size() ==0) return empty_R;
        for (int i=0;i!=numCourses; i++){
            for (int j: graph[i]){
                to[j].insert(i);
                rely[i].insert(j);
            }
        }
        queue<int> qint;

        for (int i=0;i!=numCourses;i++){
            if (rely[i].size()==0) qint.push(i);
        }
        while (qint.size()>0)
        {
            int tmp = qint.front();
            result.push_back(tmp);
            qint.pop();
            for (int i:to[tmp]){
                rely[i].erase(tmp);
                if (rely[i].size()==0) qint.push(i);
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