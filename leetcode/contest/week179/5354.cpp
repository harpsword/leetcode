#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<deque>
#include<map>

using namespace std;


class Solution {
    map<int, vector<int>> to;
    // int max_value = 0;
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        for (int i = 0; i != n; i++){
            int tmp = manager[i];
            if (to.find(tmp)==to.end()) to[tmp] = vector<int>{i};
            else to[tmp].push_back(i);
        }
        return visit(headID, informTime);
    }

    int visit(int nodeId, vector<int>& informTime){
        if (to.find(nodeId) == to.end()) return 0;
        int max_value = 0;
        for (auto i = to[nodeId].begin(); i!=to[nodeId].end();i++){
            max_value = max(max_value, visit(*i, informTime) + informTime[nodeId]);
        }
        return max_value;
    }
};