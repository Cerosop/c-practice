//032802
#include<bits/stdc++.h>
using namespace std;
void address(double *p){
    cout<<"the value at "<<p<<" is "<<*p<<"\n";
}

int main(){
    double pi = 3.14f;
    double *ptr = &pi;
    address(&pi);
    address(ptr);
}

