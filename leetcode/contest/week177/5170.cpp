#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> input(n, 0);
        // vector<int> output(n, 0);
        for (int i=0; i!=n; i++){
            if (leftChild[i]!=-1){
                input[leftChild[i]]++;
            }
            if (rightChild[i]!=-1){
                input[rightChild[i]]++;
            }
        }
        int zeroInput = 0;
        for (int i=0; i!=n; i++){
            if (input[i]==0) zeroInput++;
            else if (input[i]>1) return false;
        }
        if (zeroInput!=1) return false;
        return true;
    }
};