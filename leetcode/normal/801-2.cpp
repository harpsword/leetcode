#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B){
        const int n = A.size();
        const int INI_MAX = 1e9;
        vector<int> keep(n, INI_MAX);
        vector<int> swap(n, INI_MAX);
        keep[0] = 0;
        swap[0] = 1;

        for (int i=1; i<n; ++i){
            if (A[i]>A[i-1] && B[i]>B[i-1]){
                // do nothing
                keep[i] = keep[i-1];
                // Swapped A[i - 1] / B[i - 1], swap A[i], B[i] as well
                swap[i] = swap[i-1] + 1;
            }
            if (A[i]>B[i-1] && B[i]>A[i-1]){
                // A[i - 1] / B[i - 1] weren't swapped.
                swap[i] = min(swap[i], keep[i-1]+1);
                // swap A[i-1]/B[i-1]
                keep[i] = min(keep[i], swap[i-1]);
            }
        }
        return min(keep.back(), swap.back());
    }
};

int main(){
    Solution s = Solution();
    vector<int> a = {0, 7, 8, 10, 10, 11, 12, 13, 19, 18};
    vector<int> b = {4, 4, 5, 7, 11, 14, 15, 16, 17, 20};
    int r = s.minSwap(a, b);
    return 0;
}