#include <iostream>
using namespace std;
int main()
{


////s.find( , )
	string a="987654321654";
	int i,c=1;
	string::size_type pos=a.find("8654",0);  //從字串a中第0個字元開始尋找是否有符合abc的子字串
	cout<<pos<<" ";  //3   pos為子字串654在字串a中第一次出現的位置
	if(pos!=string::npos)  //包含
	cout<<"Yes";
	else if(pos==string::npos) //不包含
	cout<<"No";

////s.rfind( )
	pos=a.rfind("654");
	cout<<" "<<pos;  //9   pos為子字串654在字串a中最後出現的位置


////s.insert( )
	a.insert(2,"456");  //將a插入456在第2個字元之後
	cout<<a<<endl;  //984567654321
	a="987654321";

////s.size( )   s.substr( , )
	i=a.size();    //字串a的長度  i==9
	i--;
	while(i>=0)
	{
		cout<<a.substr(i,c);   //輸出a字串第i個字元數來c個字元   //c=1  //123456789
		i--;
	}

}
