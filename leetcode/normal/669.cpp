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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(!root) return root;
        if(root->left) root->left = trimBST(root->left, L, R);
        if(root->right) root->right = trimBST(root->right, L, R);
        
        // check
        if(root->val < L || root->val > R)
        {
            // here does not specify should connect left tree or right tree
            if(root->left) root = root->left;
            else if(root->right) root = root->right;
            else if(!root->right && !root->left) root = nullptr; // leaf, trim it
        }
        return root;
    }
};