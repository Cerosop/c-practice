/*
* Practice 9
* Name: 許尚軒
* Student Number: 110502516
* Course 2021-CE1003-A
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    getline(cin, s);
    while(n--){
        getline(cin, s);
        if(s == ""){
            cout<<"\n";
            continue;
        }
        cout<<s[0];
        int x = 1;
        for(int i = 1; i < s.size(); i++){
            if(s[i] == s[i - 1]){
                x++;
            }
            else{
                cout<<x<<s[i];
                x = 1;
            }
        }
        cout<<x<<"\n";
    }
}
