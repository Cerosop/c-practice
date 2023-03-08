#include<bits/stdc++.h>
using namespace std;
bool inout(char a, char b){
    int ai, bi;
    switch (a){
    case 'h':
        return true;
    case '(':
        ai = 0;
        break;
    case ')':
        ai = 3;
        break;
    case '+':   case '-':
        ai = 1;
        break;
    case '*':   case '/':
        ai = 2;
        break;
    default:
        break;
    }

    switch (b){
    case '(':
        bi = 4;
        break;
    case ')':
        bi = 3;
        break;
    case '+':   case '-':
        bi = 1;
        break;
    case '*':   case '/':
        bi = 2;
        break;
    default:
        break;
    }

    return bi > ai;
}

int main(){
    int n;
    cin>>n;
    string s, tmp;
    vector<char> ope;
    queue<string> ans;
    getline(cin, s);
    while(n--){
        getline(cin, s);
        ope.push_back('h');
        for(int i = 0; i < s.size(); i++){
            if(s[i] != ' ' && s[i] != '\n'){
                if(s[i] <= '9' && s[i] >= '0'){
                    tmp = "";
                    for(int j = i; j < s.size(); j++){
                        if(s[j] <= '9' && s[j] >= '0')
                            tmp += s[j];
                        else{
                            i = j - 1;
                            break;
                        }  
                    }
                    ans.push(tmp);
                }
                else{
                    if(inout(ope.back(), s[i]))
                        ope.push_back(s[i]);
                    else{
                        while(!inout(ope.back(), s[i])){
                            tmp = "";
                            tmp += ope.back();
                            ans.push(tmp);
                            ope.pop_back();
                        }
                        ope.push_back(s[i]);
                    }
                    if(ope.back() == ')'){
                        while(ope.back() != '('){
                            if(ope.back() != ')'){
                                tmp = "";
                                tmp += ope.back();
                                ans.push(tmp);
                            }
                            ope.pop_back();
                        }
                        ope.pop_back();
                    }
                }
            }
        }
        while(!ope.empty()){
            if(ope.back() != 'h'){
                tmp = "";
                tmp += ope.back();
                ans.push(tmp);
            }
            ope.pop_back();
        }

        while (!ans.empty()){
            cout<<ans.front()<<" ";
            ans.pop();
        }
        cout<<"\n";
    }
}