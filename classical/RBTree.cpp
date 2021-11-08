#include<iostream>

using namespace std;

// Red Black Tree 

enum RBTColor{RED, BLACK};

struct RBTNode
{
    int val;
    RBTColor color;
    RBTNode* left;
    RBTNode* right;
    RBTNode* parent;
    RBTNode(int value, RBTColor c, RBTNode *p,RBTNode *l, RBTNode *r):
            val(value),color(c),left(l),right(r),parent(p) {}
};

class RBTree{
    RBTree();
    ~RBTree();

private:
    RBTNode* root;
    void leftRotate(RBTNode* x);
    void rightRotate(RBTNode* x);
};

void RBTree::leftRotate(RBTNode* x){
    RBTNode* y = x->right;
    x->right = y->left;
    if (y->left != nullptr) y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == nullptr) root = y;
    else if (x == x->parent->left) x->parent->left = y;
    else x->parent->right = y;
    y->left = x;
    x->parent = y;
}

void RBTree::rightRotate(RBTNode* x){
    RBTNode* y = x->left;
    x->left = y->right;
    if (y->right != nullptr) y->right->parent = x;

    y->parent = x->parent;
    if (x->parent == nullptr) root = y;
    else if (x->parent->left == x) x->parent->left = y;
    else x->parent->right = y;

    y->right = x;
    x->parent = y;
}
