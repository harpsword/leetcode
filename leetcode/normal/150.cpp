#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <set>
#include <math.h>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> value;

        set<string> opt = {"+", "-", "*", "/"};
        for (auto s: tokens){
            if (opt.find(s) != opt.end()){
                int a = value.top();
                value.pop();
                int b = value.top();
                value.pop();
                int c = 0;
                switch (s[0])
                {
                case '*':
                    c = a * b;
                    break;
                case '/':
                    c = b / a;
                    break;
                case '+':
                    c = a + b;
                    break;
                case '-':
                    c = a - b;
                    break;
                }
                value.push(c);
            }else {
                value.push(stoi(s));
            }
        }
        return value.top();
    }
};

int main(){
    Solution s = Solution();
    vector<string> input = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    int a = s.evalRPN(input);
    return 1;
}