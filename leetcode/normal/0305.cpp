#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;


class SortedStack {
    stack<int> s1, s2;
public:
    SortedStack() {

    }
    
    void push(int val) {
        if (s1.empty()) s1.push(val);
        else {
            while (s1.empty()==false && s1.top() < val)
            {
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(val);
            while (!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
        }
    }
    
    void pop() {
        if (!s1.empty()) s1.pop();
    }
    
    int peek() {
        if (s1.empty()) return -1;
        else return s1.top();
    }
    
    bool isEmpty() {
        return s1.empty();
    }
};

int main(){

    SortedStack* obj = new SortedStack();
    // obj->push(1);
    // obj->push(2);
    // int a1 = obj->peek();
    obj->pop();
    int a2 = obj->peek();
    return 1;
}