#include<iostream>
using namespace std;

int c[100] = {0};
int w[100] = {0};

int back(int i, int v){
	if(i>0 && v >= w[i])
	return max(back(i-1, v), back(i-1, v-w[i]) + c[i]);
	else if(i > 0)
	return back(i-1, v);
	else if(v >= w[i])
	return c[i];
	else
	return 0;
}

int main(){
	int i = 0;
	int v = 100;
	int n = 0;
	while(cin>>n){
		for(i = 0; i < n; i++){
			cin>>w[i]>>c[i];
		}
		cout<<back(i-1, v)<<"\n";
	}
}
