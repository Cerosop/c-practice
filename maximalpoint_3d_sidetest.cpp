/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-10-08 21:00:02
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-10-08 21:36:59
 * @FilePath: \c++\maximalpoint_3d_randomtest.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<bits/stdc++.h>
using namespace std;

bool cmpxy(tuple<int, int, int> a, tuple<int, int, int> b){
    if(get<0>(a) == get<0>(b)){
        if(get<1>(a) == get<1>(b)){
            return get<2>(a) > get<2>(b);
        }
        return get<1>(a) > get<1>(b);
    }
    return get<0>(a) > get<0>(b);
}

bool cmpyz(tuple<int, int, int> a, tuple<int, int, int> b){
    if(get<1>(a) == get<1>(b)){
        if(get<2>(a) == get<2>(b)){
            return get<0>(a) > get<0>(b);
        }
        return get<2>(a) > get<2>(b);
    }
    return get<1>(a) > get<1>(b);
}

bool cmpzx(tuple<int, int, int> a, tuple<int, int, int> b){
    if(get<2>(a) == get<2>(b)){
        if(get<0>(a) == get<0>(b)){
            return get<1>(a) > get<1>(b);
        }
        return get<0>(a) > get<0>(b);
    }
    return get<2>(a) > get<2>(b);
}

int main(){
    int n = 100000;
    vector<tuple<int, int, int>> points;
    set<tuple<int, int, int>> ans;
    // set<tuple<int, int, int>> repeat;
    double START = clock();
    cout<<"start 2dsd";
    int x, y, z;
    while(n--){
        
        x = 100000 - n;
        y = n;
        z = 0;
        // cout<<x<<" "<<y<<" "<<z<<"\n";
        points.push_back(make_tuple(x, y, z));
        // if(ans.find(make_tuple(x, y, z)) != ans.end()){
        //     repeat.emplace(make_tuple(x, y, z));
        // }
        // ans.emplace(make_tuple(x, y, z));
    }
    // ans.clear();
    cout<<"\n"<<"建資料所花費: "<<(double)(clock() - START) / CLOCKS_PER_SEC<<" s\n";

    sort(points.begin(), points.end(), cmpxy);
    int max_y = get<1>(points[0]) - 1;
    for(auto i : points){
        if(get<1>(i) > max_y){
            max_y = get<1>(i);
            ans.emplace(i);
        }
        // if(repeat.find(i) != repeat.end()){
        //     ans.erase(i);
        // }
    }

    sort(points.begin(), points.end(), cmpyz);
    int max_z = get<2>(points[0]) - 1;
    for(auto i : points){
        if(get<2>(i) > max_z){
            max_z = get<2>(i);
            ans.emplace(i);
        }
        // if(repeat.find(i) != repeat.end()){
        //     ans.erase(i);
        // }
    }

    sort(points.begin(), points.end(), cmpzx);
    int max_x = get<0>(points[0]) - 1;
    for(auto i : points){
        if(get<0>(i) > max_x){
            max_x = get<0>(i);
            ans.emplace(i);
        }
        // if(repeat.find(i) != repeat.end()){
        //     ans.erase(i);
        // }
    }
    cout<<"\n"<<"生成答案所花費: "<<(double)(clock() - START) / CLOCKS_PER_SEC<<" s\n";
    // for(auto i = ans.rbegin(); i != ans.rend(); ++i){
    //     cout<<get<0>(*i)<<" "<<get<1>(*i)<<" "<<get<2>(*i)<<"\n";
    // }
    // cout<<"\n"<<"程式執行所花費: "<<(double)(clock() - START) / CLOCKS_PER_SEC<<" s";
}