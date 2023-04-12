/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-10-08 21:38:31
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-10-12 22:22:22
 * @FilePath: \c++\maximalpoint_3d_smart_sidetest.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
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
    cout<<"start smsd";
    for(int i=0;i<n;i++){
        arr[i].a = i;
        arr[i].b = n - i;
        arr[i].c = 0;
        // cout<<arr[i].a<<" "<<arr[i].b<<" "<<arr[i].c<<"\n";
    }
    cout<<"\n"<<"建資料所花費: "<<(double)(clock() - START) / CLOCKS_PER_SEC<<" s\n";
    sort(arr, arr+n, cmp);
    cout<<"\n"<<"建資料所花費: "<<(double)(clock() - START) / CLOCKS_PER_SEC<<" s\n";
    for(int i=0;i<n;i++){
        if(unMax[i]) continue;
        for(int j=i+1;j<n;j++){
            if(arr[i].a >= arr[j].a && arr[i].b >= arr[j].b && arr[i].c >= arr[j].c){
                unMax[j] = 1;
            }
        }
    }
    cout<<"\n"<<"程式執行所花費: "<<(double)(clock() - START) / CLOCKS_PER_SEC<<" s\n";
}
