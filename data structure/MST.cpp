#include<bits/stdc++.h>
using namespace std;
struct node{
    int point, weight;
    node *next = NULL;
};

int main(){
    int n, m;
    cin>>n>>m;
    node *adjlist[n];
    node *nowpo[n];
    for(int i = 0; i < n; i++){
        adjlist[i] = new node;
        nowpo[i] = adjlist[i];
    }
    while(m--){
        int a, b, w;
        cin>>a>>b>>w;
        node *an = new node;
        an->point = b;
        an->weight = w;
        nowpo[a]->next = an;
        nowpo[a] = nowpo[a]->next;

        node *bn = new node;
        bn->point = a;
        bn->weight = w;
        nowpo[b]->next = bn;
        nowpo[b] = nowpo[b]->next;

    }
    bool visited[n] = {false};
    int key[n], ans = 0;
    
    for(int i = 0; i < n; i++){
        visited[i] = false;
        key[i] = INT_MAX;
    }
    key[0] = 0;
    for(int i = 0; i < n; i++){
        int mi = INT_MAX, mipos = -1;
        for(int j = 0; j < n; j++){
            if(!visited[j]){
                if(key[j] != INT_MAX && mi > key[j]){
                    mi = key[j];
                    mipos = j;
                }
            }
        } 
        ans += mi;
        visited[mipos] = true;
        nowpo[mipos] = adjlist[mipos]->next;
        while(nowpo[mipos]){
            if(key[nowpo[mipos]->point] > nowpo[mipos]->weight)
                key[nowpo[mipos]->point] = nowpo[mipos]->weight;
            nowpo[mipos] = nowpo[mipos]->next;
        }
    }
    cout<<ans;
}