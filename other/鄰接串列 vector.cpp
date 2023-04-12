#include<bits/stdc++.h>
using namespace std;

struct edge{
    int v, w;
};

vector<edge> graph[10000];

void addedge(int u, int v, int w){
    graph[u].push_back({v, w});
    //graph[v].push_back({u, w});
}
int main(){
    int x, n;
    cin>>x>>n;
    while(n--){
        int u, v, w;
        cin>>u>>v>>w;
        addedge(u, v, w);
    }
    for(int i = 0; i < x; i++){
        cout<<i<<" ";
        for(auto g : graph[i]){
            cout<<"("<<g.v<<", "<<g.w<<") ";
        }
        cout<<"\n";
    }
}
