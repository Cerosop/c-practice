//032801
#include<bits/stdc++.h>
using namespace std;
#define ROW 2
#define COL 4

double average(int arr[ROW][COL]){
    double sum = 0;
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            sum += arr[i][j];
        }
    }
    return sum / (ROW * COL);
}

int main(){
    int arr[ROW][COL] = {{2, 3, 4, 5}, 
                        {6, 7, 8, 9}};
    cout<<"the average of arr is "<<average(arr);
}