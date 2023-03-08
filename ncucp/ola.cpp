#include<bits/stdc++.h>
using namespace std;

vector<int> graph[1000005];
int in[1000005], out[1000005], c, n, en, si;
set<int> s;
queue<int> q;

void dfs(int a){
    if(graph[a].empty()){
        if(!en)
            en = a;
        else if (a == si)
            si = 0;
        return;
    }

    int x = graph[a].back();
    graph[a].pop_back();
    out[a]--;
    dfs(x);
    if(!si){
        q.push(a);
        c++;
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i = 0, a; i < n; i++){
            cin>>a;
            q.push(a);
            s.insert(a);
            out[a]++;
        }
        for(int i = 0, a, b; i < n; i++){
            cin>>b;
            a = q.front();
            q.pop();
            s.insert(b);
            in[b]++;
            graph[a].push_back(b);
        }

        int sta = 0, sta2 = 1e9;
        for(auto x:s){
            if(out[x] == in[x])
                sta2 = min(sta2, x);
            if(out[x] - in[x] == 1){
                sta = x;
                break;
            }
        }
        if(!sta){
            if(sta2 != 1e9)
                sta = sta2;
            else{
                cout<<-1<<"\n";
                for(auto x:s){
                    in[x] = 0;
                    out[x] = 0;
                    graph[x].clear();
                }
                s.clear();
                continue;
            }
        }

        c = 0;
        en = 0;
        si = 0;
        dfs(sta);
        while(!q.empty()){
            int x = q.front();
            q.pop();
            if(out[x]){
                si = x;
                dfs(x);
            }
        }

        if(en and c == n)
            cout<<sta<<" "<<en<<"\n";
        else 
            cout<<-1<<"\n";
        for(auto x:s){
            in[x] = 0;
            out[x] = 0;
            graph[x].clear();
        }
        s.clear();
    }
}