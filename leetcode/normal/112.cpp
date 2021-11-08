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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root!=nullptr && root->left==nullptr && root->right==nullptr){
            if (sum==root->val) return true;
            else return false;
        }else if (root==nullptr){
            if (sum==0) return true;
            else return false;
        }
        bool left{false}, right{false};
        if (root->left) left = hasPathSum(root->left, sum-root->val);
        if (root->right) right = hasPathSum(root->right, sum-root->val);
        return left || right;
    }
};