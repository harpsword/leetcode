
#include <iostream>
#include <vector>

using namespace std;

class ProductOfNumbers {
public:
    ProductOfNumbers() {
        sequence = {};
    }
    
    void add(int num) {
        sequence.push_back(num);
    }
    
    int getProduct(int k) {
        int s = sequence.size();
        int r = 1;
        for (int i = s - 1; i >= s - k; i--) r = r * sequence[i];
        return r;
    }
private:
    vector<int> sequence;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */