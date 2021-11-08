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
    int r{0};
public:
 
    int dfs(TreeNode* node){
        int leftchange{0}, rightchange{0};
        if (node->left) leftchange = dfs(node->left);
        if (node->right) rightchange = dfs(node->right);
        node->val += leftchange;
        node->val += rightchange;
        int change = node->val - 1;
        r += abs(change); 
        return change;
    }

    int distributeCoins(TreeNode* root) {
        if (!root) return 0;
        dfs(root);
        return r;
    }
};