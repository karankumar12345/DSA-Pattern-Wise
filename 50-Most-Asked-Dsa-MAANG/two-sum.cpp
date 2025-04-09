#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> twosum(vector<int>& arr, int target) {
    int n = arr.size();
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++) {
        // Check if the complement (target - arr[i]) exists in the map
        if (map.find(target - arr[i]) != map.end()) {
            // Return the indices of the two numbers
            return {map[target - arr[i]], i};
        }
        // Store the current number and its index in the map
        map[arr[i]] = i;
    }
    return {};  // Return an empty vector if no solution found
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
   
    int target;
    cout << "Enter your target to search: ";
    cin >> target;
    
    // Call twosum and capture the result
    vector<int> result = twosum(arr, target);
    
    // Check if a solution was found and display it
    if (!result.empty()) {
        cout << "Indices of the two numbers are: " << result[0] << " and " << result[1] << endl;
    } else {
        cout << "No solution found" << endl;
    }

    return 0;
}
