#include <iostream>
#include <vector>
#include <set>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    struct IntNode {
        vector<int> neighbor_id;
    };
    Node* cloneGraph(Node* node) {
        set<int> used;
        vector<IntNode> list(101);
        search(node, list, used);
        
        vector<Node*> graph;
        for (auto i=used.begin(); i!=used.end(); ++i){
            Node* newNode = new Node();
            newNode->val = *i;
            graph.push_back(newNode);
        }
        for (auto i=graph.begin();i!=graph.end(); ++i){
            for (int j: list[(*i)->val].neighbor_id)
            {
                (*i)->neighbors.push_back(graph[j-1]);
            }
        }
        return  graph[0];
    }

    void search(Node* node, vector<IntNode>& list, set<int>& used)
    {
        if (used.find(node->val) != used.end()){
            return;
        }
        else used.insert(node->val);

        for (Node* p : node->neighbors){
            list[node->val].neighbor_id.push_back(p->val);
            search(p, list, used);
        }
    }

};

int main(){
    Node* node1 = new Node();
    Node* node2 = new Node();
    node1->val = 1;
    node2->val = 2;
    node1->neighbors.push_back(node2);
    node2->neighbors.push_back(node1);

    Solution s = Solution();
    Node* r = s.cloneGraph(node1);
    return 0;
}