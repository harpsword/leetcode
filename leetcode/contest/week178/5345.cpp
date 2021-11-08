#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>

using namespace std;


class Solution {
public:
    string rankTeams(vector<string>& votes) {
        set<int> allABC;
        int n, m;
        n = votes.size();
        if (n==0) return "";
        m = votes[0].size();
        vector<vector<int>> count(26, vector<int>(26, 0));

        for (int i:votes[0]){
            allABC.insert(i-'A');
        }
        for (int i=0; i!=n; i++)
            for (int j=0; j!=m; j++){
                count[votes[i][j]-'A'][j]++;
            }
        string r = "";
        int max_count = 0;
        vector<int> max_id;
        set<int> used;
        set<int> tmpV;
        while (r.length()<m)
        {
            int first_one = -1;
            bool foundNoOne = true;
            for (int rank=0; rank!=m; rank++)
            {
                max_count = 0;
                if (rank==0 || max_id.size() == 0) tmpV = allABC;
                else if (max_id.size() > 0){
                    tmpV.clear();
                    for (int i: max_id) tmpV.insert(i);
                }
                max_id.clear();
                for (int i : tmpV){
                    if (used.find(i)==used.end() && count[i][rank]>max_count){
                        max_count = count[i][rank];
                        max_id.clear();
                        max_id.push_back(i);
                    }
                    else if (used.find(i)==used.end() && count[i][rank]==max_count && max_count != 0){
                        max_id.push_back(i);
                    }
                }
                if (max_count!=0){
                    first_one = max_id[0];
                    if (max_id.size()==1){
                        r = r + char(max_id[0] + 'A');
                        used.insert(max_id[0]);
                        foundNoOne = false;
                        break;
                    }
                }
            }
            if (foundNoOne && first_one != -1){
                r = r + char(first_one + 'A');
                used.insert(first_one);
            }
        }
        return r;
    }
};


int main(){
    Solution s = Solution();
    //"ABC","ACB","ABC","ACB","ACB"
    // vector<string> input = {"ABC", "BCA", "CAB"};
    vector<string> input = {"WXYZ","XYZW"};
    cout << s.rankTeams(input);
    return 1;
}