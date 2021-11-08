#include<iostream>
#include<set>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
// 利用并查集来查找有关联的最大子集
using namespace std;

class Solution {
public:
    int largestComponentSize(vector<int>& A) {
        int max_value = 100001;
        int result{0};
        int n = A.size();
        if (n==0) return 0;
        vector<int> father(max_value, -1);
        for (int i=0;i!=father.size();++i) father[i] = i;
        vector<int> count(max_value, 0);
        vector<int> tmp;
        for (int i = 0;i!=n;i++)
        {
            tmp = get_factors(A[i]);
            for (auto factor:tmp){
                unionSet(father, factor, A[i]);
            }
        }
        int ans = 0;
        for (auto i:A){
            count[find(father, i)]++;
            ans = max(ans, count[find(father, i)]);
        }
        return ans;
    }

    void unionSet(vector<int>& father, int x, int y){
        x = find(father, x);
        y = find(father, y);
        father[x] = father[y];
    }

    int find(vector<int>& father, int x){
        if (x == father[x]) return x;
        father[x] = find(father, father[x]);
        return father[x];
    }

    vector<int> get_factors(int i){
        vector<int> tmp;
        for (int d{2};d<=sqrt(i);d++){
            if (i%d==0) {
                tmp.push_back(d);
                tmp.push_back(i/d);
            }
        }
        return tmp;
    }

};

void test(int i)
{
    cout << "--------------------";
    for (int d{2};d<sqrt(i);d++){
        if (i%d==0) {
            cout << d << " " << i / d <<" ";
        }
    }
}

int main(){
    vector<int> A={4,6,15,35};
    Solution s = Solution();
    cout << s.largestComponentSize(A);
    cout << endl;
    test(463);
    return 1;
}



