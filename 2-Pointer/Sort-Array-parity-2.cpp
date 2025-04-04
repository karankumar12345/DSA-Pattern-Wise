#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

vector<int> sortArrayByParityII(vector<int>& nums) {
    int s = 0, e = 1; // s for even indices, e for odd indices
    int n = nums.size();
    
    while (s < n && e < n) {
        // If the element at even index is even, just move s
        if (nums[s] % 2 == 0) {
            s += 2;
        }
        // If the element at odd index is odd, just move e
        else if (nums[e] % 2 != 0) {
            e += 2;
        }
        // Otherwise, swap the elements at s and e
        else {
            swap(nums[s], nums[e]);
            s += 2;
            e += 2;
        }
    }
    
    return nums;
}

int main() {
    vector<int> arr = {4,2,5,7}; // Initialize vector with values

    vector<int> result = sortArrayByParityII(arr);
    
    // Output the sorted array
    for (int i = 0; i < result.size(); i++) {
        cout << "element " << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}
