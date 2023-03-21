#include<bits/stdc++.h>
using namespace std;

struct node{
    int begin, end;
};

int main(){
    int n;
    long long int k;
    cin>>n>>k;
    long long int arr[n], k_arr[n];
    int plus_index[n], minus_index[n];
    node k_plus_arr[n], k_minus_arr[n];
    cin>>arr[0];
    k_plus_arr[0].begin = 0;
    k_plus_arr[0].end = 0;
    plus_index[0] = 0;
    k_minus_arr[0].begin = 0;
    k_minus_arr[0].end = 0;
    minus_index[0] = 0;
    for(int i = 1; i < n; i++){
        cin>>arr[i];
        k_arr[i] = k * arr[i];
        if(k_arr[i] > k_arr[i - 1]){
            k_plus_arr[plus_index[i - 1]].end = i;
            plus_index[i] = plus_index[i - 1];
        }
        else{
            k_plus_arr[plus_index[i - 1] + 1].begin = i;
            k_plus_arr[plus_index[i - 1] + 1].end = i;
            plus_index[i] = plus_index[i - 1] + 1;
        }
    }

    for(int i = 0; i < n; i++){
        for(int )
    }
}