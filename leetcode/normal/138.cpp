#include <iostream>
#include <vector>
#include <set>
#include <map>
// copy list with random pointer
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        int special{-1111};
        if (head==nullptr) return nullptr;
        set<int> visited;
        map<int, int> next, random;
        dfs(head, visited, next, random);
        map<int, Node*> list;
        for (int p:visited){
            Node* tmp= new Node();
            tmp->val = p;
            tmp->next = nullptr;
            tmp->random = nullptr;
            list.insert(pair<int, Node*>(p, tmp));
        }
        Node* copyHead = list[head->val];
        for(int p:visited){
            if (next.count(p)) list[p]->next = list[next[p]];
            if (random.count(p)) list[p]->random = list[random[p]];
        }
        return copyHead;
    }

    void dfs(Node* head, set<int>& visited, map<int, int>& next, map<int, int>& random){
        if (visited.find(head->val)!=visited.end()) return;
        visited.insert(head->val);
        if (head->next!=nullptr) {
            next.insert(pair<int, int>(head->val, head->next->val));
            dfs(head->next, visited, next, random);
        }
        if (head->random!=nullptr) {
            random.insert(pair<int,int>(head->val, head->random->val));
            dfs(head->random, visited, next, random);
        }
    }
};

int main(){
    Node* head = new Node();
    Node* node2 = new Node();
    head->val = 1;
    node2->val = 2;
    head->next = node2;
    head->random = node2;
    node2->next = nullptr;
    node2->random = node2;
    Solution s = Solution();
    Node* copyHead = s.copyRandomList(head);
    return 1;
}