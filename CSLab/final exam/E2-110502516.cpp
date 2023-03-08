/*
* Exam 2
* Name: 許尚軒
* Student Number: 110502516
* Course 2021-CE1003-A
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    ifstream infile("input.txt", ios::in);
    ofstream outfile("output.txt", ios::out);
    string s;
    getline(infile, s);
    cout<<int(' ')<<"\n";
    for(int i = 0; i <= (s.size() / 3); i++){
        char c1 = ' ', c2 = ' ', c3 = ' ', c4 = ' ';
        int a, b = 0, c = 0;
        a = int(s[i * 3]);
        if(i * 3 + 1 < s.size()){
            b = int(s[i * 3 + 1]);
            if(i * 3 + 2 < s.size())
                c = int(s[i * 3 + 2]);
            else
                c4 = '=';
        }
        else{
            c3 = '=';
            c4 = '=';
        }
       // cout<<c1<<c2<<c3<<c4<<" ";
        int ans1 = a / 4, ans2 = ((a % 4) * 16) + (b / 16), ans3 = ((b % 16) * 4) + (c / 64), ans4 = c % 64;
      // cout<<ans1<<" "<<ans2<<" "<<ans3<<" "<<ans4<<" ";
        if(ans1 < 26)
            c1 = ans1 + 'A';
        else if(ans1 < 52)
            c1 = ans1 - 26 + 'a';
        else if(ans1 < 62)
            c1 = ans1 - 52 + '0';
        else if(ans1 == 62)
            c1 = '+';
        else
            c1 = '/';
        if(ans2 < 26)
            c2 = ans2 + 'A';
        else if(ans2 < 52)
            c2 = ans2 - 26 + 'a';
        else if(ans2 < 62)
            c2 = ans2 - 52 + '0';
        else if(ans2 == 62)
            c2 = '+';
        else
            c2 = '/';
        if(c3 != '='){
            if(ans3 < 26)
                c3 = ans3 + 'A';
            else if(ans3 < 52)
                c3 = ans3 - 26 + 'a';
            else if(ans3 < 62){
                c3 = ans3 - 52 + '0';
            }

            else if(ans3 == 62)
                c3 = '+';
            else
                c3 = '/';
        }
        if(c4 != '='){
            if(ans4 < 26)
                c4 = ans4 + 'A';
            else if(ans4 < 52)
                c4 = ans4 - 26 + 'a';
            else if(ans4 < 62)
                c4 = ans4 - 52 + '0';
            else if(ans4 == 62)
                c4 = '+';
            else
                c4 = '/';
        }
        outfile<<c1<<c2<<c3<<c4;
        cout<<c1<<c2<<c3<<c4;
    }
}
