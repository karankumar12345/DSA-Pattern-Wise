#include <iostream>
#include <vector>
using namespace std;

class ProductOfNumbers {
public:
    vector<int> prefix;  // To store cumulative product values

    ProductOfNumbers() {
        prefix.push_back(1);  // Start with a base case (product of 0 numbers is 1)
    }
    
    void add(int num) {
        if (num == 0) {
            // If the number is 0, reset the prefix array because product becomes 0 after this
            prefix.clear();
            prefix.push_back(1);  // Reset with the base case
        } else {
            // Add the new product to the cumulative product
            prefix.push_back(prefix.back() * num);
        }
    }
    
    int getProduct(int k) {
        // If k is larger than the size of prefix, return 0
        if (k >= prefix.size()) return 0;
        
        // Calculate the product of the last k numbers
        return prefix[prefix.size() - 1] / prefix[prefix.size() - 1 - k];
    }
};

int main() {
    ProductOfNumbers* obj = new ProductOfNumbers();
    
    obj->add(3);
    obj->add(2);
    obj->add(1);
    cout << obj->getProduct(2) << endl; // Expected output: 2 (product of 2 and 1)
    
    obj->add(4);
    cout << obj->getProduct(3) << endl; // Expected output: 24 (product of 4, 1, and 2)
    
    obj->add(0);
    cout << obj->getProduct(3) << endl; // Expected output: 0 (after 0, the product of any range is 0)
    
    obj->add(5);
    cout << obj->getProduct(2) << endl; // Expected output: 5 (product of 5)
    
    return 0;
}
