

#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<deque>
#include<map>

using namespace std;

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        vector<vector<char>> v;
        int size = encodedText.length();
        int column = size / rows;
        for (int i =0; i != rows; i++) {
            vector<char> oColumn;
            for (int j = 0; j != column; j ++) {
                oColumn.push_back(encodedText[i * column + j]);
            }
            v.push_back(oColumn);
        }
        string result = "";
        while (true)
        {
            
        }
        
    }
};