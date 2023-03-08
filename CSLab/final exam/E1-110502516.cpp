/*
* Exam 1
* Name: 許尚軒
* Student Number: 110502516
* Course 2021-CE1003-A
*/
#include<bits/stdc++.h>
using namespace std;

ofstream outfile("110502516.txt",ios::out);
int i = 0;
void hanoi(int n, char f, char l){
    if(n == 1){
        outfile<<f<<l<<"\n";
        cout<<f<<l<<"\n";
    }
    else{
        i++;
        char c = 3 - ((f - 'A') + (l - 'A')) + 'A';
        hanoi(n - 1, f, c);
        //cout<<i<<" ";
        hanoi(1, f, l);
        //cout<<i<<" ";
        hanoi(n - 1, c, l);
        //cout<<i<<" ";
    }
}

int main(){
    ifstream infile("N.txt", ios::in);

    char n_str;
    infile>>n_str;
    int n = int(n_str) - int('0');
    hanoi(n, 'A', 'C');
}
