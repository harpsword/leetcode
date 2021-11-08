#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
    vector<string> r;
public:

    void dfs(TreeNode* node, string s){
        if (node->left==nullptr && node->right==nullptr) {
            s+=to_string(node->val);
            r.push_back(s);
        }
        else{
            s = s + to_string(node->val) + "->";
            if (node->left) dfs(node->left, s);
            if (node->right) dfs(node->right, s);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if (root==nullptr) return r;
        string s = "";
        dfs(root, s);
        return r;
    }
};