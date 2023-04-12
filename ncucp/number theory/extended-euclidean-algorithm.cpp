#include<bits/stdc++.h>
using namespace std;

vector<int> gragh[40005];
int MOD = 1e9 + 7, point[40005];
long long int fact[40005], refact[40005], n_route[40005];

long long int cal_refact(long long int a, int b){
    long long int ref = 1;
    while(b){
        if(b & 1)
            ref = ref * a % MOD;
        a = a * a % MOD;
        b = b>>1;
    }
    return ref;
}

void dfs(int a){
    for(auto x:gragh[a]){
        dfs(x);
        point[a] += point[x] + 1;
    }

    n_route[a] = fact[point[a]];
    for(auto x:gragh[a])
        n_route[a] = n_route[a] * refact[point[x] + 1] % MOD * n_route[x] % MOD;
}

int main(){
    fact[0] = 1;
    for(long long int i = 1; i < 40005; i++){
        fact[i] = fact[i - 1] * i % MOD;
    }

    refact[40004] = cal_refact(fact[40004], MOD - 2);
    for(long long int i = 40003; i >= 0; i--){
        refact[i] = refact[i + 1] * (i + 1) % MOD;
    }

    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        
        int check[n + 1];
        for(int i = 0; i <= n; i++){
            gragh[i].clear();
            check[i] = 0;
            point[i] = 0;
            n_route[i] = 1;
        }

        while(m--){
            int a, b;
            cin>>a>>b;
            gragh[b].push_back(a);
            check[a]++;
        }

        for(int i = 1; i <= n; i++){
            if(!check[i])
                dfs(i);
        }

        int nowpoint = -1;
        long long int nown_route;
        for(int i = 1; i <= n; i++){
            if(!check[i]){
                if(nowpoint == -1){
                    nowpoint = point[i];
                    nown_route = n_route[i];
                    continue;
                }
                nown_route = fact[nowpoint + point[i] + 2] * refact[point[i] + 1] % MOD * refact[nowpoint + 1] % MOD * n_route[i] % MOD * nown_route % MOD;
                nowpoint += point[i] + 1;
            }
        }

        cout<<nown_route<<"\n";
    }
}