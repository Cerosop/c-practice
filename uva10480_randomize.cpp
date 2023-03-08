#include<bits/stdc++.h>
using namespace std;
struct edge{
    int c1, c2, w;
};

int an[51], n;
vector<edge> v;
vector<edge> ans_v;

int get_an(int a){ //算祖先
    if(an[a] == a)
        return a;
    an[a] = get_an(an[a]);
    return an[a];
}

int main(){
    // freopen("test.txt", "r", stdin);
    // freopen("testw.txt", "w", stdout);
    int m;
    srand(time(NULL));
    while(cin>>n>>m){
        if(!n && !m)
            break;
        
        v.clear();
        while(m--){
            int a, b, w;
            cin>>a>>b>>w;
            edge *newedge = new edge;
            newedge->c1 = a;
            newedge->c2 = b;
            newedge->w = w;
            v.push_back(*newedge);
        }
        int ans_min = INT_MAX;
        
        for(int k = 0; k < 10000; k++){ //跑10000次
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
                // cout<<x<<"a\n";
                x %= tmp.size();
                if(get_an(tmp[x].c1) == get_an(tmp[x].c2)){ //自己走到自己
                    swap(*(tmp.end() - 1), *(tmp.begin() + x));
                    tmp.pop_back();
                    continue;
                }
                if(get_an(tmp[x].c1) == get_an(1) && get_an(2) == get_an(tmp[x].c2)){ //要融合的集合包刮1 2
                    anstmp.push_back(tmp[x]);
                    swap(*(tmp.end() - 1), *(tmp.begin() + x));
                    tmp.pop_back();
                    continue;
                }
                if(get_an(tmp[x].c1) == get_an(2) && get_an(1) == get_an(tmp[x].c2)){
                    anstmp.push_back(tmp[x]);
                    swap(*(tmp.end() - 1), *(tmp.begin() + x));
                    tmp.pop_back();
                    continue;
                }
                an[an[tmp[x].c2]] = an[tmp[x].c1];
                count++;
                swap(*(tmp.end() - 1), *(tmp.begin() + x));
                tmp.pop_back();
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
            if(ans_min > ans){
                ans_min = ans;
                ans_v = anstmp;
            }
        }
        // cout<<ans_min<<"\n";
        for(int i = 0; i < ans_v.size(); i++){
            cout<<ans_v[i].c1<<" "<<ans_v[i].c2<<"\n";
        }

        cout<<'\n';
        
    }
}