#include<bits/stdc++.h>
using namespace std;
int ans[10] = {};

void func(int a, int b){
    int x = 100000000, a1, b1, i = 8;
    if(a - b < 9){
        for(int i = b; i <= a; i++){
            int c = i;
            while(c){
                ans[c % 10] ++;
                c /= 10;
            }
        }
        return;
    }  
    for(; i >= 0; i--){
        if(a / x != 0 && a / x != b / x){
            a1 = x * ((a + 1) / x) - 1;
            b1 = x * ((b + x - 1 ) / x);
            break;
        }
        x /= 10;
    }
    int ax = a1 / x, bx = b1 / x;
    for(int j = bx; j <= ax; j++){
        int c = j;
        while(c){
            if(c % 10 || c >= 10)
                ans[c % 10] += x; 
            c /= 10;
        }
        
    }
    x /= 10;
    while(i--){
        for(int j = 0; j < 10; j++){
            ans[j] += x * (ax - bx + 1); 
        }
        
    }
    func(a, a1 + 1);
    func(b1 - 1, b);
}

int main(){
    int a, b ;
    while(cin>>a>>b){
        if(!a && !b){
            break;
        }
        for(int i = 0; i < 10; i++){
            ans[i] = 0;
        }
        if(a < b){
            swap(a, b);
        }
        func(a, b);
        for(int i = 0; i < 9; i++){
            cout<<ans[i]<<" ";
        }
        cout<<ans[9]<<"\n";
    }

}