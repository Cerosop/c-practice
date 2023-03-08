#include<bits/stdc++.h>
using namespace std;
struct node{
    int point, weight;
    node *next = NULL;
};
int main(){
    // freopen("test.txt", "r", stdin);
    // freopen("testw.txt", "w", stdout);
    int n;
    cin>>n;
    while(n--){
        int n1, n2;
        cin>>n1>>n2;
        node *adjlist[n1 + 1];
        node *adjlist2[n1 + 1];
        node *nowpo[n1 + 1];
        node *nowpo2[n1 + 1];
        for(int i = 1; i <= n1; i++){
            adjlist[i] = new node;
            nowpo[i] = adjlist[i];
            adjlist2[i] = new node;
            nowpo2[i] = adjlist2[i];
        }
        while(n2--){
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
            nowpo2[b]->next = bn;
            nowpo2[b] = nowpo2[b]->next;
        }
        queue<int> q;
        q.push(1);
        int key[n1 + 1];
        for(int i = 2; i <= n1; i++){
            key[i] = INT_MAX;
        }
        key[1] = 0;
        while(!q.empty()){
            int now = q.front();
            q.pop();
            nowpo[now] = adjlist[now]->next;
            while(nowpo[now]){
                if(key[now] + nowpo[now]->weight < key[nowpo[now]->point]){
                    key[nowpo[now]->point] = key[now] + nowpo[now]->weight;
                    q.push(nowpo[now]->point);
                }
                nowpo[now] = nowpo[now]->next;
            }
        }
        int ans = 0;
        for(int i = 2; i <= n1; i++){
            ans += key[i];
        }
        for(int i = 2; i <= n1; i++){
            key[i] = INT_MAX;
        }
        key[1] = 0;
        q.push(1);
        while(!q.empty()){
            int now = q.front();
            q.pop();
            nowpo2[now] = adjlist2[now]->next;
            while(nowpo2[now]){
                if(key[now] + nowpo2[now]->weight < key[nowpo2[now]->point]){
                    key[nowpo2[now]->point] = key[now] + nowpo2[now]->weight;
                    q.push(nowpo2[now]->point);
                }
                nowpo2[now] = nowpo2[now]->next;
            }
        }
        for(int i = 2; i <= n1; i++){
            ans += key[i];
        }
        cout<<ans<<"\n";
    }
}