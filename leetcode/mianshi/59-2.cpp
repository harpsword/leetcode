#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<deque>

using namespace std;

class MaxQueue {
    deque<int> baseQ, assistantQ;
public:
    MaxQueue() {

    }
    
    int max_value() {
        if (baseQ.empty()) return -1;
        else return assistantQ.front();
    }
    
    void push_back(int value) {
        baseQ.push_back(value);
        while (!assistantQ.empty() && assistantQ.back() < value)
        {
            assistantQ.pop_back();
        }
        assistantQ.push_back(value);
    }
    
    int pop_front() {
        if (baseQ.empty()) return -1;
        int tmp = baseQ.front();
        baseQ.pop_front();
        if (assistantQ.front() == tmp) assistantQ.pop_front();
        return tmp;
    }
};