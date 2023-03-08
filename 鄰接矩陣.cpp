#include<bits/stdc++.h>
using namespace std;
int main(){
    int x, n;
    cin>>x>>n;
    int pic[x][x];
    memset(pic, 0, sizeof pic);
    while(n--){
        int a, b, v;
        cin>>a>>b>>v;
        pic[a][b] = v;
    }
    for(int i = 0; i < x; i++){
        for(int j = 0; j < x; j++)
            cout<<pic[i][j]<<" ";
        cout<<"\n";
    }
}
