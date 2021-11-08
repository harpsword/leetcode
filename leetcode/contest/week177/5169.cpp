#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> month_day = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int daysBetweenDates(string date1, string date2) {
        int year1, year2, m1, m2, day1, day2;
        year1 = stoi(date1.substr(0, 4));
        year2 = stoi(date2.substr(0, 4));
        m1 = stoi(date1.substr(5, 2));
        m2 = stoi(date2.substr(5, 2));
        day1 = stoi(date1.substr(8, 2));
        day2 = stoi(date2.substr(8, 2));

        int count1 = dayCount(year1, m1, day1);
        int count2 = dayCount(year2, m2, day2);
        return abs(count1 - count2);
    }

    int dayCount(int year, int month, int day){
        int count=0;
        for (int i = 1971; i < year; i++){
            if (isSpecial(i)) count += 366;
            else count += 365;
        }
        for (int i = 1; i < month; i++){
            count += month_day[i-1];
            if (i == 2 && isSpecial(year)) count++;
        }
        return count + day;
    }

    bool isSpecial(int year){
        if (year % 100 == 0){
            if (year % 400 == 0) return true;
            else return false;
        }else {
            if (year % 4 == 0) return true;
            else return false;
        }
    }
};