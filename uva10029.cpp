#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    vector<int> dpa;
    map<string, int> ma;
    int j = 0, ans = 0;
    while(cin>>s){
        // if(s == "87878")
        //     break;
        j++;
        for(int i = 0; i <= s.size(); i++){
            string tmp = s.substr(0, i);
            tmp += '*';
            tmp += s.substr(i, s.size() - i);
            if(ma[tmp] == 0){
                ma[tmp] = j;
            }
            else{
                if(dpa.size() == j)
                    dpa[j - 1] = max(dpa[j - 1], dpa[ma[tmp] - 1] + 1);
                else
                    dpa.push_back(dpa[ma[tmp] - 1] + 1);
                ans = max(ans, dpa[j - 1]);
                ma[tmp] = j;
            }
        }
        for(int i = 0; i < s.size(); i++){
            string tmp = s.substr(0, i);
            tmp += '*';
            tmp += s.substr(i + 1, s.size() - i);
            if(ma[tmp] == 0){
                ma[tmp] = j;
            }
            else{
                if(dpa.size() == j)
                    dpa[j - 1] = max(dpa[j - 1], dpa[ma[tmp] - 1] + 1);
                else
                    dpa.push_back(dpa[ma[tmp] - 1] + 1);
                ans = max(ans, dpa[j - 1]);
                ma[tmp] = j;
            }
        }
        if(dpa.size() < j){
            dpa.push_back(1);
        }
    }
    cout<<ans<<"\n";
}