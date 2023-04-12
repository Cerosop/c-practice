/*
 * @Author: Cerosop jmhsu920816@gmail.com
 * @Date: 2023-03-29 19:06:42
 * @LastEditors: Cerosop jmhsu920816@gmail.com
 * @LastEditTime: 2023-03-29 21:01:43
 * @FilePath: \c++\ncucp\test2\2.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<bits/stdc++.h>
using namespace std;
int main(){
    // freopen("test.txt", "r", stdin);
    // freopen("testw.txt", "w", stdout);
    

    
    long long int n, k;
    cin>>n>>k;
    vector<int> prime;
    for(int i = 2; i * i <= ((n < 100000000)?n:100000000); i++){
        bool ch = false;
        for(auto x : prime){
            if(!(i % x)){
                ch = true;
                break;
            }
        }
        if(!ch){
            prime.push_back(i);
            // cout<<i<<",";
        }
            
    }
    // cout<<prime.size();

    vector<long long int> v;
    priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
    int t = n;
    for(auto x : prime){
        if(x * x > n){
            if(t > 1){
                v.push_back(t);
                pq.push(t);
            }
                

            break;
        }
        if(!(t % x)){
            v.push_back(x);
            pq.push(x);
            while(!(t % x)){
                t /= x;
            }
        }
        
    }

    long long int mul = 1;

    for(int i = 0; i < k; i++){
        mul = pq.top();
        pq.pop();
        for(auto x: v){
            pq.push(mul * x);
        }
    }
    cout<<mul * n;
}