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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> r;
        if (root==nullptr) return r;
        while (!q.empty())
        {
            int ss = q.size();
            vector<int> tmp;
            while (ss--)
            {
                TreeNode* front = q.front();
                q.pop();
                tmp.push_back(front->val);
                if (front->left!=nullptr) q.push(front->left);
                if (front->right!=nullptr) q.push(front->right);
            }
            r.insert(r.begin(), tmp);
            // r.push_back(tmp);
        }
        return r;
    }
};