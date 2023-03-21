#include<bits/stdc++.h>
using namespace std;

double fac(int n){
    if(!n) return 1;
    return n * fac(n - 1);
}

double my_fun(double x, int n){
    double ans = 0, x1 = x;
    for(int i = 1; i <= n; i++){
        ans += x1 / fac(i);
        x1 *= x;
    }
    return ans;
}

int main(){
    cout<<fixed<<setprecision(10)<<"my_fun(0.1, 5) = "<<my_fun(0.1, 5)<<"\n";
    cout<<"my_fun(0.1, 8) = "<<my_fun(0.1, 8)<<"\n";
    cout<<"my_fun(0.2, 8) = "<<my_fun(0.2, 8)<<"\n";
    int i = 1;
    while(1){
        if(my_fun(0.1, i) - my_fun(0.1, i - 1) < 0.00001){
            cout<<"when n is greater than "<<i<<", my_fun(0.1, n) - my_fun(0.1, n - 1) < 0.00001";
            break;
        }
        i++;
    }
}