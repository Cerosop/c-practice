#include<bits/stdc++.h>
using namespace std;

string add(string a, string b){
    if(a.size() < b.size())
        swap(a, b);
    string tmp = "0";
    a = tmp + a;
    for(int i = 0; i < a.size() - b.size() - 1; i++){
        tmp += '0';
    }
    b = tmp + b;

    string ret = "";
    int car = 0;
    for(int i = a.size() - 1; i >= 0; i--){
        tmp = "";
        int x = ((a[i] - '0') + (b[i] - '0') + car);
        car = 0;
        if(x >= 10){
            x -= 10;
            car = 1;
        }
        char c = '0' + x;
        tmp += c;
        ret = tmp + ret;
    }

    int i = 0;
    for(; i < ret.size(); i++){
        if(ret[i] - '0')
            break;
    }
    return ret.substr(i, ret.size() - i);
}

void solve(int res[], string a, string b){
    if(a.size() <= 1){
        for(int i = 0; i < b.size(); i++){
            res[i] += (b[b.size() - i - 1] - '0') * (a[0] - '0');
            while(res[i] >= 10){
                res[i] -= 10;
                res[i + 1]++;
            }
        }
    }

    else if(b.size() <= 1){
        for(int i = 0; i < a.size(); i++){
            res[i] += (a[a.size() - 1 - i] - '0') * (b[0] - '0');
            while(res[i] >= 10){
                res[i] -= 10;
                res[i + 1]++;
            }
        }
    }

    else{
        if(a.size() > b.size())
            swap(a, b);
        int an = a.size() / 2;
        int an2 = a.size() - an;
        int bn = b.size() - an2;
        int r[bn + an2 + 2] = {}, wy[bn + an2 + 2] = {}, xz[bn + an2 + 2] = {};

        solve(r, add(a.substr(0, an), a.substr(an, an2)), add(b.substr(0, bn), b.substr(bn, an2)));
        solve(wy, a.substr(0, an), b.substr(0, bn));
        solve(xz, a.substr(an, an2), b.substr(bn, an2));
        for(int i = bn + an2 + 1; i >= 0; i--){
            r[i] -= wy[i] + xz[i];
            while(r[i] < 0){
                for(int j = i + 1; j <= bn + an2 + 1; j++){
                    if(r[j]){
                        r[j]--;
                        break;
                    }
                        
                    else    
                        r[j] = 9;
                }
                r[i] += 10;
            }
        }

        int d = an2<<1;
        for(int i = 0; i < d; i++){
            res[i] += xz[i];
        }

        for(int i = 0; i < an + bn; i++){
            res[i + d] += wy[i];
        }

        int i = 0, c = 0;
        for(; i < bn + an2 + 2; i++){
            res[i + an2] += r[i] + c;
            c = 0;
            if(res[i + an2] >= 10){
                c = 1;
                res[i + an2] -= 10;
            }
        }
        while(c){
            res[i + an2] += c;
            c = 0;
            if(res[i + an2] >= 10){
                c = 1;
                res[i + an2] -= 10;
            }
            i++;
        }
    }
}

int main(){
    string n, m;
    cin>>n>>m;
    int t = 100, ans[10005];
    auto start = chrono::high_resolution_clock::now();

    // double START = clock();
    for(int i = 0; i < t; i++){
        memset(ans, 0, sizeof(ans));
        solve(ans, n, m);
    }
    // double timer = (clock() - START);
    
    auto finish = chrono::high_resolution_clock::now();
    if(ans[m.size() + n.size()]) cout<<ans[m.size() + n.size()];
    if(ans[m.size() + n.size() - 1]) cout<<ans[m.size() + n.size() - 1];
    for(int i = m.size() + n.size() - 2; i >= 0; i--){
        cout<<ans[i];
    }
    cout<<"\n"<<(double)chrono::duration_cast<chrono::nanoseconds>(finish-start).count() / t;
}
