#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream in("input.txt");       //宣告in為ifstream物件並輸入input.txt
    ofstream out("output.txt");     //宣告out為ofstream物件並輸入output.txt
    string s;
    while (getline(in, s)){         //將input.txt中每一行的文字輸入字串s
        out<<s<<endl;               //將字串s輸入output.txt中
    }
}
