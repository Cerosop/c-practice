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
		vec.push_back(i);							//在最後面的位置輸入i 
	}
	reverse(vec.begin(), vec.end());				//使vec陣列前後反轉 
	for (int i = 0; i < 10; i ++)
	{
		cout << arr[i] << ' ' << vec[i] << endl;	
	}
	vec.insert(vec.begin()+2, 3);						//在vec[2]及vec[1]之間插入3 
	cout << vec[2]<<' ';  //3 
	cout << vec[1];  //8
	return 0;
}
