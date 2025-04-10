#include<iostream>
#include<vector>
#include<climits>
#include<set>
using namespace std;
int maxProduct(vector<int>&nums){
    int n = nums.size();
       
    int ans = INT_MIN;

    int prefix = 1;
    int suff = 1;
    for (int i = 0; i < n; i++) {
        if (prefix == 0)
            prefix = 1;
        if (suff == 0)
            suff = 1;

        prefix *= nums[i];
        suff *= nums[n - i - 1];
        ans = max(ans, max(prefix, suff));
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

    cout<<maxProduct(arr);

}