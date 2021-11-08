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

// 0: 没有覆盖
// 1: 有camera
// 2: 无camera，但是被覆盖了

class Solution {
    int r{0};
public:
    int dfs(TreeNode* node){
        if (!node) return 2;
        if (node->left==nullptr && node->right==nullptr) return 0;
        int left = dfs(node->left);
        int right = dfs(node->right);
        if (left==0 || right==0) {
            r++;
            return 1;
        }
        else if (left==2 && right==2){
            return 0;
        }else return 2;
    }

    int minCameraCover(TreeNode* root) {
        if (!root) return 0;
        int s = dfs(root);
        if (s==0) r++;
        return r;
    }
};