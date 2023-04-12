#include<bits/stdc++.h>
using namespace std;

struct point{
    int a, b, c;
};

bool cmp(point a, point b){
    if(a.a == b.a){
        if(a.b == b.b){
            return a.c > b.c;
        }
        return a.b > b.b;
    }
    return a.a > b.a;
}

int main(){
    int n;
    point arr[100000];
    int ans[100000];
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>arr[i].a>>arr[i].b>>arr[i].c;
        ans[i] = 1;
    }
    sort(arr, arr+n, cmp);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(ans[j] == 0)
                continue;
            if(arr[j].b >= arr[i].b && arr[j].c >= arr[i].c){
                ans[i] = 0;
                break;
            }
        }
        if(ans[i] == 1)
            cout<<arr[i].a<<" "<<arr[i].b<<" "<<arr[i].c<<"\n";
    }
}
