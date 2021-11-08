#include <iostream>
#include <vector>
#include <set>

using namespace std;

// 思路存在问题

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    
    void dfs(TreeNode* root, int sum, vector<int> visited, int& i){
        visited.push_back(root->val);
        if (root!=nullptr && root->left==nullptr && root->right==nullptr){
            for (int j=0; j!=visited.size();++j)
            {
                int ss = 0;
                for (int k=j; k!=visited.size(); ++k){
                    ss+=visited[k];
                    if (ss==sum){
                        i++;
                        break;
                    }
                }
            }
        }
        if (root->left) dfs(root->left, sum-root->val, visited, i);
        if (root->right) dfs(root->right, sum-root->val, visited, i);
    }

    int pathSum(TreeNode* root, int sum) {
        int r{0};
        dfs(root, sum, vector<int>(), r);
        return r;
    }
};