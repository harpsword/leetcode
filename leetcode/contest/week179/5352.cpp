#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<deque>
#include<map>

using namespace std;



class Solution {
public:
    string generateTheString(int n) {
        string output(n, 'a');
        if (n == 0) return "";
        if (n % 2 == 0) return output.substr(0, n-1) + 'b';
        else return output;
    }
};