#include<iostream>
#include<vector>
using namespace std;

vector<int>diStringMatch(string s){
    vector<int>ans;
    int n=s.size();
    int i=0;
    int j=0;

    while(n>=i){
        if(j<s.size()&& s[j]=='I'){
          ans.push_back(i);
          i++;
        }
        else{
          ans.push_back(n);
          n--;
        }
        j++;
    }

      return ans;
  }
int main(){
    string s="DDI";


vector<int>result=diStringMatch(s);
for(int i=0;i<result.size();i++){
    cout<<result[i];
}
}