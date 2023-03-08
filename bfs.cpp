#include<bits/stdc++.h>
using namespace std;

vector<int> graph[10000];
vector<int> ans;
int level[10000] = {}, instamp[10000] = {}, x = 0;
queue<int> q;

void bfs(int i){

    for(auto y : graph[i]){
        if(!instamp[y]){
            q.push(y);
            instamp[y] = 1;
            level[y] = level[i] + 1;
        }

    }

    ans.push_back(i);
    x++;


    q.pop();
    if(!q.empty())
        bfs(q.front());
}

int main(){
    int n;
    cin>>n;
    while(n--){
        int a, b;
        cin>>a>>b;
        graph[a].push_back(b);
    }

    q.push(0);
    bfs(0);
    level[0] = 0;
    for(int i = 0; i < x; i++){
        cout<<level[i]<<" ";
    }
    cout<<"\n";
    for(auto y : ans){
        cout<<y<<" ";
    }
}
