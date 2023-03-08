#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first < b.first)
        return true;
    else if (a.first == b.first)
        return a.second < b.second;
    else
        return false;
}

string minute(int n){
    if(n < 10)
        return "0" + to_string(n);
    else
        return to_string(n);
}

string last(int n){
    if(n < 60)
        return to_string(n) + " minutes.";
    else
        return to_string(n / 60) + " hours and " + to_string(n % 60) + " minutes.";
}

int main(){
    int n, count = 1;
    vector<pair<int, int>> vec;
    while(cin>>n){
        if(n == 8787)
            break;
        string line;
        getline(cin, line);
        vec.clear();
        while(n--){
            getline(cin, line);
            int begin = ((line[0] - '0') * 10 + (line[1] - '0')) * 60 + (line[3] - '0') * 10 + (line[4] - '0'), 
                end = ((line[6] - '0') * 10 + (line[7] - '0')) * 60 + (line[9] - '0') * 10 + (line[10] - '0');
            vec.push_back(make_pair(begin, end));
        }
        sort(vec.begin(), vec.end(), cmp);
        int prend = 600, max = 0, from;
        for(auto i : vec){
            if(i.first - prend > max){
                max = i.first - prend;
                from = prend;
            }
                
            if(i.second > prend)
                prend = i.second;
        }
        if(18 * 60 - prend > max){
            from = prend;
            max = 18 * 60 - prend;
        }
        cout<<"Day #"<<count++<<": the longest nap starts at "<<from / 60<<":"<<minute(from % 60)<<" and will last for "<<last(max)<<"\n";
    }
}