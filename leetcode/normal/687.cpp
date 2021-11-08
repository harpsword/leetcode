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
        // return the number of nodes satisfies the constraint
        if (!node) return 0;
        int left = dfs(node->left);
        int right = dfs(node->right);
        if (node->left && node->val!=node->left->val) left = 0;
        if (node->right && node->val!=node->right->val) right = 0;
        r = max(left+right, r);
        return max(left, right)+1;
    }

    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;
        dfs(root);
        return r;
    }
};