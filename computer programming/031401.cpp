//031401
#include<bits/stdc++.h>
using namespace std;

double my_fun(int n){
    if(n == 1)
        return 0.5;
    return ((double)1/(1<<n)) + my_fun(n - 1);
}

int main(){
    int n;
    for(int i = 3; i <= 6; i++){
        cout<<"my_fun("<<i<<") = "<<my_fun(i)<<"\n";
    }

    cout<<"my_fun(n)會趨近於"<<((double)1 / 2) * (1 - pow((double)1 / 2, 1000)) / ((double)1 / 2)<<"\n";

    for(int i = 1; i < 1000; i++){
        if(my_fun(i) -  0.99999 > 0){
            cout<<"n最少為"<<i<<"時my_fun(n)會大於0.99999，此時my_fun("<<i<<") = "<<my_fun(i)<<"\n";
            break;
        }
    }
}