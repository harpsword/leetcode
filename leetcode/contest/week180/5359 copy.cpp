
#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<deque>
#include<map>

using namespace std;

// 贪心法

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<int> speedIndex;
        for (int i = 0; i!=n; i++) speedIndex.push_back(i);
        sort(speedIndex.begin(), speedIndex.end(), [&](int& a, int& b)->bool {
            return efficiency[a] >= efficiency[b];
        });
        priority_queue<int, vector<int>, greater<int>> q;
        long long r{0};
        long long sumC{0};
        for (int i = 0; i != n; i++){
            int index = speedIndex[i];
            q.push(speed[index]);
            if (q.size() <= k){
                sumC += speed[index];
            }else {
                sumC = sumC + speed[index] - q.top();
                q.pop();
            }
            r = max(r, sumC * efficiency[index]);
        }
        return r % 1000000007; 
    }
};

int main()
{
    vector<int> s_in = {2,10,3,1,5,8};
    vector<int> e_in = {5,4,3,9,7,2};
    Solution s = Solution();
    int v = s.maxPerformance(6, s_in, e_in, 2);
    cout << v;
    return 1;
}
