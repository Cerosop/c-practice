#include<bits/stdc++.h>
using namespace std;
struct edge{
    int c1, c2, w;
};
vector<edge> v;
int flow[1001], parent[1001], n, remain[1001][1001], all[1001][1001];
int an[1001];

int get_an(int a){ //算祖先
    if(an[a] == a)
        return a;
    an[a] = get_an(an[a]);
    return an[a];
}

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
    
    // int m = 500;
    n = 50;
    srand(time(NULL));
    // int p = 100;
    // while(p--){
    int correct = 0;
    for(int u = 0; u < 1000; u++){
        v.clear();
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                remain[i][j] = 0;
                all[i][j] = 0;
            }
        }
        for(int a = 1; a <= n; a++){
            for(int b = a; b <= n; b++){
                int x = rand();
                if(!(x % 5)){
                    int w = rand() % 100;
                    remain[a][b] = w;
                    remain[b][a] = w;
                    all[a][b] = w;
                    all[b][a] = w;
                    edge *newedge = new edge;
                    newedge->c1 = a;
                    newedge->c2 = b;
                    newedge->w = w;
                    v.push_back(*newedge);
                }
                
            }
        }
        // cout<<"a\n;";  
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
        int tans = 0;
        for(int i = 1; i <= n; i++){
            if(flow[i] > 0){
                for(int j = 1; j <= n; j++){
                    if(flow[j] == 0 && all[i][j] != 0){
                        // cout<<i<<" "<<j<<"\n";
                        tans += all[i][j];
                    }
                }
            }
        }
        // cout<<tans<<"\n";
        // cout<<"a\n;";  
            // cout<<ans;
            // cout<<'\n';
        // }
        
        for(int k = 0; k < 1000; k++){ //跑10000次
            int ansmin = INT_MAX;
            for(int l = 0; l < n; l++){
                for(int i = 0; i <= n; i++){
                    an[i] = i;
                }
                vector<edge> tmp = v; //做計算的vector
                vector<edge> anstmp; //存這次答案的vector
                anstmp.clear();
                int count = 0;
                
                while(1){
                    if(count >= n - 2 || !tmp.size())
                        break;
                    
                    int x = rand();
                    x %= tmp.size();
                    if(get_an(tmp[x].c1) == get_an(tmp[x].c2)){ //自己走到自己
                        swap(*(tmp.end() - 1), *(tmp.begin() + x));
                        tmp.pop_back();
                        // tmp.erase(tmp.begin() + x);
                        continue;
                    }
                    if(get_an(tmp[x].c1) == get_an(1) && get_an(2) == get_an(tmp[x].c2)){ //要融合的集合包刮1 2
                        anstmp.push_back(tmp[x]);
                        swap(*(tmp.end() - 1), *(tmp.begin() + x));
                        tmp.pop_back();
                        // tmp.erase(tmp.begin() + x);
                        continue;
                    }
                    if(get_an(tmp[x].c1) == get_an(2) && get_an(1) == get_an(tmp[x].c2)){
                        anstmp.push_back(tmp[x]);
                        swap(*(tmp.end() - 1), *(tmp.begin() + x));
                        tmp.pop_back();
                        // tmp.erase(tmp.begin() + x);
                        continue;
                    }
                    an[an[tmp[x].c2]] = an[tmp[x].c1];
                    count++;
                    swap(*(tmp.end() - 1), *(tmp.begin() + x));
                    tmp.pop_back();
                    // tmp.erase(tmp.begin() + x);
                }
                int ans = 0;
                for(int i = 0; i < tmp.size(); i++){
                    if(get_an(tmp[i].c1) != get_an(tmp[i].c2)){
                        anstmp.push_back(tmp[i]);
                    } 
                }
                for(int i = 0; i < anstmp.size(); i++){
                    ans += anstmp[i].w;
                }
                ansmin = min(ans, ansmin);
            }
            
            // cout<<ans<<"\n";
            if(ansmin == tans){
                correct++;
            }
        }
    }
    
    cout<<double(correct) / 1000000.0;
}