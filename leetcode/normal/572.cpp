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

    bool check(TreeNode* s, TreeNode* t){
        if (s==nullptr && t==nullptr) return true;
        else if (s==nullptr) return false;
        else if (t==nullptr) return false;
        else if (s->val != t->val) return false;
        else return check(s->left, t->left) && check(s->right, t->right);
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        queue<TreeNode*> q;
        q.push(s);
        while (!q.empty())
        {
            int ss = q.size();
            while (ss--)
            {
                TreeNode* front = q.front();
                q.pop();
                if (front->val!=t->val) {
                    if (front->left!=nullptr) q.push(front->left);
                    if (front->right != nullptr) q.push(front->right);
                }else {
                    if (check(front, t)) return true;
                    else {
                        if (front->left!=nullptr) q.push(front->left);
                        if (front->right != nullptr) q.push(front->right);
                    }
                }
            }
            
        }
        return false;
    }
};