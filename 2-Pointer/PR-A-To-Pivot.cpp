#include<iostream>
#include<vector>
using namespace std;

vector<int> pivotArray(vector<int>& nums, int pivot) {
    vector<int> result(nums.size(), 0);
    int left = 0, right = nums.size() - 1;
    
    // First pass: place elements smaller than pivot at the left side
    // and elements greater than pivot at the right side
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] < pivot) {
            result[left++] = nums[i];  // Place smaller elements at left
        } else if (nums[i] > pivot) {
            result[right--] = nums[i];  // Place larger elements at right
        }
    }
    
    // Fill in the pivot elements in the middle of the result array
    while (left <= right) {
        result[left++] = pivot;
    }
    
    return result;
}

int main(){
    vector<int> arr{9, 12, 5, 10, 14, 3, 10};
    int pivot = 10;

    vector<int> result = pivotArray(arr, pivot);

    // Print the result array
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
