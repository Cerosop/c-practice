/*
* Assignment 9
* Name: ³\©|°a
* Student Number: 110502516
* Course 2021-CE1003-A
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[3];
    cout<<"Firsr:\n";
    cin>>a[0];
    cout<<"Second:\n";
    cin>>a[1];
    cout<<"Third:\n";
    cin>>a[2];
    sort(a, a + 3);
    if(a[0] + a[1] <= a[2])
        cout<<"Not triangle\n";
    else{
        if(a[0] == a[1]){
            if(a[0] * a[0] + a[1] * a[1] == a[2] * a[2])
                cout<<"Isosceles right triangle\n";
            else if(a[1] == a[2])
                cout<<"Regular triangle\n";
            else
                cout<<"Isosceles triangle\n";
        }
        else if(a[1] == a[2])
            cout<<"Isosceles triangle\n";
        else{
            if(a[0] * a[0] + a[1] * a[1] == a[2] * a[2])
                cout<<"Right triangle\n";
            else
                cout<<"Triangle\n";
        }
    }
}
