#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int arr[51][51][51];
    for(int i = 1; i < 51; i++){
        for(int j = 0; j < 51; j++){
            arr[i][0][j] = 0;
            arr[0][i][j] = 0;
        }
    }
    for(int j = 1; j < 51; j++)
        arr[0][0][j] = 1;
    arr[0][0][0] = 0;
    for(int i = 1; i < 51; i++){
        for(int j = 1; j < 51; j++){
            for(int m = 1; m < 51; m++){
                arr[i][j][m] = 0;
                for(int k = 1 ; k <= min(i, m); k++)
                    arr[i][j][m] += arr[i - k][j - 1][m];
            }
        }
    }
    int a, b, c;
    while(cin>>a>>b>>c)
        cout<<arr[a][b][c]<<"\n";
}
