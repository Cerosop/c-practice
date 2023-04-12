#include<iostream>
#include<vector>
using namespace std;
int main(){
    string s;
    int niden = 0, nnum = 0, nspe = 0;
    vector<string> all;
    while(getline(cin, s)){
        if(s == "END_OF_FILE"){
            break;
        }
        for(int i = 0; i < s.size(); i++){
            if(s[i] <= '9' && s[i] >= '0'){
                string tmp = "";
                tmp += s[i];
                // cout<<i<<"\n";
                for(int j = i + 1; j <= s.size(); j++){
                    if(j < s.size() && (s[j] <= '9' && s[j] >= '0')){
                        tmp += s[j];
                    }
                    else{
                        all.push_back(tmp);
                        nnum++;
                        i = j - 1;
                        // cout<<i<<"\n";
                        break;
                    }
                }
            }
            else if(s[i] == '_' || (s[i] <= 'z' && s[i] >= 'a') || (s[i] <= 'Z' && s[i] >= 'A')){
                string tmp = "";
                tmp += s[i];
                for(int j = i + 1; j <= s.size() + 1; j++){
                    if(j < s.size() && (s[j] == '_' || (s[j] <= 'z' && s[j] >= 'a') || (s[j] <= 'Z' && s[j] >= 'A') || s[j] <= '9' && s[j] >= '0')){
                        tmp += s[j];
                    }
                    else{
                        all.push_back(tmp);
                        niden++;
                        i = j - 1;
                        break;
                    }
                }
            }
            else if(s[i] == '+'){
                if(s[i + 1] == '+' || s[i + 1] == '='){
                    string tmp = "";
                    tmp += s[i];
                    tmp += s[i + 1];
                    all.push_back(tmp);
                    nspe++;
                    i++;
                }
                else{
                    string tmp = "";
                    tmp += s[i];
                    all.push_back(tmp);
                    nspe++;
                }
            }
            else if(s[i] == '-'){
                if(s[i + 1] == '-'){
                    string tmp = "";
                    tmp += s[i];
                    tmp += s[i + 1];
                    all.push_back(tmp);
                    nspe++;
                    i++;
                }
                else{
                    string tmp = "";
                    tmp += s[i];
                    all.push_back(tmp);
                    nspe++;
                }
            }
            else if(s[i] == '>' || s[i] == '<' || s[i] == '=' || s[i] == '!'){
                if(s[i + 1] == '='){
                    string tmp = "";
                    tmp += s[i];
                    tmp += s[i + 1];
                    all.push_back(tmp);
                    nspe++;
                    i++;
                }
                else{
                    string tmp = "";
                    tmp += s[i];
                    all.push_back(tmp);
                    nspe++;
                }
            }
            else if(s[i] == '&'){
                if(s[i + 1] == '&'){
                    string tmp = "";
                    tmp += s[i];
                    tmp += s[i + 1];
                    all.push_back(tmp);
                    nspe++;
                    i++;
                }
                else{
                    string tmp = "";
                    tmp += s[i];
                    all.push_back(tmp);
                    nspe++;
                }
            }
            else if(s[i] == '|'){
                if(s[i + 1] == '|'){
                    string tmp = "";
                    tmp += s[i];
                    tmp += s[i + 1];
                    all.push_back(tmp);
                    nspe++;
                    i++;
                }
                else{
                    string tmp = "";
                    tmp += s[i];
                    all.push_back(tmp);
                    nspe++;
                }
            }
            else if(s[i] == '*' || s[i] == '/' || s[i] == '%' || s[i] == '^' || s[i] == '\"' || s[i] == '\'' || s[i] == '.' || s[i] == ',' || s[i] == '(' || s[i] == ')' || s[i] == '[' || s[i] == ']' || s[i] == '{' || s[i] == '}' || s[i] == ':' || s[i] == ';'){
                string tmp = "";
                tmp += s[i];
                all.push_back(tmp);
                nspe++;
            }
            else if(s[i] != ' ' && s[i] != '\n'){
                string tmp = "";
                tmp += s[i];
                all.push_back(tmp);
            }
        }
    }
    int a;
    while(cin>>a){
        if(a == 0)
            break;
        else if(a == 1)
            cout<<"Total number of tokens: "<<all.size()<<"\n";
        else if(a == 2){
            for(int i = 0; i < all.size(); i++){
                cout<<"["<<all[i]<<"]\n";
            }
        }
        else if(a == 3)
            cout<<"Identifier: "<<niden<<", Number: "<<nnum<<", Special Symbol: "<<nspe<<"\n";
        else
            cout<<"Invalid command.\n";
    }
}