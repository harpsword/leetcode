#include <iostream>
#include <vector>
#include <set>
#include <queue>

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

    void dfs(TreeNode* node, vector<int>& leaf_s){
        if (node->left==nullptr && node->right==nullptr) leaf_s.push_back(node->val);
        else if (node->left==nullptr) dfs(node->right, leaf_s);
        else if (node->right==nullptr) dfs(node->left, leaf_s);
        else {
            dfs(node->left, leaf_s);
            dfs(node->right, leaf_s);
        }
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf_s1, leaf_s2;
        if (root1!=nullptr) dfs(root1, leaf_s1);
        if (root2!=nullptr) dfs(root2, leaf_s2);
        if (leaf_s1.size()!=leaf_s2.size()) return false;
        else {
            for (int i=0; i!=leaf_s1.size(); ++i){
                if (leaf_s1[i]!=leaf_s2[i]) return false;
            }
        }
        return true;
    }
};