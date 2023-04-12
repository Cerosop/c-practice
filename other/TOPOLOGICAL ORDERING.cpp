#include<bits/stdc++.h>
using namespace std;

vector<int> gra[10];
int deg[10] = {}, usi[10] = {};
vector<int> ans;

void topo(int x, int n){
    if(x == n){
        for(auto c : ans)
            cout<<c;
        cout<<"\n";
        return;
    }
    for(int i = 0; i < n; i++){
        if(deg[i] == 0 and usi[i] == 0){
            ans.push_back(i);
            usi[i] = 1;
            for(auto s : gra[i])
                deg[s]--;
            topo(x + 1, n);
            ans.pop_back();
             for(auto s : gra[i])
                deg[s]++;
            usi[i] = 0;
        }
    }
}

int main(){
    int n, m;
    cin>>n>>m;
    while(m--){
        int a, b;
        cin>>a>>b;
        gra[a].push_back(b);
        deg[b]++;
    }
    topo(0, n);
}
