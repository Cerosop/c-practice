#include<bits/stdc++.h>
using namespace std;
struct route
{
    int a, b, v;
};

bool cmp(route a, route b){
    return a.v < b.v;
}
vector<route> spintree[3001];
bool xfind[3001];
int grand[3001];

int dt(int a){
    if(grand[a] == a){
        return a;
    }
    grand[a] = dt(grand[a]);
    return grand[a];
}

int find(int s, int e){
    for(int i = 0; i < spintree[s].size(); i++){
        if(!xfind[spintree[s][i].b]){
            if(spintree[s][i].b == e){
                return spintree[s][i].v;
            }
            xfind[spintree[s][i].b] = true;
            int ifindlast = find(spintree[s][i].b, e);
            if(ifindlast != -1){
                return max(ifindlast, spintree[s][i].v);
            }
        }
        
    }
    return -1;
}

int main(){
    // freopen("test.txt", "r", stdin);
    // freopen("testw.txt", "w", stdout);
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int k = 1; k <= n; k++){
        int n1, n2;
        cin>>n1>>n2;
        vector<route> graph;
        for(int i = 1; i <= n1; i++){
                spintree[i].clear();
        }
        while(n2--){
            route newroute;
            cin>>newroute.a>>newroute.b>>newroute.v;
            graph.push_back(newroute);

        }
        sort(graph.begin(), graph.end(), cmp);
        int rank[n + 1] = {0};
        for(int i = 1; i <= n1; i++){
            grand[i] = i;
        }
        int count = 1;
        for(int i = 0; i < graph.size(); i++){
            if(dt(graph[i].a) != dt(graph[i].b)){
                count++;
                spintree[graph[i].a].push_back(graph[i]);
                route tmp;
                tmp.a = graph[i].b;
                tmp.b = graph[i].a;
                tmp.v = graph[i].v;
                spintree[graph[i].b].push_back(tmp);

                grand[dt(graph[i].a)] = dt(graph[i].b);

                // if(rank[graph[i].a] > rank[graph[i].b])
                //     grand[graph[i].b] = graph[i].a;
                // else if(rank[graph[i].a] < rank[graph[i].b])
                //     grand[graph[i].a] = graph[i].b;
                // else{
                //     grand[graph[i].a] = graph[i].b;
                //     rank[graph[i].b]++;
                // }
                if(count == n1)
                    break;
            }
        }
        int n3;
        cin>>n3;
        cout<<"Case "<<k<<"\n";
        while(n3--){
            int s, e;
            cin>>s>>e;
            xfind[n1 + 1] = {false};
            for(int i = 1; i <= n1; i++)
                xfind[i] = false;
            xfind[s] = true;
            cout<<find(s, e)<<"\n";
        }
        cout<<"\n";
    }
}