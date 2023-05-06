#include<bits/stdc++.h>
using namespace std;

int ans[100005];
void solve1(int res[], string a, string b, int d){
    if(a.size() == 1){
        for(int i = 0; i < b.size(); i++){
            res[d + i] += (b[b.size() - i - 1] - '0') * (a[0] - '0');
            
        }
    }
    else if(b.size() == 1){
        for(int i = 0; i < a.size(); i++){
            res[d + i] += (a[a.size() - 1 - i] - '0') * (b[0] - '0');
            
        }
    }
    else{
        int an = a.size() / 2, bn = b.size() / 2;
        int an2 = a.size() - an, bn2 = b.size() - bn;
        solve1(res, a.substr(0, an), b.substr(0, bn), d + an2 + bn2);
        solve1(res, a.substr(0, an), b.substr(bn, bn2), d + an2);
        solve1(res, a.substr(an, an2), b.substr(0, bn), d + bn2);
        solve1(res, a.substr(an, an2), b.substr(bn, bn2), d);
    }

}


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

void solve2(int res[], string a, string b){
    if(min(a.size(), b.size()) < 1950){
        solve1(res, a, b, 0);
        int c = 0;
        for(int j = 0; j < a.size() + b.size(); j++){
            res[j] += c;
            c = res[j] / 10;
            res[j] %= 10;
        }
        return;
    }
    
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

        solve2(r, add(a.substr(0, an), a.substr(an, an2)), add(b.substr(0, bn), b.substr(bn, an2)));
        solve2(wy, a.substr(0, an), b.substr(0, bn));
        solve2(xz, a.substr(an, an2), b.substr(bn, an2));
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
    // freopen("test.txt", "r", stdin);
    freopen("testw.txt", "w", stdout);
    
    string n, m;
    int t = 30;
    for(int k = 10000; k <= 50000; k+=5000){
        vector<string> vn, vm;
        vn.clear();
        vm.clear();
        
        for(int i = 0; i < t; i++){
            n = "";
            m = "";
            n += (char)((rand() % 9) + '0' + 1);
            m += (char)((rand() % 9) + '0' + 1);
            for(; (int)n.size() <= (k-8);){
                n += to_string(rand() % (int)1e9);
            }
            for(; (int)m.size() <= k-8;){
                m += to_string(rand() % (int)1e9);
            }
            for(int j = n.size(); j < k; j++){
                n += (char)((rand() % 10) + '0');
            }
            for(int j = m.size(); j < k; j++){
                m += (char)((rand() % 10) + '0');
            }
            
            vn.push_back(n);
            vm.push_back(m);
        }
        auto start = chrono::high_resolution_clock::now();
        for(int i = 0; i < t; i++){
            memset(ans, 0, sizeof(ans));
            solve(ans, vn[i], vm[i]);
        }
        auto finish = chrono::high_resolution_clock::now();
        cout<<k<<" "<<chrono::duration_cast<chrono::nanoseconds>(finish-start).count() / t;

        start = chrono::high_resolution_clock::now();
        for(int i = 0; i < t; i++){
            memset(ans, 0, sizeof(ans));
            solve1(ans, vn[i], vm[i], 0);
            int c = 0;
            for(int j = 0; j < vn[i].size() + vm[i].size(); j++){
                ans[j] += c;
                c = ans[j] / 10;
                ans[j] %= 10;
            }
        }
        finish = chrono::high_resolution_clock::now();
        cout<<" "<<chrono::duration_cast<chrono::nanoseconds>(finish-start).count() / t;

        start = chrono::high_resolution_clock::now();
        for(int i = 0; i < t; i++){
            memset(ans, 0, sizeof(ans));
            solve2(ans, vn[i], vm[i]);
        }
        finish = chrono::high_resolution_clock::now();
        cout<<" "<<chrono::duration_cast<chrono::nanoseconds>(finish-start).count() / t<<"\n";
    
    }
}
