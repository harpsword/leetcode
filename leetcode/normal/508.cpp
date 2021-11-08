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
    unordered_map<int, int> count;
    set<int> existed;
    vector<int> r;
public:

    int dfs(TreeNode* node){
        int left{0}, right{0};
        if (node->left) left = dfs(node->left);
        if (node->right) right = dfs(node->right);
        int subtree_sum = left + right + node->val;
        if (existed.count(subtree_sum)) count[subtree_sum]++;
        else {
            count[subtree_sum]=1;
            existed.insert(subtree_sum);
        }
        return subtree_sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        if (root==nullptr) return r;
        dfs(root);
        int max_count{0};
        for (int i:existed){
            if (count[i]>max_count){
                r.clear();
                r.push_back(i);
                max_count = count[i];
            }else if (count[i]==max_count) r.push_back(i);
        }
        return r;
    }
};