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

    bool check(TreeNode* left, TreeNode* right){
        if (left==nullptr && right==nullptr) return true;
        else if (left==nullptr) return false;
        else if (right==nullptr) return false;
        else {
            if (left->val==right->val){
                return check(left->left, right->right) && check(left->right, right->left);
            }else return false;
        }
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        else return check(root->left, root->right);
    }
};