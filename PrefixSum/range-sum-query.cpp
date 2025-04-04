#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class NumArray {
private:
    vector<int> prefix;  // Vector to store the prefix sum

public:
    // Constructor to calculate the prefix sum
    NumArray(vector<int>& nums) {
        prefix.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            prefix.push_back(prefix[i - 1] + nums[i]);
        }
    }

    // Function to get the sum of elements between indices left and right
    int sumRange(int left, int right) {
        if (left == 0) {
            return prefix[right];
        }
        return prefix[right] - prefix[left - 1];
    }
};

int main() {
    // Example input
    vector<int> arr{1, 2, 3, 45, 5};
    
    // Create a NumArray object
    NumArray numArray(arr);

    // Test sumRange function
    cout << "Sum of range (0, 2): " << numArray.sumRange(0, 2) << endl;  // Should output 6 (1+2+3)
    cout << "Sum of range (1, 4): " << numArray.sumRange(1, 4) << endl;  // Should output 55 (2+3+45+5)
    cout << "Sum of range (2, 3): " << numArray.sumRange(2, 3) << endl;  // Should output 48 (3+45)

    return 0;
}
