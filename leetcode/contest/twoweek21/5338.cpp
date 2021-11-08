#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<deque>
#include<map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}; 


class Solution {
    int max_len = 0;
public:
    int longestZigZag(TreeNode* root) {
        if (root->left != nullptr) visit(0, 1, root->left);
        if (root->right != nullptr) visit(1, 1, root->right);
        return max_len;
    }

    void visit(int direction, int l, TreeNode* root){
        // direction , 0 -> left, 1 -> right
        max_len = max(l, max_len);
        if (root->left != nullptr) {
            if (direction == 0) visit(0, 1, root->left);
            else visit(0, l+1, root->left);
        }
        if (root->right != nullptr){
            if (direction == 0) visit(1, l+1, root->right);
            else visit(1, 1, root->right);
        }
    }
};