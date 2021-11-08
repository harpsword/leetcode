#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

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

    void dfs(TreeNode* node, int v){
        int val = v*10+node->val;
        if (node->left) dfs(node->left, val);
        if (node->right) dfs(node->right, val);

        if (node->left==nullptr && node->right==nullptr){
            r += val;
        }
    }

    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        dfs(root, 0);
        return r;
    }
};