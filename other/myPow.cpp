#include<bits/stdc++.h>
using namespace std;
double myPow(double x, int n) {
    if(n >= 0){ //耞Ωよ琌タ计
        if(n == 1){ //沧ゎ兵ン
            return x;
        }
        else if(n == 0){ //疭Ωよ计
            return 1;
        }
        else if(n % 2){ //Ωよ计
            return x * myPow(x, n - 1);
        }
        else{ //Ωよ案计
            double i = myPow(x, n / 2);
            return i * i;
        }
    }
    else{ //筁Ωよ琌璽计碞琵ウ跑タ
        if(n == -1){
            return 1 / x;
        }
        else if(n % 2){
            return 1 / (x * myPow(x, -1 * n - 1));
        }
        else{
            double i = myPow(x,  (n / 2) * -1);
            return 1 / (i * i);
        }
    }
}

int main(){
    int n;
    double x;
    cin>>x>>n;
    cout<<fixed<<setprecision(5)<<myPow(x, n); //块计翴5
    return 0;
}
