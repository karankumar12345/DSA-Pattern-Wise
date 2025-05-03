#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool canVisitedAllRooms(vector<vector<int>>& rooms){
    int n=rooms.size();
    vector<bool>visited(n,false);

    queue<int>q;
    visited[0]=true;
    q.push(0);

    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(int key:rooms[curr]){
            if(!visited[key]){
                visited[key]=true;
                q.push(key);
            }
        }
        }
    }




int main(){
    vector<vector<int>>rooms={{1},{2},{3},{}};

    cout<<(canVisitedAllRooms(rooms)?"true":"false")<<endl;
}