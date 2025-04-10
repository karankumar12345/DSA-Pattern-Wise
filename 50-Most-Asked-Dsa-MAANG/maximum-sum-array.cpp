#include<iostream>
#include<vector>
#include<climits>
#include<set>
using namespace std;
int maxSubArray(vector<int>&arr){
    int n=arr.size();
   int maxSum=INT_MIN;
   int sum=0;
   for(int i=0;i<n;i++){
    sum+=arr[i];
    if(sum>maxSum){
        maxSum=sum;
    }
    if(sum<0){
        sum=0;
    }
   
   }
   return maxSum;
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
cout<<maxSubArray(arr)<<endl;

}