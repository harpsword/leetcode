#include <iostream>
#include <vector>
#include <set>

using namespace std;


// Definition for a Node.
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
    void search(Node* node, vector<int>& visit){
        visit.push_back(node->val);
        for (auto n:node->children){
            if (n!=NULL) search(n, visit);
        }
    }

    vector<int> preorder(Node* root) {
        vector<int> visit;
        if (root!=NULL) search(root, visit);
        return visit;
    }   
};