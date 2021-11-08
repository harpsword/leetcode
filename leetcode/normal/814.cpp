#include <iostream>
#include <vector>
#include <set>

using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    void dfs(TreeNode*& node){
        if (node->left!=nullptr) dfs(node->left);
        if (node->right!=nullptr) dfs(node->right);

        if (node->left==nullptr && node->right==nullptr && node->val==0) node=nullptr; 
    }

    TreeNode* pruneTree(TreeNode* root) {
        if (root==nullptr) return root;
        dfs(root);
        return root;
    }
};