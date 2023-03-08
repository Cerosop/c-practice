/*
* Practice 10
* Name: ³\©|°a
* Student Number: 110502516
* Course 2021-CE1003-A
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    while(1){
        cin>>s;
        if(s == "-1")
            break;
        int x = 1;
        for(int i = 0; i < ((s.size() + 1) / 2); i++){
            if(s[i] != s[s.size() - i -1]){
                x = 0;
                break;
            }
        }
        if(x)
            cout<<"Palindrome!\n";
        else
            cout<<"Not Palindrome!\n";
    }
}
