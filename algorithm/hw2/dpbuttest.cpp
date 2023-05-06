/*
 * @Author: Cerosop jmhsu920816@gmail.com
 * @Date: 2023-05-05 16:53:51
 * @LastEditors: Cerosop jmhsu920816@gmail.com
 * @LastEditTime: 2023-05-07 00:32:06
 * @FilePath: \c++\algorithm\hw2\dpbuttest.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

struct obs{
    int a, b, a2, b2;
};

bool cmp(obs a, obs b){
    if(a.a2 == b.a2)
        return a.b2 < b.b2;
    return a.a2 < b.a2;
}

int p[2001][2001];

int main(){
    freopen("in10000.txt", "r", stdin);
    freopen("dpbutout.txt", "w", stdout);

    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int h, w, k, a, b, c, d, q;
    while(cin>>h>>w>>k){
        
        p[0][0] = 1;
        for(int i = 1; i <= h; i++)
            p[i][0] = p[i - 1][0];
        for(int i = 1; i <= w; i++)
            p[0][i] = p[0][i - 1];
        for(int i = 1; i <= h; i++){
            for(int j = 1; j <= w; j++){
                p[i][j] += p[i][j - 1];
                p[i][j] += p[i - 1][j];
                if(p[i][j] >= 2552)
                    p[i][j] -= 2552;
            }
        }
        auto st = high_resolution_clock::now();
        while(k--){
            cin>>q;
            vector<obs> v;
            v.clear();
            for(int i = 0; i < q; i++){
                obs *newobs = new obs;
                cin>>newobs->a>>newobs->b>>newobs->a2>>newobs->b2;
                v.push_back(*newobs);
            }
            
            sort(v.begin(), v.end(), cmp);
            obs *newobs = new obs;
            newobs->a = h;
            newobs->b = w;
            v.push_back(*newobs);
            // cout<<v.size()<<"grgeg ";
            int dp[v.size()];
            for(int i = 0; i < v.size(); i++){
                dp[i] = p[v[i].a][v[i].b];
                for(int j = 0; j < i; j++){
                    if(v[j].a2 < v[i].a && v[j].b2 < v[i].b){
                        dp[i] -= dp[j] * p[v[i].a - v[j].a2][v[i].b - v[j].b2];
                    }
                }
                dp[i] %= 2552;
                if(dp[i] < 0)
                    dp[i] += 2552;
            }
            
            // cout<<dp[v.size() - 1]<<"\n";
        }
        auto ed = high_resolution_clock::now();
        auto dt = duration_cast<nanoseconds>(ed - st);
        cout<<h<<" "<<q<<" "<< dt.count() << '\n';
    }
}