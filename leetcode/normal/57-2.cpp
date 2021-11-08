#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <math.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int t = 2 * target;
        int maxn = (int) sqrt((double) t);

        int n = maxn;
        vector<vector<int>> results;

        while (n > 1)
        {
            if ((t-n*n) % n==0 && (((t-n*n)/n+1)%2==0) ){
                vector<int> tmp;
                int a1 = ((t-n*n)/n +1)/2;
                for (int i=a1; i<=a1+n-1; i++)
                    tmp.push_back(i);
                results.push_back(tmp);
            }
            n--;
        }
        return results;
        
    }
};

int main(){
    Solution s = Solution();
    vector<vector<int>> output = s.findContinuousSequence(9);
    return 1;
}