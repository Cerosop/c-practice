/*
* Assignment 9
* Name: �\�|�a
* Student Number: 110502516
* Course 2021-CE1003-A
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a1, a2, b1, b2;
    cout<<"A size = ";
    cin>>a1>>a2;
    cout<<"B size = ";
    cin>>b1>>b2;
    if(a2 != b1)
        cout<<"Can't be multiplied";
    else{
        int a[a2][a1], b[b2][b1], ans[b2][a1];
        for(int i = 0; i < b2; i++){
            for(int j = 0; j < a1; j++)
                ans[i][j] = 0;
        }
        cout<<"A:\n";
        for(int i = 0; i < a1; i++){
            for(int j = 0; j < a2; j++)
                cin>>a[j][i];
        }
        cout<<"B:\n";
        for(int i = 0; i < b1; i++){
            for(int j = 0; j < b2; j++)
                cin>>b[j][i];
        }
        for(int i = 0; i < a1; i++){
            for(int j = 0; j < b2; j++)
                for(int k = 0; k < a2; k++)
                    ans[j][i] += a[k][i] * b[j][k];
        }
        cout<<"Multiplication:\n";
        for(int i = 0; i < a1; i++){
            for(int j = 0; j < b2; j++)
                cout<<ans[j][i]<<" ";
            cout<<"\n";
        }
    }
}
