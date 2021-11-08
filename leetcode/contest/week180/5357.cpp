#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<deque>
#include<map>

using namespace std;



class CustomStack {

    int maxS = 0;
    int value[1000];
    int top = 0;
public:
    CustomStack(int maxSize) {
        maxS = maxSize;
    }
    
    void push(int x) {
        if (top<maxS-1) value[top++] = x;
    }
    
    int pop() {
        if (top == 0) return -1;
        else return value[--top];
    }
    
    void increment(int k, int val) {
        int nn = small(k, top);
        for (int i = 0; i != nn; i++) value[i]+=val;
    }

    int small(int a, int b){
        return a < b ? a:b;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */