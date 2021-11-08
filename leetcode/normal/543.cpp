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

    int dfs(TreeNode* node){
        if (!node) return 0;
        int left = dfs(node->left);
        int right = dfs(node->right);
        r = max(left+right, r);
        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (root==nullptr) return 0;
        dfs(root);
        return r;
    }
};