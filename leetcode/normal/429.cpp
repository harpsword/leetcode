#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

// 简单的队列既可

//Definition for a binary tree node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        q.push(root);
        vector<vector<int>> r;
        if (root==nullptr) return r;
        while (!q.empty())
        {
            int ss = q.size();
            vector<int> tmp;
            while (ss--)
            {
                Node* front = q.front();
                q.pop();
                tmp.push_back(front->val);
                for (auto ii : front->children)
                    q.push(ii);
            }
            r.push_back(tmp);
        }
        return r;
    }
};