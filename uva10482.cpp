#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        int m;
        cin>>m;
        int weight[m] = {}, sum = 0;
        for(int j = 0; j < m; j++){
            cin>>weight[j];
            sum += weight[j];
        }
        int ans = sum + 1;;
        short dp[sum + 1][sum + 1];
        for(int a = 0; a < sum + 1; a++){
            for(int b = 0; b < sum + 1; b++)
                dp[a][b] = -1;
        }
        dp[0][0] = sum;
        for(int j = 0; j < m; j++){
            for(int a = sum; a >= 0; a--){
                for(int b = sum; b >= 0; b--){
                    if(dp[a][b] != -1){
                        dp[a + weight[j]][b] = max(max(a + weight[j], b), sum - a - b - weight[j]) - min(min(a + weight[j], b), sum - a - b - weight[j]);
                        dp[a][b + weight[j]] = max(max(b + weight[j], a), sum - a - b - weight[j]) - min(min(b + weight[j], a), sum - a - b - weight[j]);
                        if(dp[a + weight[j]][b] < dp[a][b + weight[j]]){
                            if(ans > dp[a + weight[j]][b])
                                ans = dp[a + weight[j]][b];
                        }
                        else if(ans > dp[a][b + weight[j]])
                            ans = dp[a][b + weight[j]];
                    }
                }
            }
        }
        cout<<"Case "<<i<<": "<<ans<<"\n";
    }
}