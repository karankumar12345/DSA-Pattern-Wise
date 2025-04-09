#include<iostream>
#include<vector>
#include<set>
using namespace std;
vector<int>ProductArray(vector<int>&arr){
    int n=arr.size();
    vector<int> ans(n, 1);
    int leftProduct=1;

    for(int i=0;i<arr.size();i++){
     ans[i]=leftProduct;
     leftProduct*=arr[i];
     
    }
    int rightProduct=1;
    for(int i=arr.size()-1;i>=0;i--){
        ans[i]*=rightProduct;
        rightProduct*=arr[i];
    }
   return ans;
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
    vector<int>ans=ProductArray(arr);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
   
    }

}