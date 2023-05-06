/*
 * @Author: Cerosop jmhsu920816@gmail.com
 * @Date: 2023-04-29 18:22:29
 * @LastEditors: Cerosop jmhsu920816@gmail.com
 * @LastEditTime: 2023-05-07 02:18:07
 * @FilePath: \c++\algorithm\hw2\110502516_q1.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<bits/stdc++.h>
using namespace std;
int main(){
    int h, w, k;
    cin>>h>>w>>k;
    bool obs[h + 1][w + 1][2];
    short ans[h + 1][w + 1];
    while(k--){
        int q;
        cin>>q;
        memset(obs, 0, sizeof(obs));
        memset(ans, 0, sizeof(ans));
        while(q--){
            int a, b, c, d;
            cin>>a>>b>>c>>d;
            if(a < c)
                obs[c][d][0] = true;
            if(b < d)
                obs[c][d][1] = true;
        }
        ans[0][0] = 1;
        for(int i = 1; i <= h; i++){
            if(!obs[i][0][1])
                ans[i][0] = ans[i - 1][0];
        }
		for(int i = 1; i <= w; i++){
			if(!obs[0][i][0])
                ans[0][i] = ans[0][i - 1];
		}
        for(int i = 1; i <= h; i++){
            for(int j = 1; j <= w; j++){
                if(!obs[i][j][1])
                    ans[i][j] += ans[i][j - 1];
                if(!obs[i][j][0])
                    ans[i][j] += ans[i - 1][j];
                while(ans[i][j] >= 2552){
                    ans[i][j] -= 2552;
                }
            }
        }
        cout<<ans[h][w]<<"\n";
    }
}