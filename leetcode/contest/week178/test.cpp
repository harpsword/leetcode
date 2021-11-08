#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>

using namespace std;

bool t(){
    cout << "test " << endl;
    return true;
}

int main(){
    bool tt = t() || t();
    return 1;
}