#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream in("input.txt");       //�ŧiin��ifstream����ÿ�Jinput.txt
    ofstream out("output.txt");     //�ŧiout��ofstream����ÿ�Joutput.txt
    string s;
    while (getline(in, s)){         //�Ninput.txt���C�@�檺��r��J�r��s
        out<<s<<endl;               //�N�r��s��Joutput.txt��
    }
}
