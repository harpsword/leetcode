#include<iostream>

using namespace std;

struct skiplistNode
{
    skiplistNode* down;
    skiplistNode* next;
    int val;
    int level;
    skiplistNode(int x, int l): val(x), level(l) {}
};


class skiplist
{
private:
    /* data */
    skiplistNode *root;
public:
    skiplist(/* args */);
    ~skiplist();

    void insert(int );
    void del(int );
    // 不存在则返回-1
    int search(int );
};

skiplist::skiplist(/* args */)
{
}

skiplist::~skiplist()
{
}
