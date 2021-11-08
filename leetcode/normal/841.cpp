#include<iostream>
#include<set>
#include<vector>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int l=rooms.size();
        if (l==0) return true;
        set<int> visited;

        dfs(rooms, visited, 0);
        if (visited.size()<l) return false;
        else return true;
    }

    void dfs(vector<vector<int>>& rooms, set<int>& visited, int node){
        if (visited.find(node)!=visited.end()) return;
        visited.insert(node);
        for (int p:rooms[node]){
            dfs(rooms, visited, p);
        }
    }

};