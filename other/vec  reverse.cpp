#include <iostream>
#include <vector>
#include <algorithm>  //reverse
using namespace std;

int main()
{
	vector <int> vec;
	int arr[10];
	for (int i = 0; i < 10; i ++)
	{
		arr[i] = i;									
		vec.push_back(i);							//�b�̫᭱����m��Ji 
	}
	reverse(vec.begin(), vec.end());				//��vec�}�C�e����� 
	for (int i = 0; i < 10; i ++)
	{
		cout << arr[i] << ' ' << vec[i] << endl;	
	}
	vec.insert(vec.begin()+2, 3);						//�bvec[2]��vec[1]�������J3 
	cout << vec[2]<<' ';  //3 
	cout << vec[1];  //8
	return 0;
}
