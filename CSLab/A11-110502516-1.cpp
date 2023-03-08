/*
* Assignment 11
* Name: 許尚軒
* Student Number: 110502516
* Course 2021-CE1003-A
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    while(1){
        int n;
        cout<<"Input Size:";
        cin>>n;
        if(n == -1)
            break;
        int a[n][n];
        for(int i = 0;i < n; i++){
            for(int j = 0; j < n; j++)
                cin>>a[i][j];
        }
        int x = 1;
        for(int i = 0;i < (n + 1) / 2; i++){
            for(int j = 0; j < n; j++)
                if(a[i][j] != a[n - i - 1][n - j - 1]){
                    x = 0;
                    break;
                }
        }
        if(x)
            cout<<"Symmetric!\n";
        else
            cout<<"Non-Symmetric!\n";
    }
}
