#include <iostream>
using namespace std;
struct Node
{
	int info;
	Node* link;
};
Node* first;
int main()
{
	init();
	Process_list();
	Process_list2();
	Process_list3();
}
void init()
{
	first = NULL;
}
// 16.1
void Process_list()
{
	Node *p;
	p = first;
	while (p != NULL)
	{
		cout << p->info << endl;
		p = p -> link;
	}
	Node *q;
	q = first;
	while (q != NULL)
	{
		cout << q->info << endl;
		q = q->link;
	}
}
//16.2
void Process_list2()
{
	Node* p;
	p = first;
	Node* q;
	q = first;
	while (p != NULL && q != NULL && p->info == q->info)
	{
		cout << p->info << endl;
		p = p->link;
		q = q->link;
	}
}
// 16.3
void Process_list3()
{
	Node* p;
	p = first;
	Node* q;
	q = first;
	while (p != NULL && q != NULL && p->info != q->info)
	{
		cout << p->info << endl;
		p = p->link;
		cout << q->info << endl;
		q = q->link;
	}
}
