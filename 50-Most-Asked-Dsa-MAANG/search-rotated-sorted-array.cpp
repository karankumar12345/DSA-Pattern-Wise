#include<iostream>
#include<vector>
#include<climits>
#include<set>
using namespace std;
int search(vector<int>& nums, int target) {
    int s = 0, e = nums.size() - 1;

    while (s <= e) {
        int mid = s + (e - s) / 2;

        if (nums[mid] == target) {
            return mid;  // Found target
        }

        // Check which half is sorted
        if (nums[s] <= nums[mid]) { // Left half is sorted
            if (nums[s] <= target && target < nums[mid]) {
                e = mid - 1; // Search left
            } else {
                s = mid + 1; // Search right
            }
        } else { // Right half is sorted
            if (nums[mid] < target && target <= nums[e]) {
                s = mid + 1; // Search right
            } else {
                e = mid - 1; // Search left
            }
        }
    }

    return -1;  // Target not found
}
int  main(){
    int n;
    cout<<"Enter The Size of Array"<<endl;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cout << "Enter the element at index " << i << ": ";

        cin>>arr[i];
    }
  cout<<search(arr,12);

}