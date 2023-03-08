#include<bits/stdc++.h>
using namespace std;
struct thing{
    string s;
    int priority;
};

int main(){
    int n, now = 1;
    cin>>n;
    thing ts[n + 1];
    for(int i = 0; i < n; i++){
        string s;
        int a;
        cin>>s>>a;
        int comp = now++;
        ts[comp].priority = a;
        ts[comp].s = s;
        while(comp > 1 && ts[comp].priority > ts[comp / 2].priority){
            swap(ts[comp], ts[comp / 2]);
            comp /= 2;
        }
    }
    if(n == 1){
        cout<<"First three things to do:\n";
        cout<<ts[1].s;
    }
    else if(n == 2){
        cout<<"First three things to do:\n";
        cout<<ts[1].s<<"\n";
        cout<<ts[2].s;
    }
    else{
        if(ts[2].priority < ts[3].priority)
            swap(ts[2], ts[3]);
        cout<<"First three things to do:\n";
        cout<<ts[1].s<<"\n";
        cout<<ts[2].s<<"\n";
        cout<<ts[3].s;
    }
}