#include<bits/stdc++.h>
using namespace std;

vector<int> graph[10000];
vector<int> ans;
int instamp[10000] = {}, outstamp[10000] = {}, stamp = 0;

void dfs(int i){
    if(!instamp[i]){
        instamp[i] = stamp++;
        ans.push_back(i);
        cout<<i<<" in: "<<instamp[i]<<"\n";
        for(auto j : graph[i]){
            dfs(j);
        }
        outstamp[i] = stamp++;
        cout<<i<<" out: "<<outstamp[i]<<"\n";
    }
}

int main(){
    int n;
    cin>>n;
    while(n--){
        int a, b;
        cin>>a>>b;
        graph[a].push_back(b);
    }
    dfs(0);
    for(auto y : ans){
        cout<<y<<" ";
    }
}
