
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m, p;
        cin>>n>>m>>p;
        vector<pair<int, int>> graph[n];
        
        while(m--){
            int a, b, w;
            cin>>a>>b>>w;
            graph[a].push_back(make_pair(b, w));
        }
        int dis[n][n];
        for(int i = 0 ; i< n; i++){
            for(int j = 0; j < n; j++){
                if(i == j)
                    dis[i][j]= 0;
                else
                    dis[i][j]= 1e9;
            }
        }
        
        for(int i = 0; i < n; i++){
            queue<int> q;
            q.push(i);
            int len[n] = {};
            for(int j = 0; j < n; j++)
                len[j] = 0;
            while(!q.empty()){
                int now= q.front();
                q.pop();
                for(auto x:graph[now]){
                    if(dis[i][x.first] > dis[i][now] + x.second){
                        if(dis[i][x.first] == -1e9)
                            continue;
                        if(dis[i][now] == -1e9){
                            dis[i][x.first] = -1e9;
                            
                        }
                        
                        else{
                            dis[i][x.first] = dis[i][now] + x.second;
                            len[x.first] = len[now] + 1;
                            if(len[x.first] > n){
                                dis[i][x.first] = -1e9;
                            }
                        }
                        
                        q.push(x.first);
                    }
                }
            }
        }
        while(p--){
            int a, b;
            cin>>a>>b;
            if(dis[a][b] == 1e9){
                cout<<"Impossible\n";
            }
            else if(dis[a][b] == -1e9)
                cout<<"-Infinity\n";
            else{
                cout<<dis[a][b]<<"\n";
            }
        }
    }
}