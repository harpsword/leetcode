#include<iostream>
#include<set>
#include<queue>
#include<vector>
// 贪心实现的迪杰斯特拉算法
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        struct ToInfo
        {
            vector<int> node;
            vector<int> price;
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
        set<int> Expand, finished;
        Expand.insert(K);
        while (!Expand.empty()){
            int bestnode = 0;
            int min_distance = InfCost;
            for (int i:Expand){
                if (distance[i]<min_distance && finished.find(i)==finished.end()){
                    min_distance = distance[i];
                    bestnode = i;
                    if (min_distance==0) break;
                }
            }
            for (int i=0;i!=to[bestnode].node.size();i++){
                int nextnode = to[bestnode].node[i];
                int price = to[bestnode].price[i];
                if (distance[bestnode]+price<distance[nextnode]){
                    distance[nextnode] = distance[bestnode] + price;
                    if (Expand.find(nextnode)==Expand.end() && finished.find(nextnode)==finished.end()){
                        Expand.insert(nextnode);
                    }
                }
            }
            Expand.erase(bestnode);
            finished.insert(bestnode);
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