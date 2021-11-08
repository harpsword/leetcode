#include<iostream>
#include<set>
#include<queue>
#include<vector>
// 贪心实现的迪杰斯特拉算法+最小堆优化
// error for compiling
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        struct ToInfo
        {
            vector<int> node;
            vector<int> price;
        };
        struct Node
        {
            public:
            int index, distance;
            bool operator < (Node& b) const{
                return distance < b.distance;
            };
        };

        vector<ToInfo> to(N+1, ToInfo());
        for (auto& time: times){
            to[time[0]].node.push_back(time[1]);
            to[time[0]].price.push_back(time[2]);
        } 
        constexpr int InfCost = 1e9;
        vector<int> distance(N+1, InfCost);
        distance[K] = 0;
        // wait for expand
        set<int> inQueue;
        inQueue.insert(K);
        priority_queue<Node> Expand;
        Node tt = Node();
        tt.distance = 0;
        tt.index = K;
        Expand.push(tt);
        while (!Expand.empty()){
            int bestnode = Expand.top().index;
            for (int i=0;i!=to[bestnode].node.size();i++){
                int nextnode = to[bestnode].node[i];
                int price = to[bestnode].price[i];
                if (distance[bestnode]+price<distance[nextnode]){
                    distance[nextnode] = distance[bestnode] + price;
                    if (inQueue.find(nextnode)==inQueue.end()){
                        inQueue.insert(nextnode);
                        Node ttt = Node();
                        ttt.index = nextnode;
                        ttt.distance = distance[nextnode];
                        Expand.push(ttt);
                    }
                }
            }
            inQueue.erase(bestnode);
            Expand.pop();
        }
        int result{0};
        for (int i=1;i<=N;i++){
            if (distance[i]==InfCost) return -1;
            result = max(result, distance[i]);
        }
        return result;
    }
};

int main()
{
    Solution s =Solution();

    return 1;
}