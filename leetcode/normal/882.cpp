#include<iostream>
#include<set>
#include<queue>
#include<vector>

using namespace std;

class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
        // 无向图
        struct ToInfo
        {
            vector<int> node;
            vector<int> price;
        };
        vector<ToInfo> To(N, ToInfo());
        for (auto& edge: edges){
            int a = edge[0];
            int b = edge[1];
            int c = edge[2]+1;
            To[a].node.push_back(b);
            To[a].price.push_back(c);
            To[b].node.push_back(a);
            To[b].price.push_back(c);
        }
        constexpr int InfCost = 1e9;
        vector<int> distance(N, InfCost);
        queue<int> Expand;
        Expand.push(0);
        set<int> inQueue;
        inQueue.insert(0);
        distance[0] = 0;
        while (!Expand.empty())
        {
            int tmpnode = Expand.front();
            Expand.pop();
            for (int i=0;i!=To[tmpnode].node.size();i++){
                int nextnode = To[tmpnode].node[i];
                int price = To[tmpnode].price[i];
                if (distance[tmpnode]+price<distance[nextnode]){
                    distance[nextnode] = distance[tmpnode] + price;
                    if (inQueue.find(nextnode)==inQueue.end()){
                        inQueue.insert(nextnode);
                        Expand.push(nextnode);
                    }
                }
            }
            inQueue.erase(tmpnode);
        }
        int result{0};
        // 先计算点
        for (int i:distance){
            if (i<=M) result++;
        }
        // 后计算边
        for (auto& edge: edges){
            int a = edge[0];
            int b = edge[1];
            int c = edge[2];
            if ((a==0 && b!=0) || (a!=0 && b==0)){
                if (a!=0 && b==0) swap(a, b);
                result += min(c, M+max(M-distance[b], 0));
            }else{
                result += min(c, max(M-distance[a], 0)+max(M-distance[b], 0));
            }
        }
        return result;
        
    }
};

