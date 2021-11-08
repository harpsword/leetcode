#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        int today = 9;
        int toyear = 2019;
        int tomonth = 9;
        set<int> big = {1, 3, 5, 7, 8, 10, 12};
        set<int> small = {4, 6, 9, 11};
        // to 小 
        if (year < toyear || (year==toyear && month < tomonth) || (year==toyear && month==tomonth && day < today))
        {
            swap(year, toyear);
            swap(day, today);
            swap(month, tomonth);
        }
        int thisyear = 0;
        for (int i = month; i<=12; ++i){
            if ()
        }
    }
};