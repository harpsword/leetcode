#include <iostream>
#include <string>

using namespace std;

int stoi(char a){
    if (a == '0') {
        return 0;
    }else if (a == '1') {
        return 1;
    }
    return 0;
}

class Solution {
public:
    string addBinary(string a, string b) {
        string c = "";
        int i = a.size()-1;
        int j = b.size()-1;
        int l = max(i, j);

        int tmpsum=0;
        while (i >= 0  || j >= 0)
        {
            /* code */
            if (i >= 0)
                tmpsum += stoi(a[i]);
            if (j >= 0)
                tmpsum += stoi(b[j]);
            
            c = (char) (tmpsum % 2) + c;
            // deal tmpsum
            tmpsum = tmpsum / 2;
            i--;j--;
        }
        if (tmpsum > 0) c = '1' + c;
        return c;
    }
};


int main(){
    Solution s = Solution();
    cout << s.addBinary("1111", "11");
    return 0;
}