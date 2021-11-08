#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int count1{0}, count2{0};
        int i = start;
        int n = distance.size();
        while (i!=destination)
        {
            count1 += distance[i];
            i++;
            i = i % n;
        }

        i = start;
        while (i!=destination)
        {
            if (i==0) count2 += distance[n-1];
            else count2 += distance[i-1];
            
            i--;
            i = i % n;
            if (i<0) i+=n;
        }
        return count1 > count2 ? count2: count1;
    }
};

int main(){
    Solution s  = Solution();
    vector<int> id = {1, 2, 3, 4};
    int r = s.distanceBetweenBusStops(id, 0, 3);
    return 0;
}