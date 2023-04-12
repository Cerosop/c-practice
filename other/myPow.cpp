#include<bits/stdc++.h>
using namespace std;
double myPow(double x, int n) {
    if(n >= 0){ //�P�_����O�_������
        if(n == 1){ //�פ����
            return x;
        }
        else if(n == 0){ //�S�����
            return 1;
        }
        else if(n % 2){ //���謰�_��
            return x * myPow(x, n - 1);
        }
        else{ //���謰����
            double i = myPow(x, n / 2);
            return i * i;
        }
    }
    else{ //�p�L����O�t�ƴN�����ܥ���
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
    cout<<fixed<<setprecision(5)<<myPow(x, n); //��X��p���I��5��
    return 0;
}
