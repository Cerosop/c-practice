/*
* Assignment 14
* Name: 許尚軒
* Student Number: 110502516
* Course 2021-CE1003-A
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    string n;
    while(cin>>n){
        int x = 0;
        if(n == "-1")
            break;
        for(int i = 2; i <= 62; i++){
            int count1 = 0;
            for(int j = 0; j < n.size(); j++){
                if((n[n.size() - j - 1]) - ('0') <= 9){
                    if(n[n.size() - j - 1] - '0' >= i){
                        i = n[n.size() - j - 1] - '0';
                        count1 = -1;
                        break;
                    }
                    count1 += (n[n.size() - j - 1] - '0') * pow(i, j);
                }
                else if(n[n.size() - j - 1] - 'A' <= 25){
                    if(n[n.size() - j - 1] - 'A' + 10 >= i){
                        i = n[n.size() - j - 1] - 'A' + 10;
                        count1 = -1;
                        break;
                    }
                    count1 += (n[n.size() - j - 1] - 'A' + 10) * pow(i, j);
                }
                else{
                    if(n[n.size() - j - 1] - 'a' + 36 >= i){
                        i = n[n.size() - j - 1] - 'a' + 36;
                        count1 = -1;
                        break;
                    }
                    count1 += (n[n.size() - j - 1] - 'a' + 36) * pow(i, j);
                }
            }
            if(count1 % (i - 1) == 0){
                cout<<i<<"\n";
                x = 1;
                break;
            }
        }
        if(!x)
            cout<<"such number is impossible!\n";
    }
}
