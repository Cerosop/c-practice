#include<bits/stdc++.h>
using namespace std;
bool candy[100005], visited[100005];
vector<int> graph[100005];
int dp[100005], maans = 0, mians = 1e9, n;

// void dfs(int a){
//     for(auto x:graph[a]){
//         if(dp[x] < dp[a] + (!visited[x] and candy[x])){
//             int tmp = dp[x];
//             bool tmpb = visited[x];
//             dp[x] = dp[a] + (!visited[x] and candy[x]);
//             visited[x] = true;
//             if(x == n){
//                 maans = max(maans, dp[x]);
//             }
//             dfs(x);
//             dp[x] = tmp;
//             visited[x] = tmpb;
//         }
//     }
// }

// void dfsmin(int a){
//     for(auto x:graph[a]){
//         if(dp[x] > dp[a] + (!visited[x] and candy[x])){
//             int tmp = dp[x];
//             bool tmpb = visited[x];
//             dp[x] = dp[a] + (!visited[x] and candy[x]);
//             visited[x] = true;
//             if(x == n){
//                 mians = min(mians, dp[x]);
//             }
//             dfsmin(x);
//             dp[x] = tmp;
//             visited[x] = tmpb;
//         }
//     }
// }

int main(){
    int c, m;
    cin>>n>>c>>m;
    while(c--){
        int tmp;
        cin>>tmp;
        candy[tmp] = true;
    }
    while(m--){
        int a, b;
        cin>>a>>b;
        graph[a].push_back(b);
    }
    
    for(int i = 2; i <= n; i++){
        dp[i] = -1;
        // visited[i] = false;
    }
    dp[1] = 0;
    if(candy[1]){
        dp[1] = 1;
    }
    // visited[1] = true; 
    // dfs(1);

    

    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(auto x:graph[now]){
            if(dp[x] < dp[now] + (!visited[x] and candy[x])){
                dp[x] = dp[now] + (!visited[x] and candy[x]);
                q.push(x);
            }
        }
    }
    maans = dp[n];

    for(int i = 2; i <= n; i++){
        dp[i] = 1e9;
        // visited[i] = false;
    }
    dp[1] = 0;
    if(candy[1]){
        dp[1] = 1;
    }
    // visited[1] = true;
    // dfsmin(1);

    
    q.push(1);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(auto x:graph[now]){
            if(dp[x] > dp[now] + (!visited[x] and candy[x])){
                dp[x] = dp[now] + (!visited[x] and candy[x]);
                q.push(x);
            }
        }
    }
    mians = dp[n];

    cout<<mians<<" "<<maans;
}