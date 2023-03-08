#include<bits/stdc++.h>
using namespace std;
int flow[51], parent[51], n, remain[51][51], all[51][51];

int findpath(int s, int t){
    memset(flow, 0, sizeof(flow));
    memset(parent, 0, sizeof(parent));
    queue<int> q;
    while(!q.empty())
        q.pop();
    q.push(s);
    parent[s] = s;
    flow[s] = INT_MAX;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i = 1; i <= n; i++){
            if(remain[x][i] > 0 && parent[i] == 0){
                parent[i] = x;
                flow[i] = min(flow[x], remain[x][i]);
                if(i == t)
                    return flow[i];
                q.push(i);
            }
        }
    }
    return 0;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int m;
    while(cin>>n>>m){
        if(!n && !m)
            break;
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                remain[i][j] = 0;
                all[i][j] = 0;
            }
        }
        while(m--){
            int a, b, w;
            cin>>a>>b>>w;
            remain[a][b] = w;
            remain[b][a] = w;
            all[a][b] = w;
            all[b][a] = w;
        }
        while(1){
            int fmin = findpath(1, 2);
            if(fmin == 0){
                break;
            }
            int t = 2, s = parent[t];
            while(s != t){
                remain[s][t] -= fmin;
                remain[t][s] += fmin;
                t = s;
                s = parent[t];
            }
        }
        // ans = 0;
        for(int i = 1; i <= n; i++){
            if(flow[i] > 0){
                for(int j = 1; j <= n; j++){
                    if(flow[j] == 0 && all[i][j] != 0){
                        cout<<i<<" "<<j<<"\n";
                        // ans += all[i][j];
                    }
                }
            }
        }
        // cout<<ans;
        cout<<'\n';
        
    }
}