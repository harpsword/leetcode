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

    bool search(TreeNode* p, int& depth){
        if (p!=nullptr){
            int left = depth+1;
            int right = depth+1;
            bool l = search(p->left, left);
            bool r = search(p->right, right);
            depth = max(left, right);
            if (l&&r) return (abs(left-right)<=1);
            else return false;
        }
        return true;
    }

    bool isBalanced(TreeNode* root) {
        if (root==nullptr) return true;
        int depth = 0;
        return search(root, depth);
    }
};