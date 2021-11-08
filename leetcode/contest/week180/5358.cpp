
#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<deque>
#include<map>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    vector<int> value;
public:
    TreeNode* balanceBST(TreeNode* root) {
        visit(root);
        sort(value.begin(), value.end());
        int n = value.size();
        return build(0, n-1);
    }

    TreeNode* build(int l, int r){
        int mid = (l + r) /2;
        TreeNode* root = new TreeNode(value[mid]);
        if (l < mid) root->left = build(l, mid-1);
        if (r > mid) root->right = build(mid+1, r);
        return root;
    }

    void visit(TreeNode* node){
        value.push_back(node->val);
        if (node->left != nullptr) visit(node->left);
        if (node->right != nullptr) visit(node->right);
    }
};