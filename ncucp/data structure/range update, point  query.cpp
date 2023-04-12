#include<bits/stdc++.h>
using namespace std;
int s_tree[00000];
void rain(int l, int r, int d1, int d2, int v, int i){
    if(l >= d1 and r <= d2) {
        s_tree[i] += v;
        return;
    }
    int mid = (l + r) / 2;
    if(l >= d1){
        rain(l, mid, d1, d2, v, i * 2);
        rain(mid + 1, r, d1, d2, v, i * 2 + 1);
    }
    if(r <= d1){
        rain(l, mid, d1, d2, v, i * 2);
        rain(mid + 1, r, d1, d2, v, i * 2 + 1);
    }

}

int main(){
    int n, q;
    cin>>n>>q;
    memset(s_tree, 0, sizeof(s_tree));

    for(int i = 0; i < n; i++){
        int l, r, v;
        cin>>l>>r>>v;
        rain(1, n, l, r, v, 0);
    }
}