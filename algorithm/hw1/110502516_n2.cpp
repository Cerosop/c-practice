#include<bits/stdc++.h>
using namespace std;
int main(){
    string n, m;
    cin>>n>>m;
    int ans[10005] = {}, c = 0, t = 200;
    auto start = chrono::high_resolution_clock::now();

    // double START = clock();
    for(int k = 0; k < t; k++){
        memset(ans, 0, sizeof(ans));
        for(int i = 0; i < m.size(); i++){
            for(int j = 0; j < n.size(); j++){
                ans[i + j] += c + (m[m.size() - i - 1] - '0') * (n[n.size() - j - 1] - '0');
                c = ans[i + j] / 10;
                ans[i + j] %= 10;
            }
            ans[i + n.size()] = c;
            c = 0;
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
