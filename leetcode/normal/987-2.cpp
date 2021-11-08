#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

// 深度优先搜索版本，按照题目要求，应该采用宽度优先搜索
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> r;
        map<int, vector<int>> record;
        if (root==nullptr) return r;
        queue<TreeNode*> q;
        queue<int> idx;
        q.push(root);
        idx.push(0);

        while (!q.empty())
        {
            int s = q.size();
            while (s--)
            {
                TreeNode *node = q.front();
                q.pop();
                int x = idx.front();
                idx.pop();
                
                if (record.count(x)) record[x].push_back(node->val);
                else{
                    vector<int> tmp;
                    tmp.push_back(node->val);
                    record.insert({x, tmp});
                }
                if (node->left!=nullptr) {
                    q.push(node->left);
                    idx.push(x-1);
                }
                if (node->right!=nullptr){
                    q.push(node->right);
                    idx.push(x+1);
                }
            }
        }

        int min_x = 0;
        for (int x=-1010; x!=1010; ++x){
            if (record.count(x)){
                min_x = x;
                break;
            }
        }
        int max_x = 0;
        for (int x = 1010; x!=-1010; --x){
            if (record.count(x)){
                max_x = x;
                break;
            }
        }
        for (int i=min_x; i<=max_x; ++i)
        {
            r.push_back(record[i]);
        }
            
        return r;
    }
};

int main(){
    TreeNode *root = new TreeNode(1);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n4 = new TreeNode(4);
    TreeNode *n5 = new TreeNode(5);
    root->left = n2;
    root->right = n3;
    n2->left = n4;
    n2->right = n5;
    Solution s = Solution();
    vector<vector<int>> r = s.verticalTraversal(root);

    return 0;
}