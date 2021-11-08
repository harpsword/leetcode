#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        vector<int> yu1 = {1, 4, 7};
        vector<int> yu2 = {2, 5, 8};
        int sum = 0;
        string s = "";
        vector<int> statistic(10, 0);
        for (int i : digits){
            statistic[i]++;
            sum += i;
        }
        bool correct = false;
        if (sum % 3 ==0) correct = true;
        if ( sum % 3 == 1){
            for (int i: yu1){
                if (! correct){
                    if (statistic[i]>0) {
                        statistic[i]--;
                        correct = true;
                    }
                }
            }

            if (! correct){
                int tmpSum = 0;
                for (int i : yu2){
                    if (statistic[i] >= 2){
                        statistic[i]-=2;
                        correct = true;
                    }
                    tmpSum += statistic[i];
                }
                if (!correct){
                    if (tmpSum>=2){
                        int t = 2;
                        for (int i: yu2){
                            t -= statistic[i];
                            statistic[i] = 0;
                            if (t==0) break;
                        }
                        correct = true;
                    }
                }
            }
        }else if (sum % 3 == 2){
            for (int i: yu2){
                if (! correct){
                    if (statistic[i]>0) {
                        statistic[i]--;
                        correct = true;
                    }
                }
            }

            if (! correct){
                int tmpSum = 0;
                for (int i : yu1){
                    if (statistic[i] >= 2){
                        statistic[i]-=2;
                        correct = true;
                    }
                    tmpSum += statistic[i];
                }
                if (!correct){
                    if (tmpSum>=2){
                        int t = 2;
                        for (int i: yu1){
                            t -= statistic[i];
                            statistic[i] = 0;
                            if (t==0) break;
                        }
                        correct = true;
                    }
                }
            }
        }
        if (correct){
            for (int i=9; i>=0; i--){
                for (int j=0; j < statistic[i]; j++)
                    s = s + char(i+'0');
            }
        }
        if (s[0] == '0' && s.length()>1) s='0';
        return s;
    }
};


int main(){
    Solution s = Solution();
    vector<int> input = {8, 1, 9};
    cout << s.largestMultipleOfThree(input);
    return 1;
}