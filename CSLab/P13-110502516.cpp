/*
* Practice 13
* Name: 許尚軒
* Student Number: 110502516
* Course 2021-CE1003-A
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    string filename[3] = {"ox1", "ox2", "ox3"};
    for(int i = 0; i < 3; i++){
        ifstream file((filename[i] + ".txt").c_str());
        string line;
        int arr[3][3], k = 0, x = 0;
        while(getline(file, line)){
            for(int j = 0; j < 3; j++){
                if(line[j] == 'O' or line[j] == 'o')
                    arr[k][j] = 1;
                else
                    arr[k][j] = 0;
            }
            k++;
        }
        for(k = 0; k < 3; k++){
            if(arr[k][0] == arr[k][1] and arr[k][0] == arr[k][2]){
                x = arr[k][0] + 1;
                break;
            }
        }
        if(!x){
            for(k = 0; k < 3; k++){
                if(arr[0][k] == arr[1][k] and arr[0][k] == arr[2][k]){
                    x = arr[0][k] + 1;
                    break;
                }
            }
        }
        if(!x){
            if(arr[0][0] == arr[1][1] and arr[0][0] == arr[2][2])
                x = arr[0][0] + 1;
            else if(arr[2][0] == arr[1][1] and arr[2][0] == arr[0][2])
                x = arr[2][0] + 1;
        }
        if(x == 0)
            cout<<filename[i]<<": tie\n";
        else if(x == 1)
            cout<<filename[i]<<": Xwin\n";
        else
            cout<<filename[i]<<": Owin\n";
        file.close();
    }
}
