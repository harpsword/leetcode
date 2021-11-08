#include <iostream>
#include <vector>
#include<string>
#include <set>

using namespace std;
// 从后往前匹配，注意当出现
// "aa"
// "a"
// "aaa"
// 即三个string的最后一个元素相同时，需要有两个分支，只要一个分支可行，则结果可行
// 超时

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        if (n1+n2!=n3) return false;
        return dfs(s1, n1-1, s2, n2-1, s3);
    }

    bool dfs(string& s1, int i1, string& s2, int i2, string& s3){
        if (i1==-1 && i2!=-1){
            if (s2.substr(i2, 1)==s3.substr(i1+i2+1, 1)) return dfs(s1, i1, s2, i2-1, s3);
            else return false;
        }
        if (i2==-1&& i1!=-1){
            if (s1.substr(i1, 1)==s3.substr(i1+i2+1, 1)) return dfs(s1, i1-1, s2, i2, s3);
            else return false;
        }
        if (i1==-1 && i2==-1) return true;
        string tmp1 = s1.substr(i1, 1);
        string tmp2 = s2.substr(i2, 1);
        string tmp3 = s3.substr(i1+i2+1, 1);
        if (tmp1==tmp3 && tmp2==tmp3) {
            return dfs(s1, i1-1, s2, i2, s3) || dfs(s1, i1, s2, i2-1, s3);
        }
        if (tmp1 == tmp3) return dfs(s1, i1-1, s2, i2, s3);
        else if (tmp2 == tmp3) return dfs(s1, i1, s2, i2-1, s3);
        else return false;
    }
};

int main(){
    Solution s = Solution();
    cout << s.isInterleave("aabcc", "dbbca","aadbbcbcac");
    return 0;
}