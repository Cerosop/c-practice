#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a[1000],n,i=0;
	long long int x=0,y=0;
	cin>>n;
	while(i<n)
	{
		cin>>a[i];
		i++;
	}
	sort(a,a+n);
	i=0;
	while(i<n-1)
	{
		y=a[0]+a[1];
		x=x+y;
		a[0]=y;
		a[1]=10001;
		sort(a,a+n);
		i++;
	}
	cout<<x;
} 
