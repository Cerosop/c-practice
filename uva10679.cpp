#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n1, n2;
    string s1, s2;
    cin>>n1;
    while(n1--){
        cin>>s1>>n2;
        while(n2--){
            cin>>s2;
            if(strstr(s1.c_str(), s2.c_str()) != NULL)
                cout<<"y\n";
            else 
                cout<<"n\n";
        }
    }
}