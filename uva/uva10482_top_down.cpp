#include<bits/stdc++.h>
using namespace std;
int candies[205], precan[205], m;
struct dp{
    short w, i;
};

dp diff[20005][20005];
int solve(int index, int c1, int c2){
    if(index >= m)  return(c1 - c2);
    if(diff[c1][c2].w != -1 && index >= diff[c1][c2].i)  return diff[c1][c2].w;
    int c3 = precan[index] - c1 - c2;
    if(diff[c1][c2].i > index)
        diff[c1][c2].i = index;
    diff[c1][c2].w = min({solve(index + 1, max({c1, c2 + candies[index], c3}), min({c1, c2 + candies[index], c3}))
                    , solve(index + 1, max({c1, c2, c3 + candies[index]}), min({c1, c2, c3 + candies[index]}))
                    , solve(index + 1, max({c1 + candies[index], c2, c3}), min({c1 + candies[index], c2, c3}))});
    return diff[c1][c2].w;
}

int main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>m;
        precan[0] = 0;
        for(int j = 0; j < m; j++){
            cin>>candies[j];
            precan[j + 1] = precan[j] + candies[j];
        }
        for(int a = 0; a < precan[m] + 1; a++){
            for(int b = 0; b < precan[m] + 1; b++){
                diff[a][b].i = 1000;
                diff[a][b].w = -1;
            }
                
        }
        cout<<"Case "<<i<<": "<<solve(0, 0, 0)<<"\n";
    }
}