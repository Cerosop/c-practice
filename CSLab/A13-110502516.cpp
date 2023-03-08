/*
* Assignment 13
* Name: 許尚軒
* Student Number: 110502516
* Course 2021-CE1003-A
*/
#include<bits/stdc++.h>
using namespace std;

int arr[9][9], x;
ifstream ifs;

void is_sudo(int n){
    for(int k = 0; k < 9; k++){
        int check[9] = {};
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(check[arr[(k / 3) * 3 + i][(k % 3) * 3 + j] - 1]){
                    x = 0;
                    break;
                }
                else
                    check[arr[(k / 3) * 3 + i][(k % 3) * 3 + j] - 1] = 1;
            }
            if(!x)
                break;
        }
        if(!x)
            break;
    }
    if(x){
        for(int i = 0; i < 9; i++){
            int check[9] = {};
            for(int j = 0; j < 9; j++){
                if(check[arr[i][j] - 1]){
                    x = 0;
                    break;
                }
                else
                    check[arr[i][j] - 1] = 1;
            }
            if(!x)
                break;
        }
    }
    if(x){
        for(int i = 0; i < 9; i++){
            int check[9] = {};
            for(int j = 0; j < 9; j++){
                if(check[arr[j][i] - 1]){
                    x = 0;
                    break;
                }
                else
                    check[arr[j][i] - 1] = 1;
            }
            if(!x)
                break;
        }
    }
    if(x)
        cout<<"sudo"<<n<<":Y\n";
    else
        cout<<"sudo"<<n<<":N\n";
}

void prog(int n){
    int j = 0;
    string s;
    while(getline(ifs, s)){
        int i = 0;
        for(auto c : s){
            if(c != ' ' and c != '\n'){
                arr[j][i] = c - '0';
                i++;
            }
        }
        j++;
    }
    ifs.close();
    x = 1;
    is_sudo(n);
}

int main(){
    ifs.open("sudo1.txt");
    prog(1);
    ifs.open("sudo2.txt");
    prog(2);
    ifs.open("sudo3.txt");
    prog(3);
}
