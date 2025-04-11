#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> threesum(vector<int>& arr, int target) {
    int n = arr.size();
    vector<vector<int>> result;

    // Sort the array to use the two-pointer technique
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 2; i++) {
        // Skip duplicates for the first element
        if (i > 0 && arr[i] == arr[i - 1]) continue;

        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int currentSum = arr[i] + arr[left] + arr[right];

            if (currentSum == target) {
                result.push_back({arr[i], arr[left], arr[right]});
                // Skip duplicates for the second element
                while (left < right && arr[left] == arr[left + 1]) left++;
                // Skip duplicates for the third element
                while (left < right && arr[right] == arr[right - 1]) right--;
                left++;
                right--;
            }
            else if (currentSum < target) {
                left++;
            }
            else {
                right--;
            }
        }
    }

    return result; // Return all the triplets
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

    // Call threesum and capture the result
    vector<vector<int>> result = threesum(arr, target);

    // Check if a solution was found and display it
    if (!result.empty()) {
        cout << "Triplets that sum to " << target << " are:" << endl;
        for (auto& triplet : result) {
            cout << "[";
            for (int num : triplet) {
                cout << num << " ";
            }
            cout << "]" << endl;
        }
    } else {
        cout << "No solution found" << endl;
    }

    return 0;
}
