#include <iostream>
using namespace std;
int main()
{


////s.find( , )
	string a="987654321654";
	int i,c=1;
	string::size_type pos=a.find("8654",0);  //�q�r��a����0�Ӧr���}�l�M��O�_���ŦXabc���l�r��
	cout<<pos<<" ";  //3   pos���l�r��654�b�r��a���Ĥ@���X�{����m
	if(pos!=string::npos)  //�]�t
	cout<<"Yes";
	else if(pos==string::npos) //���]�t
	cout<<"No";

////s.rfind( )
	pos=a.rfind("654");
	cout<<" "<<pos;  //9   pos���l�r��654�b�r��a���̫�X�{����m


////s.insert( )
	a.insert(2,"456");  //�Na���J456�b��2�Ӧr������
	cout<<a<<endl;  //984567654321
	a="987654321";

////s.size( )   s.substr( , )
	i=a.size();    //�r��a������  i==9
	i--;
	while(i>=0)
	{
		cout<<a.substr(i,c);   //��Xa�r���i�Ӧr���ƨ�c�Ӧr��   //c=1  //123456789
		i--;
	}

}
