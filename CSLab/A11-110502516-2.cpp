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
        string s;
        cin>>s;
        if(s == "-1")
            break;
        int len = 0;
        string ans;
        for(int i = 0; i < s.size() / 2; i++){
            for(int j = s.size() - 1; j >= 0; j--){
                if(s[i] == s[j]){
                    int x = 1;
                    for(int k = i + 1; k < (i + j + 1) / 2; k++){
                        if(s[k] != s[j - k + i]){
                            x = 0;
                            break;
                        }
                    }
                    if(x && (j - i + 1) > len){
                        ans = s.substr(i, j - i + 1);
                        len = j - i + 1;
                        break;
                    }
                }
            }
        }
        if(len > 1)
            cout<<"Palindrome:"<<ans<<"\nLength:"<<len<<"\n\n";
        else
            cout<<"Palindrome not existed!\n\n";
    }
}
