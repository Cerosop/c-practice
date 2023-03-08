#include<bits/stdc++.h>
using namespace std;

struct point{
    int a, b, c;
};

bool cmp(point a, point b){
    if(a.a == b.a){
        if(a.b == b.b)
            return a.c > b.c;
        return a.b > b.b;
    }
    return a.a > b.a;
}

int main(){
    int n;
    point arr[100000];
    int unMax[100000];
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>arr[i].a>>arr[i].b>>arr[i].c;
    sort(arr, arr+n, cmp);

    for(int i = 0; i < n; i++){
        if(unMax[i]) continue;
        for(int j = i + 1; j < n; j++){
            if(arr[i].a >= arr[j].a && arr[i].b >= arr[j].b && arr[i].c >= arr[j].c)
                unMax[j] = 1;
        }
        cout<<arr[i].a<<" "<<arr[i].b<<" "<<arr[i].c<<"\n";
    }
}
