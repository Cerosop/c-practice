/*
 * @Author: Cerosop jmhsu920816@gmail.com
 * @Date: 2022-12-07 14:01:59
 * @LastEditors: Cerosop jmhsu920816@gmail.com
 * @LastEditTime: 2023-03-20 00:41:23
 * @FilePath: \c++\test1.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int matrixChainMultiplication(vector<pair<int,int>>& matrices) {
    int n = matrices.size();
    vector<vector<int>> M(n, vector<int>(n, 0));
    vector<vector<int>> s(n, vector<int>(n, -1));
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            M[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = M[i][k] + M[k+1][j] + matrices[i].first * matrices[k].second * matrices[j].second;
                if(cost < M[i][j]){
                    M[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            cout<<M[i][j]<<" ";
        
        }
        cout<<"\n";
    }
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            cout<<s[i][j]<<" ";
        
        }
        cout<<"\n";
    }
    return M[0][n-1];
}

int main() {
    vector<pair<int,int>> matrices = {{5, 10}, {10, 3}, {3, 12}, {12, 5}, {5, 50}, {50, 6}};
    int result = matrixChainMultiplication(matrices);
    cout << "Minimum number of scalar multiplications: " << result << endl;
    return 0;
}
