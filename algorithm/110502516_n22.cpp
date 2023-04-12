/*
 * @Author: Cerosop jmhsu920816@gmail.com
 * @Date: 2023-03-30 11:01:28
 * @LastEditors: Cerosop jmhsu920816@gmail.com
 * @LastEditTime: 2023-03-30 11:26:46
 * @FilePath: \c++\110502516_n22.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<bits/stdc++.h>
using namespace std;
int ans[10005];

void solve(string a, string b, int d){
    if(a.size() == 1){
        for(int i = 0; i < b.size(); i++){
            ans[d + i] += (b[b.size() - i - 1] - '0') * (a[0] - '0');
            
        }
    }
    else if(b.size() == 1){
        for(int i = 0; i < a.size(); i++){
            ans[d + i] += (a[a.size() - 1 - i] - '0') * (b[0] - '0');
            
        }
    }
    else{
        int an = a.size() / 2, bn = b.size() / 2;
        int an2 = a.size() - an, bn2 = b.size() - bn;
        solve(a.substr(0, an), b.substr(0, bn), d + an2 + bn2);
        solve(a.substr(0, an), b.substr(bn, bn2), d + an2);
        solve(a.substr(an, an2), b.substr(0, bn), d + bn2);
        solve(a.substr(an, an2), b.substr(bn, bn2), d);
    }

}


int main(){
    string n, m;
    cin>>n>>m;
    int t = 100;
    auto start = chrono::high_resolution_clock::now();

    // double START = clock();
    for(int i = 0; i < t; i++){
        memset(ans, 0, sizeof(ans));
        solve(n, m, 0);
        int c = 0;
        for(int j = 0; j < n.size() + m.size(); j++){
            ans[j] += c;
            c = ans[j] / 10;
            ans[j] %= 10;
        }
    }
    // double timer = (clock() - START);
    
    auto finish = chrono::high_resolution_clock::now();
    if(ans[m.size() + n.size()]) cout<<ans[m.size() + n.size()];
    if(ans[m.size() + n.size() - 1]) cout<<ans[m.size() + n.size() - 1];
    for(int i = m.size() + n.size() - 2; i >= 0; i--){
        cout<<ans[i];
    }
    // cout<<"\n"<<timer / t;
    cout<<"\n"<<(double)chrono::duration_cast<chrono::nanoseconds>(finish-start).count() / t;
    
}
