#include<iostream>  
using namespace std;  
int main()  
{  
    int a=0;
	while(1)
	{
		cout<<"1"<<endl;  //總輸出21個1 
		a++;
		if(a>20)break;  //當a>20時，跳出迴圈 
	} 
	cout<<a<<endl;  //21
	a=0;
	while(1)
	{
		cin>>a;
		if(cin.fail()) break;  //當輸入失敗或沒輸入時 ，跳出迴圈 
		cout<<a<<endl;   
	} 
}
