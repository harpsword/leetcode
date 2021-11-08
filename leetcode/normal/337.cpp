#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>

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

    vector<int> dfs(TreeNode* node){
        vector<int> rr(2, 0);
        if (!node) return rr;
        if (node->left==nullptr && node->right==nullptr){
            rr[0] = node->val;
            rr[1] = 0;
            return rr;
        }
        vector<int> left = dfs(node->left);
        vector<int> right = dfs(node->right);
        rr[0] = left[1] + right[1]+node->val;
        // 父节点不选，那么两个子节点选不选都可以，最优的组合结果如下
        rr[1] = max(left[0], left[1]) + max(right[0], right[1]);
        return rr;
    }

    int rob(TreeNode* root) {
        if (!root) return 0;
        vector<int> r = dfs(root);
        return max(r[0], r[1]);
    }
};