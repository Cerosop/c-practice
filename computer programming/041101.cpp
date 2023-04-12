//041101
#include<bits/stdc++.h>
using namespace std;
int arr[5] = {31, 17, 33, 22, 16};

void alladd10(int *p, int n){
    for(int i = 0; i < n; i++){
        *(p + i) += 10;
        cout<<*(p + i)<<" ";
    }
    cout<<"\n";
}

int findmax(int *p, int n){
    int ans = -1e9;
    for(int i = 0; i < n; i++)
        ans = max(ans, *(p + i));
    return ans;
}

int findmin(int *p, int n){
    int ans = 1e9;
    for(int i = 0; i < n; i++)
        ans = min(ans, *(p + i));
    return ans;
}

int main(){
    alladd10(arr, 5);
    cout<<"max is "<<findmax(arr, 5)<<", min is "<<findmin(arr, 5);
}