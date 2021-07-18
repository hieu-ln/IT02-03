#include <iostream>
#include <conio.h>
using namespace std;

struct Node
{
	int info;
	Node* link;
};
Node* sp; // câu 10.1
void init()
{
	sp = NULL;
} // câu 10.2
int isEmpty()
{
	if (sp == NULL)
		return 1;
	return 0;
} // câu 10.3
void Push(int x)
{
	Node* p;
	p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
} // câu 10.4
int Pop(int& x)
{
	if (sp != NULL)
	{
		Node* p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
} // câu 10.5
void changeBinary(int decimal)
{
	int x;
	while (decimal != 0)
	{
		x = decimal % 2;
		Push(x);
		decimal /= 2;
	}
} // câu 10.6
void Output()
{
	while (isEmpty() == 0)
	{
		char a = 'A';
		int x;
		Pop(x);
		if (x < 10)
			cout << x;
		else
			cout << char(a - 10 + x);
	}
}

int main()
{
	int x;
	cout << "Input a value that you want to change into binary: ";
	cin >> x;
	changeBinary(x);
	cout << "Result after change: ";
	Output();
	return 0;
}