/*
 * @Author: Cerosop jmhsu920816@gmail.com
 * @Date: 2022-12-07 14:01:59
 * @LastEditors: Cerosop jmhsu920816@gmail.com
 * @LastEditTime: 2023-03-09 00:25:54
 * @FilePath: \c++\test1.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;

vector <vector<int>> edge;
vector <int> vis2; //大層的
stack <int> stk; //ans

int vis[100005]={0}; //小層的
int vertice_num , edge_num;
int start_num=0;
bool find_ans = false; //不能宣告在 dfs 的函式裡

bool dfs( int now ,int before );
bool visiting();
void print_ans();

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    cin >> vertice_num >> edge_num; //點度數目和邊的數目
    edge.resize(vertice_num+1);
    vis2.resize(vertice_num+1);

    for(int i=0,a,b;i<edge_num;i++){
        cin >> a >> b;
        edge[a].push_back(b); // 有向圖
    }

    if(visiting()) print_ans();
    else cout << "IMPOSSIBLE";

    return 0;
}

bool dfs( int now ,int before ){

    for(auto next : edge[now]){
        
        if(!vis2[next]){ //
			vis[next] =1;
            vis2[next] =1;
            if(dfs(next,now)){ //只要可以往下都回傳 true，但dfs的數字不一定是答案所要的路徑之一
                
                if(start_num){
                    if(start_num == now){
                        start_num=-1;
                        stk.push(now);
                    }
                    if(start_num != -1) {
                        stk.push(now);
                    }
                }  
                return true;
            }
			vis[next]=0;
        }
        else if(vis[next]){
            start_num = next; //起點
            stk.push(start_num); 
            stk.push(now); //因為 before_vertice[next] = before_vertice[start_num] = -1
            return true;
        }
    }
    return false;
}

bool visiting(){
    for(int i=1 ; i<=vertice_num ; i++){
        if(!vis2[i]){ //沒被拜訪過
            vis[i]=1;
            vis2[i]=1;
            if(dfs(i,-1)) return true;
            vis[i]=0;
            //else memset(vis,0,vertice_num+1);
        }
    }
    return false;
}

void print_ans(){
    //stack
    cout << stk.size() << endl; 
    while(!stk.empty()){
        int now = stk.top();
        stk.pop();
        cout << now << ' ';
    }
}