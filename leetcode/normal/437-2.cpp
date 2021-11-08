#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

// 思路存在问题

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

    int r;
public:
    Solution():r(0) {}
    void dfs(TreeNode* root, int pathSum, unordered_map<int, int>& freq, int sum){
        if (root){
            pathSum += root->val;
            r += freq[pathSum-sum];
            freq[pathSum]++;
            dfs(root->left, pathSum, freq, sum);
            dfs(root->right, pathSum, freq, sum);
            freq[pathSum]--;
        }
    }

    int pathSum(TreeNode* root, int sum) {
        if (root==nullptr) return r;
        unordered_map<int, int> freq;
        freq[0] = 1;
        dfs(root, 0, freq, sum);
        return r;
    }
};