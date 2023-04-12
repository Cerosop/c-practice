/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-12-08 21:27:44
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-12-08 22:03:37
 * @FilePath: \c++\shortest_path.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<bits/stdc++.h>
using namespace std;
struct edge
{
    int w, s, e;
};

struct cmp{
    public:
    bool operator()(edge& a,edge& b){
        return a.w < b.w;
    }
};

int main(){
    int n, s, e;
    cin>>n>>s>>e;
    int a[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>a[i][j];
        }
    }
    priority_queue<edge, vector<edge>, cmp> q;
    int ans[n];
    for(int i = 0; i < n; i++){
        ans[i] = INT_MAX;
        if(a[s][i] != 0){
            edge *ne = new edge;
            ne->e = i;
            ne->s = s;
            ne->w = a[s][i];
            q.push(*ne);
        }
    }
    ans[s] = 0;
    while(!q.empty()){
        edge ed = q.top();
        q.pop();
        if(ans[ed.e] > ans[ed.s] + ed.w){
            ans[ed.e] = ans[ed.s] + ed.w;
            for(int i = 0; i < n; i++){
                if(a[ed.e][i] != 0){
                    edge *ne = new edge;
                    ne->e = i;
                    ne->s = ed.e;
                    ne->w = a[ed.e][i];
                    q.push(*ne);
                }
            }
        }
    }
    cout<<ans[e];
}