#include<bits/stdc++.h>
using namespace std;
struct point{
    int x, y;
};

int main(){
    // freopen("test.txt", "r", stdin);
    // freopen("testw.txt", "w", stdout);
    int n;
    cin>>n;
    string s;
    getline(cin, s);
    getline(cin, s);
    while(n--){
        vector<point> v;
        v.clear();
        while(getline(cin, s)){
            if(s == "")
                break;
            int a = 0;
            bool x = false;
            point newpoint;
            for(int i = 0; i < s.size(); i++){
                if(s[i] == ' '){
                    if(x)
                        a *= -1;
                    newpoint.x = a;
                    x = false;
                    a = 0;
                }
                else if(s[i] == '-'){
                    x = true;
                }
                else{
                    a *= 10;
                    a += s[i] - '0';
                }
            }
            if(x)
                a *= -1;
            newpoint.y = a;
            v.push_back(newpoint);
        }
        int maxp = 2;
        for(int i = 0; i < v.size(); i++){
            vector<double> vd;
            vd.clear();
            for(int j = 0; j < v.size(); j++){
                if(i - j){
                    double m;
                    if(v[i].x - v[j].x){
                        m = double(v[i].y - v[j].y) / double(v[i].x - v[j].x);
                    }
                    else{
                        m = 1e1000;
                    }
                    vd.push_back(m);
                }
            }
            sort(vd.begin(), vd.end());
            int tmp = 2;
            for(int j = 1; j < vd.size(); j++){
                if(vd[j - 1] == vd[j]){
                    tmp++;
                }
                else{
                    maxp = max(maxp, tmp);
                    tmp = 2;
                }
            }
            maxp = max(maxp, tmp);
        }
        if(n)
        cout<<maxp<<"\n\n";
        else
        cout<<maxp<<"\n";
    }
}