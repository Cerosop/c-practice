#include<iostream>  
using namespace std;  
int main()  
{  
    int a=0;
	while(1)
	{
		cout<<"1"<<endl;  //�`��X21��1 
		a++;
		if(a>20)break;  //��a>20�ɡA���X�j�� 
	} 
	cout<<a<<endl;  //21
	a=0;
	while(1)
	{
		cin>>a;
		if(cin.fail()) break;  //���J���ѩΨS��J�� �A���X�j�� 
		cout<<a<<endl;   
	} 
}
