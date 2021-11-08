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
    Solution():r(-1e9) {}

    int dfs(TreeNode* node){
        if (node==nullptr) return 0;
        int a = dfs(node->left);
        int b = dfs(node->right);
        a = max(a, 0);
        b = max(b, 0);
        int sum = a + b + node->val;
        r = max(sum, r);
        return max(a, b)+node->val;
    }

    int maxPathSum(TreeNode* root) {
        r = root? root->val: 0;
        dfs(root);
        return r;
    }
};