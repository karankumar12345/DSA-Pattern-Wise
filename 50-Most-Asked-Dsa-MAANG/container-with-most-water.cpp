#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0,j=n-1;
        int ans=0;
        while(i<j){
            int area=min(height[i],height[j])*(j-i);
            ans=max(ans,area);
            if(height[i]<height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return ans;
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

   cout<<"Most Water"<<maxArea(arr);
    return 0;
}
