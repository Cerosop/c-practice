#include<bits/stdc++.h>
using namespace std;
int main(){
    int a, b, maze[102][102];
    cin>>a>>b;
    for(int j = 0; j <= b + 1; j++){
        maze[0][j] = 1;
    }
    for(int i = 1; i <= a; i++){
        maze[i][0] = 1;
        for(int j = 1; j <= b; j++){
            cin>>maze[i][j];
        }
        maze[i][b + 1] = 1;
    }
    for(int j = 0; j <= b + 1; j++){
        maze[a + 1][j] = 1;
    }
    stack<tuple<int, int, int>> road;
    int x = 1, y = 1, dir = 0;
    int xmove[4] = {0, 1, 0, -1}, ymove[4] = {1, 0, -1, 0};
    bool found = false;
    while(!found){
        int check = 0;
        while(dir < 4){
            if(maze[y + ymove[dir]][x + xmove[dir]] == 0){
                road.push(make_tuple(y, x, dir));
                maze[y][x] = 1;
                x = x + xmove[dir];
                y = y + ymove[dir];
                dir = 0;
                check = 1;
                break;
            }
            dir++;
        }
        if (!check){
            if(road.empty()){
                cout<<"Can't reach the exit!";
                break;
            }
            tie(y, x, dir) = road.top();
            road.pop();
            dir++;
        }
        else if(y == a && x == b){
            found = true;
            road.push(make_tuple(y, x, dir));
        }
    }
    stack<pair<int, int>> output;
    while(!road.empty()){
        output.push(make_pair(get<0>(road.top()), get<1>(road.top())));
        road.pop();
    }
    while (!output.empty()){
        cout<<"("<<output.top().first - 1<<","<<output.top().second - 1<<") ";
        output.pop();
    }
    
}