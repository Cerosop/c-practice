#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second > b.second;
}

int main(){
    priority_queue<int> pq;
    vector<pair<int, int>> turtles;
    int a, b;
    while(cin>>a>>b){
        // if(a == -1){
        //     break;
        // }
        turtles.push_back(make_pair(a, b));

    }
    sort(turtles.begin(), turtles.end(), cmp);
    int weight = 0;
    for(int i = turtles.size() - 1; i >= 0; i--){
        pq.push(turtles[i].first);
        weight += turtles[i].first;
        if(weight > turtles[i].second){
            weight -= pq.top();
            pq.pop();
        }
    }
    cout<<pq.size()<<"\n";
}