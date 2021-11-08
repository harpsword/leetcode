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

    void search(TreeNode* p, int& depth){
        if (p!=nullptr){
            int left = depth+1;
            int right = depth+1;
            search(p->left, left);
            search(p->right, right);
            if (p->left==nullptr && p->right==nullptr) {
                return;
            }else if (p->left == nullptr){
                depth = right;
            }else if (p->right == nullptr){
                depth = left;
            }else depth = min(left, right);
        }
    }

    int minDepth(TreeNode* root) {
        if (root==nullptr) return 0;
        int depth = 1;
        search(root, depth);
        return depth;
    }
};