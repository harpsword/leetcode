#include<iostream>
#include<set>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
// 先建立图
// 再寻找无向图中的最大连通分量
using namespace std;


class Solution {
public:
    int largestComponentSize(vector<int>& A) {
        int max_value = 100001;
        int count{0};
        int n = A.size();
        if (n==0) return 0;
        vector<vector<int>> to(n, vector<int>());
        vector<int> table = primeTable(max_value);
        for (int i = 0;i!=n;i++)
        {
            for(int j=0;j!=i;j++){
                if (connected(A[i], A[j], table)){
                    to[i].push_back(j);
                    to[j].push_back(i);
                }
            }
        }

        set<int> visited;
        int result{0}, pre_size{0};
        while (visited.size()<n){
            pre_size = visited.size();
            for (int i=0;i!=n;i++){
                if (visited.find(i)==visited.end()){
                    dfs(i, to, visited);
                    break;
                }
            }
            if (visited.size()-pre_size>result) result = visited.size() - pre_size;
        }
        return result;
    }

    void dfs(int node, vector<vector<int>>& to, set<int>& visited){
        visited.insert(node);
        for (int next_node: to[node]){
            if (visited.find(next_node) == visited.end()){
                dfs(next_node, to, visited);
            } 
        }
    }

    bool connected(int A, int B, vector<int>& table){
        int T = A;
        if (B>A) T=B;
        if (T==1) return false;
        if (A%T ==0 && B%T == 0) return true;
        for (int p:table){
            if (p>=T) return false;
            if (A % p==0 && B % p ==0) return true;
        }
        return false;
    }

    vector<int> primeTable(int max_value){
        vector<int> table;
        vector<bool> isPrime(max_value+1, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for (int i=2; i<=sqrt(max_value);i++)
            if (isPrime[i]){
                table.push_back(i);
                for (int j=i+i;j<=max_value;j+=i) isPrime[j] = false;
            }
        return table;
    }
};