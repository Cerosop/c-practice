#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m, dt, nt;
    
    cin>>n>>m>>dt>>nt;
    vector<pair<int, int>> graph[n + 1];
    while(m--){
        int a, b, l;
        cin>>a>>b>>l;
        graph[a].push_back(make_pair(l, b));
        graph[b].push_back(make_pair(l, a));
    }
    priority_queue<pair<long long int, int>, vector<pair<long long int, int>>, greater<pair<long long int, int>>> pq;
    pq.push(make_pair(0, 1));
    bool visited[n + 1];
    long long int dis[n + 1];
    for(int i = 1; i <= n; i++){
        visited[i] = false;
        dis[i] = 1e18;
    }
    dis[1] = 0;
    while(!pq.empty()){
        int now = pq.top().second;
        pq.pop();
        if(visited[now])
            continue;
        visited[now] = true;
        for(auto x:graph[now]){
            if(x.first <= dt){
                if(dis[now] % (dt + nt) + x.first <= dt){
                    if(dis[x.second] > dis[now] + x.first){
                        dis[x.second] = dis[now] + x.first;
                        pq.push(make_pair(dis[x.second], x.second));
                    }
                }
                else if(dis[x.second] > ((dis[now]) / (dt + nt) + 1) * (dt + nt) + x.first){
                    dis[x.second] = ((dis[now]) / (dt + nt) + 1) * (dt + nt) + x.first;
                    pq.push(make_pair(dis[x.second], x.second));
                }
            }
        }
    }
    if(dis[n] == 1e18)
        cout<<-1;
    else
        cout<<dis[n];
}