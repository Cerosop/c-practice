/*
* Practice 11
* Name: 許尚軒
* Student Number: 110502516
* Course 2021-CE1003-A
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    while(1){
        int n;
        cin>>n;
        if(n == -1)
            break;
        set<char> ans;
        while(n--){
            char a;
            cin>>a;
            ans.insert(a);
        }
        for(auto x : ans)
            cout<<x<<" ";
        cout<<"\n";
        char c;
        cin>>c;
        if(ans.count(c)){
            int i = 0;
            for(auto x : ans){
                if(x == c){
                    cout<<i<<"\n";
                    break;
                }
                i++;
            }
        }
        else
            cout<<"-1\n";
        cout<<"\n";
    }
}
