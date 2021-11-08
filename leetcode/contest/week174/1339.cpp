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
    long MOD = 1000000007;

    int all_sum = 0;
    int bestSubSum = 0;
    int halfAllSum = 0;
public:
    int maxProduct(TreeNode* root) {
        sum(root, all_sum);
        halfAllSum = all_sum / 2;
        int tmp = visit(root);
        return (bestSubSum % MOD) * (all_sum - bestSubSum) %MOD;
    }

    int visit(TreeNode* node){
        int left = 0;
        int right = 0;
        if (node->left != nullptr) left = visit(node->left);
        if (node->right != nullptr) right = visit(node->right);
        return node->val + left + right;
    }

    void check(int s_I){
        if (abs(s_I-halfAllSum)<abs(bestSubSum-halfAllSum)) bestSubSum = s_I;
    }

    void sum(TreeNode* node, int &ss){
        ss += node->val;
        if (node->left != nullptr) sum(node->left, ss);
        if (node->right != nullptr) sum(node->right, ss);
    }
};