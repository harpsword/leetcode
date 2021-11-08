
#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<deque>
#include<map>

using namespace std;

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        quickSelect(arr, 0, arr.size()-1, k);
        vector<int> output;
        for (int i = 0; i != k; i++) output.push_back(arr[i]);
        return output;
    }

    void quickSelect(vector<int>& arr, int l, int r, int k){
        int mid = k-1;
        int i = l; 
        int j = r;
        while (i <= j){
            while (arr[i] < arr[mid]) i++;
            while (arr[j] > arr[mid]) j--;
            if (i <= j){
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }
    }

    void quick_sort(vector<int>& sequnce, int s, int e){
        int mid = sequnce[(s+e)/2];
        int l = s, r = e;
        while (l < r){
            // 从小到大改成从大到小需要调整这里
            while (sequnce[l]<mid) l++;
            while (sequnce[r]>mid) r--;
            if (l <= r){
                int tmp = sequnce[l];
                sequnce[l] = sequnce[r];
                sequnce[r] = tmp;
                l++;
                r--;
            } 
        }
        if (l < e) quick_sort(sequnce, l, e);
        if (s < r) quick_sort(sequnce, s, r);
    }
};

int main(){
    vector<int> a{5, 12, 55, 22, 3, 4};
    Solution s = Solution();
    // s.quick_sort(a, 0, a.size()-1);
    // for (int i: a)
    //     cout << i << " " << endl;

    for (int i: s.getLeastNumbers(a, 3))
        cout << i << " " << endl;
    return 1;
}