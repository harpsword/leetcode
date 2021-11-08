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
    
    void dfs(vector<vector<int>>& r, TreeNode* root, int sum, vector<int> visited){
        visited.push_back(root->val);
        if (root!=nullptr && root->left==nullptr && root->right==nullptr){
            if (sum==root->val){
                r.push_back(visited);
            }
        }
        if (root->left) dfs(r, root->left, sum-root->val, visited);
        if (root->right) dfs(r, root->right, sum-root->val, visited);
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> r;
        if (root==nullptr) return r;
        dfs(r, root, sum, vector<int>());
        return r;
    }
};