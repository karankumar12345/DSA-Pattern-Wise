#include<iostream>
#include<vector>
#include<climits>
using namespace std;


int SellStock(vector<int>&arr){
    int n=arr.size();
    int maxProfit=0;
    int minPrice=INT_MAX;
    for(int i=0;i<n;i++){
        minPrice=min(minPrice,arr[i]);
        maxProfit=max(maxProfit,arr[i]-minPrice);
    }
    return maxProfit;
}

int main(){
    int n;
    cout<<"Enter The Size of Array"<<endl;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cout << "Enter the element at index " << i << ": ";

        cin>>arr[i];
    }
    cout<<"Max Profit is "<< SellStock(arr);
   
}