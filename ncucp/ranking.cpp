#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin>>n>>m;
    int deg[n + 1] = {};
    vector<int> graph[n + 1];
    while(m--){
        int a, b;
        cin>>a>>b;
        graph[a].push_back(b);
        deg[b]++;

    }
    queue<int> q, ans;
    for(int i = 1; i <= n; i++){
        if(!deg[i])
            q.push(i);
    }
    while(!q.empty()){
        if(q.size() != 1){
            cout<<-1;
            return 0;
        }
        int now = q.front();
        q.pop();
        ans.push(now);
        for(auto x:graph[now]){
            deg[x]--;
            if(!deg[x])
                q.push(x);
        }
    }
    if(ans.empty())
        cout<<-1;
    else{
        while(!ans.empty()){
            cout<<ans.front()<<" ";
            ans.pop();
        }
    }
}