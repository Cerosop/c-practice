#include<bits/stdc++.h>
using namespace std;

int main(){
	cout << "遊戲: ?a?b\n";
	string ans[256];
	int que[10] = {0}, count1 = 0;
    srand(time(NULL));
    int ran = rand();
    for (int i = 0; i < 4; i ++){
        que[i] = ran % 10;
        ran = ran / 10;
        for (int j = i - 1; j >= 0; j --){
            if (que[j] == que[i]){
                que[i] ++;
                que[i] %= 10;
                j = i ;
            }
        }
    } //隨機答案生成

	for (int m = 0;; m ++){
	    int a = 0;
		int b = 0;
        count1 ++;
	    cout << "請輸入4個不同的數字:  ";
        getline(cin, ans[m]);
		while(ans[m].size() != 4 or
		ans[m][0] == ans[m][1] or
		ans[m][0] == ans[m][2] or
		ans[m][0] == ans[m][3] or
		ans[m][1] == ans[m][2] or
		ans[m][1] == ans[m][3] or
		ans[m][2] == ans[m][3] or
		ans[m][0]>'9' or ans[m][0]<'0' or
		ans[m][1]>'9' or ans[m][1]<'0' or
		ans[m][2]>'9' or ans[m][2]<'0' or
		ans[m][3]>'9' or ans[m][3]<'0'){
            cout << "請輸入[不同的][4個][數字] ";
            m ++;
            getline(cin, ans[m]);
		}  //判斷輸入格式

		for (int i = 0; i < 4; i ++){
			if(que[i] == int(ans[m][i]) - '0')
                a ++;
			else{
				for (int j = 0; j <4; j ++){
					if(que[i] == ans[m][j] - '0'){
                        b ++;
						break;
					}
				}
			}
		}  //偵測命中數量

		if(a == 4){
			cout << "bingo! " << "次數: " << count1;
			return 0;
		}
		cout << a << "a" << b << "b " << "次數: " << count1 << "\n";
	}
}
