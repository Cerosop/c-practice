/*
* Assignment 10
* Name: 許尚軒
* Student Number: 110502516
* Course 2021-CE1003-A
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int l = 0;
    string stack1 = "";
    while(1){
        string s;
        cin>>s;
        if(s == "push"){
            char c;
            cin>>c;
            stack1 += c;
            l++;
        }
        else if(s == "pop"){
            if(!l)
                cout<<"empty\n";
            else{
                cout<<stack1[l - 1]<<"\n";
                stack1 = stack1.substr(0, --l);
            }
        }
        else if(s == "list"){
            for(auto c : stack1)
                cout<<c<<" ";
            cout<<"\n";
        }
        else
            break;
    }
}
