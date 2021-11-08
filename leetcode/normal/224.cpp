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

    void meetRightBrace(stack<int> &value, stack<char> &opt){
        while (!opt.empty() && opt.top()!='('){
            char optr = opt.top();
            opt.pop();
            int c = 0;
            int b = value.top();
            value.pop();
            int a = value.top();
            value.pop();
            switch (optr){
                case '+':
                    c = a+b;
                    break;
                case '-':
                    c = a - b;
                    break;
            }
            value.push(c);
        }
    }

    int calculate(string s) {
        stack<int> value;
        stack<char> opt;
        map<char, int> priority = {
            {'+', 10}, 
            {'-', 10},
            {'*', 20},
            {'/', 20}
        };

        int tmpS = -1;
        for (int i = 0; i != s.size(); i++){
            if (s[i] != ' '){
                if (s[i] >= '0' && s[i]<='9' ){
                    if (tmpS == -1) tmpS = i;
                }else {
                    if (tmpS!=-1){
                        value.push(stoi(s.substr(tmpS, i - tmpS)));
                        tmpS = -1;
                    }
                    if (s[i] == '+' || s[i] == '-') {
                        if (!opt.empty()){
                            meetRightBrace(value, opt);
                        }
                        opt.push(s[i]);
                    }
                    else if (s[i] == '(') opt.push(s[i]);
                    else if (s[i] == ')'){
                        meetRightBrace(value, opt);
                        opt.pop();
                    }
                }
            }
            else {
                if (tmpS != -1) {
                    value.push(stoi(s.substr(tmpS, i - tmpS)));
                    tmpS = -1;
                }
            }
        }

        if (tmpS != -1) {
            value.push(stoi(s.substr(tmpS, s.size() - tmpS)));
        }
        

        while (!opt.empty()){
            char optr = opt.top();
            opt.pop();
            int c = 0;
            int b = value.top();
            value.pop();
            int a = value.top();
            value.pop();
            switch (optr){
                case '+':
                    c = a+b;
                    break;
                case '-':
                    c = a - b;
                    break;
                default:
                    break;
            }
            value.push(c);
        }
        return value.top();
    }
};

int main(){
    Solution s = Solution();
    string input = " 2 - 1 + 2 ";
    int a = s.calculate(input);
    cout << a << endl;
    return 1;
}