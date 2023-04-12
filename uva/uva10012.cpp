#include<bits/stdc++.h>
using namespace std;
int k;
double arr[8], mi = 0;
vector<double> seq;
bool used[8];

void solve(int now){
    if(now == k){
        if(k){
            int lp = 0;
            double x[k] = {};
            for(int i = 0; i < k; i++){
                x[i] = seq[i];
                for(int j = 0; j < i; j++)
                    x[i] = max(x[i], x[j] + 2 * (sqrt(seq[i] * seq[j])));
                if(x[lp] + seq[lp] < x[i] + seq[i])
                    lp = i;
            }
            mi = min(mi, x[lp] + seq[lp]);
        }
    }
    else{
        for(int i = 0; i < k; i++){
            if(!used[i]){
                used[i] = true;
                seq.push_back(arr[i]);
                solve(now + 1);
                seq.pop_back();
                used[i] = false;
            }
        }
    }
}

int main(){
    // freopen("test.txt", "r", stdin);
    // freopen("testw.txt", "w", stdout);
    int n;
    cin>>n;
    while(n--){
        cin>>k;
        mi = 0;
        for(int i = 0; i < k; i++){
            cin>>arr[i];
            mi += 2 * arr[i];
            used[i] = false;
        }
        seq.clear();
        solve(0);
        cout<<fixed<<setprecision(3)<<mi<<"\n";
    }
}