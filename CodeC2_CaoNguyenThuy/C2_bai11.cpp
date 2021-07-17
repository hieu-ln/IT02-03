//chuong 2 bai 11
#include <iostream>
#include <conio.h>
using namespace std;

struct Node
{
	int info;
	Node *link;
};
Node * front, *rear;
void init()
{
	 front= NULL;
	 rear= NULL;
}
void Push(int x)
{
	Node *p;
	p = new Node;
	p->info = x;
	p->link = NULL;	
	if (rear == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}
int Pop(int &x)
{
	if (front!= NULL)
	{
		Node *p = front;
		x = p -> info;
		front = front ->link;
		if (front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}
int isEmpty()
{
	if (front == NULL)
		return 1;
	return 0;	
}
void xuat()
{
	Node *p = front;
	while(p != NULL)
	{
		cout << p->info << "\t";
		p = p->link;
	}
}
int main()
{
	int x, chon;
	bool in = false;
	do{
		system("cls");
		cout << "Menu\n";
		cout << "1. Tao queue rong\n"
			 << "2. Ktra queue rong\n"
			 << "3. Them 1 phan tu\n"
			 << "4. Xoa 1 phan tu\n"
			 << "5. xuat\n"
			 << "6. Thoat\n";
		cout << "Ban chon: ";
		cin >> chon;
		switch(chon)
		{
		case 1:
			init();
			cout << "Tao danh sach thanh cong\n";
			in = true;
			break;
		case 2:
			if(in == true)
			{
				if(isEmpty() == 1)
					cout << "Queue rong\n";
				else
					cout << "Queue khong rong\n";
			}
			else
				cout << "Chua tao danh sach\n";
			break;
		case 3:
			if(in == true)
			{
				cout << "Nhap vao 1 gia tri can them: ";
				cin >> x;
				Push(x);
				cout << "Them thanh cong\n";
			}
			else
				cout << "Chua tao danh sach\n";
			break;
		case 4:
			if(in == true)
			{
				Pop(x);
				cout << "xoa thanh cong\n";
			}
			else
				cout << "Chua tao danh sach\n";
			break;
		case 5:
			if(in == true)
				if(front == NULL && rear == NULL)
					cout << "Queue rong\n";
				else
					xuat();
			else
				cout << "Chua tao danh sach\n";
			break;
		default:
			cout << "Ban chon thoat\n";
		}
		_getch();
	}while(chon >= 1 && chon <= 5);
	return 0;
}