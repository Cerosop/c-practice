#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        int ans = 1, test = 1;
        while(true){
            test %= n;
            if(test == 0)
                break;
            test *= 10;
            test++;
            ans++;
        }
        cout<<ans<<"\n";
    }
}