#include<bits/stdc++.h>
using namespace std;
int main(){
    double l = 3000;
    int count = 0;
    while(l >= 5){
        l /= 2.0;
        count++;
    }
    cout<<count;
}