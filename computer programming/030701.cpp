#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, ans = 0;
    cin>>n;
    if(!n % 2){
        cout<<"input error";
        return 0;
    }
    for(int i = 1; i <= n; i += 2){
        ans += i;
    }
    cout<<ans;
}