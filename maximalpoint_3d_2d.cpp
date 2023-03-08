#include<bits/stdc++.h>
using namespace std;

struct point{
    int a, b, c;
};

bool cmpxy(point a, point b){
    if(a.a == b.a){
        if(a.b == b.b)
            return a.c > b.c;
        return a.b > b.b;
    }
    return a.a > b.a;
}

bool cmpyz(point a, point b){
    if(a.b == b.b){
        if(a.c == b.c)
            return a.a > b.a;
        return a.c > b.c;
    }
    return a.b > b.b;
}

bool cmpzx(point a, point b){
    if(a.c == b.c){
        if(a.a == b.a)
            return a.b > b.b;
        return a.a > b.a;
    }
    return a.c > b.c;
}

int main(){
    int n;
    cin>>n;
    point points[100000];
    set<tuple<int, int, int>> ans;
    ans.clear();
    for(int i = 0; i < n; i++)
        cin>>points[i].a>>points[i].b>>points[i].c;

    sort(points, points + n, cmpxy);
    int max_y = points[0].b - 1;
    for(int i = 0; i < n; i++){
        if(points[i].b > max_y){
            max_y = points[i].b;
            ans.emplace(make_tuple(points[i].a, points[i].b, points[i].c));
        }
    }

    sort(points, points + n, cmpyz);
    int max_z = points[0].c - 1;
    for(int i = 0; i < n; i++){
        if(points[i].c > max_z){
            max_z = points[i].c;
            ans.emplace(make_tuple(points[i].a, points[i].b, points[i].c));
        }
    }

    sort(points, points + n, cmpzx);
    int max_x = points[0].a - 1;
    for(int i = 0; i < n; i++){
        if(points[i].a > max_x){
            max_x = points[i].a;
            ans.emplace(make_tuple(points[i].a, points[i].b, points[i].c));
        }
    }

    for(auto i = ans.rbegin(); i != ans.rend(); ++i)
        cout<<get<0>(*i)<<" "<<get<1>(*i)<<" "<<get<2>(*i)<<"\n";
}