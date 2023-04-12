#include<bits/stdc++.h>
using namespace std;
struct point{
    int a, b, c;
};
point arr[1000000];
int unMax[1000000];

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
    int n = 100000, x_max, y_max, z_max;
    vector<point> ans;
    double START = clock();
    cout<<"start smrd";
    int max = 100000;
    int min = -100000;
    for(int i=0;i<n;i++){
        arr[i].a = (max - min) * rand() / RAND_MAX + min;
        arr[i].b = (max - min) * rand() / RAND_MAX + min;
        arr[i].c = (max - min) * rand() / RAND_MAX + min;
        // cout<<arr[i].a<<" "<<arr[i].b<<" "<<arr[i].c<<"\n";
    }
    cout<<"\n"<<"建資料所花費: "<<(double)(clock() - START) / CLOCKS_PER_SEC<<" s\n";
    sort(arr, arr+n, cmp);

    for(int i=0;i<n;i++){
        if(unMax[i]) continue;
        for(int j=i+1;j<n;j++){
            if(arr[i].a >= arr[j].a && arr[i].b >= arr[j].b && arr[i].c >= arr[j].c){
                unMax[j] = 1;
            }
        }
        ans.push_back(arr[i]);
        // cout << arr[i].a << " " << arr[i].b << " " << arr[i].c << endl;
    }
    cout<<"\n"<<"生成答案所花費: "<<(double)(clock() - START) / CLOCKS_PER_SEC<<" s\n";
}
