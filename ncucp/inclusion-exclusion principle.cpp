#include <bits/stdc++.h>
using namespace std;

long long int gcd(long long int a1, long long int a2){
    if(a1 < a2)
        swap(a1, a2);
    if(!(a1 % a2))
        return a2;
    return gcd(a2, a1 % a2); 
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m, ans;
    vector<int> v;
    while(cin>>n>>m){
        ans = n;
        v.clear();
        for(int i = 0, a; i < m; i++){
            cin>>a;
            v.push_back(a);
        }
        long long int a[1<<m] = {};
        for(int i = 1; i < (1<<m); i++){
            int r = i & -i;
            if(r == i){
                a[i] = v[__lg(i)];
            }
            else{
                a[i] = a[i - r] * a[r] / __gcd(a[i - r], a[r]);
            }
            if(!(__builtin_popcountll(i) % 2))
                ans += n / a[i];
            else 
                ans -= n / a[i];
        }
        cout<<ans<<"\n";
    }
}