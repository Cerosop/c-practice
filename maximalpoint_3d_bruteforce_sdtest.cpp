/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-10-12 19:52:42
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-10-12 22:24:58
 * @FilePath: \c++\maximalpoint_3d_bruteforce_rdtest.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<bits/stdc++.h>
using namespace std;
struct point{
    int a, b, c;
};
point arr[1000000];
int ans[1000000] = {1};

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
    int n = 100000;
    double START = clock();
    cout<<"start bfsd";
    int max = 100000;
    int min = -100000;
    for(int i=0;i<n;i++){
        arr[i].a = i;
        arr[i].b = n - i;
        arr[i].c = 0;
        ans[i] = 1;
        // cout<<arr[i].a<<" "<<arr[i].b<<" "<<arr[i].c<<"\n";
    }
    cout<<"\n"<<"建資料所花費: "<<(double)(clock() - START) / CLOCKS_PER_SEC<<" s\n";
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
    }
    cout<<"\n"<<"生成答案所花費: "<<(double)(clock() - START) / CLOCKS_PER_SEC<<" s\n";
}
