#include <iostream>
using namespace std;

struct Test
{
	int num1 = 0, num2 = 0;
	Test *next = NULL;
};

int main()
{
	Test head, *current;
	current = &head;
	
	for (int i = 0; i < 3; i ++)
	{
		Test *tmp = new Test;
		cin >> tmp -> num1 >> tmp -> num2;
		current -> next = tmp;
		current = current -> next;
	}
	
	current = head.next;
	
	for (int i = 0; i < 3; i ++)
	{
		cout << current -> num1 << ' ' << current -> num2 << endl;
		current = current -> next;
	}
	
	return 0;
} 
