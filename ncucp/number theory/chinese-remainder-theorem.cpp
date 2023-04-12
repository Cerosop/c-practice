#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k;
    bool check = 0;
    cin>>n>>k;
               
    // vector<int> prime;
    // for(int i = 2; i < 1000; i++){
    //     bool check = false;
    //     for(int j = 2; j < i; j++){
    //         if(!(i % j)){
    //             check = true;
    //             break;
    //         }
    //     }
    //     if(!check)
    //         prime.push_back(i);
    // }

    vector<int> arr;
    for(int i = 0, a; i < n; i++){
        cin>>a;
        arr.push_back(a);
    }

    for(int x = 2; x * x <= k; x++){
        int d = 0;
        while(!(k % x)){
            k /= x;
            d++;
        }
        if(d){
            check = 0;
            for(int i = 0; i < n; i++){
                int c = 0;
                while(!(arr[i] % x)){
                    arr[i] /= x;
                    c++;
                }
                if(c >= d){
                    check = 1;
                    break;
                }
            }
            if(!check){
                cout<<"No";
                return 0;
            }
        }
    }
    if(k - 1){
        check = 0;
        for(auto z:arr){
            if(!(z % k)){
                check = 1;
                break;
            }
        }
        if(!check){
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
}