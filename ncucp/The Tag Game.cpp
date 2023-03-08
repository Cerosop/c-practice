#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    
    vector<int> graph[n + 1];
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin>>a>>b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    bool visa[n + 1], visb[n + 1];
    int disa[n + 1], disb[n + 1];

    for(int i = 1; i <= n; i++){
        visa[i] = false;
        visb[i] = false;
        disa[i] = 1e9;
        disb[i] = 1e9;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, 1));
    disa[1] = 0;
    while(!pq.empty()){
        int now = pq.top().second;
        pq.pop(); 
        if(visa[now]){
            continue;
        }
        visa[now] = true;
        for(auto x:graph[now]){
            if(disa[x] > disa[now] + 2){
                disa[x] = disa[now] + 2;
                pq.push(make_pair(disa[x], x));
            }
        }
    }

    pq.push(make_pair(-1, m));
    disb[m] = -1;
    while(!pq.empty()){
        int now = pq.top().second;
        pq.pop(); 
        if(visb[now]){
            continue;
        }
        visb[now] = true;
        for(auto x:graph[now]){
            if(disb[x] > disb[now] + 2){
                disb[x] = disb[now] + 2;
                pq.push(make_pair(disb[x], x));
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(disa[i] > disb[i]){
            ans = max(ans, disa[i]);
        }
    }
    cout<<ans;

}