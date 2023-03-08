#include<bits/stdc++.h>
using namespace std;

struct road{
    int to, t, k;
};

class cmp{
    public: bool operator()(pair<int , long long int> a, pair<int , long long int> b){
        return a.second > b.second;
    } 
};


int main(){
    int n, m, x, y;
    cin>>n>>m>>x>>y;
    bool visited[n + 1];
    long long int dis[n + 1];
    for(int i = 0; i <= n; i++){
        visited[i] = false;
        dis[i] = 1e18;
    }
    dis[x] = 0;
    priority_queue<pair<int, long long int>, vector<pair<int, long long int>>, cmp> pq;
    pq.push(make_pair(x, 0));
    vector<road> graph[n + 1];
    while(m--){
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        road *newroad = new road;
        newroad->to = b;
        newroad->t = c;
        newroad->k = d;
        graph[a].push_back(*newroad);
        newroad->to = a;
        graph[b].push_back(*newroad);
    }
    while(!visited[y]){
        int now_min = 0;
        while(!pq.empty()){
            if(!visited[pq.top().first]){
                now_min = pq.top().first;
                pq.pop();
                break;
            }
            pq.pop();    
        }
        if(!now_min){
            cout<<-1;
            break;
        }
        if(now_min == y){
            cout<<dis[now_min];
            break;
        }
        visited[now_min] = true;
        for(auto v: graph[now_min]){
            if(dis[now_min] % v.k){
                if(((dis[now_min] / v.k) + 1) * v.k + v.t < dis[v.to]){
                    dis[v.to] = ((dis[now_min] / v.k) + 1) * v.k + v.t;
                    pq.push(make_pair(v.to, dis[v.to]));
                }
            }
            else{
                if(dis[now_min]+ v.t < dis[v.to]){
                    dis[v.to] = dis[now_min] + v.t;
                    pq.push(make_pair(v.to, dis[v.to]));
                }
            }
        }
    }
}