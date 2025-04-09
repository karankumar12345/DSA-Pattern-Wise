#include<iostream>
#include<vector>
#include<set>
using namespace std;
bool containDublicate(vector<int>&arr){
    set<int>st;
    for(int i=0;i<arr.size();i++){
        if(st.find(arr[i])!=st.end()){
            return true;
        }
        st.insert(arr[i]);
    }
    return false;
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
    cout<<containDublicate(arr)<<endl;
}