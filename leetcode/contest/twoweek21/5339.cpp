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
    int max_value = 0;
    int maxV = 40000;
    int minV = -40000;
public:
    int maxSumBST(TreeNode* root) {
        int maxv, minv, sumv;
        bool ok;
        maxS(root, maxv, minv, sumv, ok);
        return max_value;
    }

    void maxS(TreeNode* node, int &maxv, int &minv, int &sumv, bool &ok){
        // min, max, sum, false or not
        // vector<int> output{node->val, node->val, node->val, 1};
        if (node == nullptr) {
            maxv = minV;
            minv = maxV;
            sumv = 0;
            ok = true;
            return;
        }
        if (node->left == nullptr && node->right == nullptr) {
            max_value = max(max_value, node->val);
            maxv = node->val;
            minv = node->val;
            sumv = node->val;
            ok = true;
            return;
        }
        int lmax, lmin, lsum;
        bool lok;
        maxS(node->left, lmax, lmin, lsum, lok);

        int rmax, rmin, rsum;
        bool rok;
        maxS(node->right, rmax, rmin, rsum, rok);

        // if (right[3] == 0) return {0, 0, 0, 0};

        ok = false;
        if (node->val > lmax && node->val < rmin && lok && rok){
            max_value = max(max_value, node->val+lsum+rsum);
            ok = true;
        }
        if (!ok) return;
        maxv = max(max(lmax, rmax), node->val);
        minv = min(min(lmin, rmin), node->val);
        sumv = lsum + rsum + node->val;
    }
};


int main(){

    TreeNode node4 = TreeNode(4);
    
    TreeNode node1 = TreeNode(1);
    TreeNode node2 = TreeNode(2);
    TreeNode node3 = TreeNode(3);

    node4.left = &node3;
    node3.left = &node1;
    node3.right = &node2;

    Solution s = Solution();
    int output = s.maxSumBST(&node4);
    return 1;
}