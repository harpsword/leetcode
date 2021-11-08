#include <iostream>
#include <vector>
#include<string>
#include <set>

using namespace std;

class Solution {
public:
    // the count of element in Multiplication Table which <= target
    int le(int target, int m, int n) {
        int ret = 0;
        for (int i = 1; i <= m; i++) {
            int maxn = target / i;
            ret += min(maxn, n);
        }
        return ret;
    }
    
    int findKthNumber(int m, int n, int k) {
        int l = 1;
        int r = 30000 * 30000;
        int ret = r;
        // binary search
        while (l <= r) {
            int mid = (l+r) / 2;
            int x = le(mid, m, n);
            //cout << mid << " " << x << endl;
            if (x >= k) {
                if (le(mid-1, m, n) < k) ret = min(ret, mid);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ret;
    }
};

int main(){
    Solution s = Solution();
    long sss=  s.findKthNumber(27000, 25000, 400001111);
    return 0;
}