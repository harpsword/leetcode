#include <iostream>
#include <vector>
#include <set>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:

    void search(TreeNode* node, vector<int>& ll){
        if (node->left != NULL) search(node->left, ll);
        ll.push_back(node->val);
        if (node->right != NULL) search(node->right, ll);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ll;
        if (root != nullptr) search(root, ll);
        return ll;
    }
};