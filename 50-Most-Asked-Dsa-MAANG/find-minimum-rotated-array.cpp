#include<iostream>
#include<vector>
#include<climits>
#include<set>
using namespace std;
int findMin(vector<int>&arr){
    int n=arr.size();
    int s=0;
    int e=arr.size();
    while(s<e){
        int mid=s+(e-s)/2;
        if (arr[mid] < arr[e]) {
            e = mid;  // Include mid
        } 
        else {  // If left half is sorted, search right
            s = mid + 1;
        }

    }
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
  cout<<findMin(arr);

}