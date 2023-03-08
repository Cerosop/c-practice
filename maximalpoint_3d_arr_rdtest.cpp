/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-10-08 21:00:02
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-10-12 22:58:51
 * @FilePath: \c++\maximalpoint_3d_randomtest.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<bits/stdc++.h>
using namespace std;
struct point{
    int a, b, c;
};

bool cmpxy(point a, point b){
    if(a.a == b.a){
        if(a.b == b.b){
            return a.c > b.c;
        }
        return a.b > b.b;
    }
    return a.a > b.a;
}

bool cmpyz(point a, point b){
    if(a.b == b.b){
        if(a.c == b.c){
            return a.a > b.a;
        }
        return a.c > b.c;
    }
    return a.b > b.b;
}

bool cmpzx(point a, point b){
    if(a.c == b.c){
        if(a.a == b.a){
            return a.b > b.b;
        }
        return a.a > b.a;
    }
    return a.c > b.c;
}

int main(){
    int n = 100000;
    point points[100000];
    set<tuple<int, int, int>> ans;
    double START = clock();
    cout<<"start 2drd";
    int x, y, z;
    int max = 100000;
    int min = -100000;
    for(int i=0;i<n;i++){
        points[i].a = (max - min) * rand() / RAND_MAX + min;
        points[i].b = (max - min) * rand() / RAND_MAX + min;
        points[i].c = (max - min) * rand() / RAND_MAX + min;
    }
    cout<<"\n"<<"建資料所花費: "<<(double)(clock() - START) / CLOCKS_PER_SEC<<" s\n";

    sort(points, points + n, cmpxy);
    int max_y = points[0].b - 1;
    for(auto i : points){
        if(i.b > max_y){
            max_y = i.b;
            ans.emplace(make_tuple(i.a, i.b, i.c));
        }
    }

    sort(points, points + n, cmpyz);
    int max_z = points[0].c - 1;
    for(auto i : points){
        if(i.c > max_z){
            max_z = i.c;
            ans.emplace(make_tuple(i.a, i.b, i.c));
        }
    }

    sort(points, points + n, cmpzx);
    int max_x = points[0].a - 1;
    for(auto i : points){
        if(i.a > max_x){
            max_x = i.a;
            ans.emplace(make_tuple(i.a, i.b, i.c));
        }
    }

    cout<<"\n"<<"生成答案所花費: "<<(double)(clock() - START) / CLOCKS_PER_SEC<<" s\n";
    // for(auto i = ans.rbegin(); i != ans.rend(); ++i){
    //     cout<<get<0>(*i)<<" "<<get<1>(*i)<<" "<<get<2>(*i)<<"\n";
    // }
    // cout<<"\n"<<"程式執行所花費: "<<(double)(clock() - START) / CLOCKS_PER_SEC<<" s";
}