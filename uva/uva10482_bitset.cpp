#include<bits/stdc++.h>
using namespace std;
const int maxn = 20001;
bitset<maxn> dp[maxn];
int main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        int m;
        cin>>m;
        int weight[m], sum = 0;
        for(int j = 0; j <= maxn; j++)
            dp[j].reset();
        dp[0][0] = 1;
        for(int j = 0; j < m; j++){
            cin>>weight[j];
            sum += weight[j];
            for(int a = sum; a >= 0; a--){
                if(a + weight[j] <= sum)
                    dp[a + weight[j]] |= dp[a];
                dp[a] |= (dp[a] << weight[j]);
            }
        }
        int ans = INT_MAX;
        for(int a = 0; a <= sum; a++){
            for(int b = 0; b <= sum; b++){
                if(dp[a][b]){
                    int c = sum - a - b;
                    ans = min(ans, max({a, b, c}) - min({a, b, c}));
                }
            }
        }
        cout<<"Case "<<i<<": "<<ans<<"\n";
    }
}