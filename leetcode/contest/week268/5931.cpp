

#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<deque>
#include<map>

using namespace std;

class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int result = 0;

        int count = capacity;
        int i = 0;
        while (i < plants.size()) {
           int current = plants[i];
            if (count >= current) {
                count -= current;
                i++;
            } else {
                result = result + i * 2;
                count = capacity;
            } 
        }
        if (count < capacity) {
            result += plants.size();
        }
        return result;
    }
};