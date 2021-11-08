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

    bool check(TreeNode* node){
        if (node==nullptr) return true;
        if (node->left==nullptr && node->right==nullptr) return true;
        else if (node->left==nullptr) return (node->val == node->right->val) && check(node->right);
        else if (node->right==nullptr) return (node->val == node->left->val) && check(node->left);
        else return (node->val==node->left->val) && (node->val==node->right->val) && check(node->left) && check(node->right);
    }

    bool isUnivalTree(TreeNode* root) {
        return check(root);
    }
};