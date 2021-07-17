#include<iostream>
#include<conio.h>
using namespace std;
#define MAX 100

struct Node
{
	int info;
	Node* link;
};
Node* front, * rear;

void init()
{
	front = NULL;
	rear = NULL;
}


int isEmpty()
{
	if (front == NULL)
	{
		return 1;
	}
	return 0;
}

void Push(int x)
{
	Node* p;
	p = new Node;
	p->info = x;
	p->link = NULL;
	if (rear == NULL)
	{
		front = p;
	}
	else
	{
		rear->link = p;
	}
	rear = p;
}

int Pop()
{
	if (front != NULL)
	{
		Node* p = front;
		front = front->link;
		if (front == NULL)
		{
			rear = NULL;
		}
		delete p;
		return 1;
	}
	return 0;
}



int main()
{
	int x;
	int chon;
	bool in = false;
	do
	{
		system("cls");
		
		cout << "1. Khoi tao danh sach rong\n"
			<< "2. Kiem tra danh sach rong\n"
			<< "3. Them mot phan tu vao danh sach\n"
			<< "4. Xoa mot phan tu trong danh sach\n"
			<< "0. Thoat\n";
		cout << "Ban chon: "; cin >> chon;
		switch (chon)
		{
		case 1:
			init();
			in = true;
			cout << "Khoi tao danh sach thanh cong\n";
			break;
		case 2:
			if (in)
			{
				if (isEmpty() == 1)
				{
					cout << "Danh sach rong\n";
				}
				else
					cout << "Danh sach khong rong\n";
			}
			else
				cout << "Ban chua khoi tao danh sach\n";
			break;
		case 3:
			if (in)
			{
				cout << "Nhap gia tri can them vao danh sach: ";
				cin >> x;
				Push(x);
				cout << "Them thanh cong\n";
			}
			else
				cout << "Ban chua khoi tao danh sach\n";
			break;
		case 4: 
			if (in)
			{
				if (Pop() == 1)
				{
					cout << "Xoa thanh cong\n";
					//cout << x;
				}
				else
					cout << "Xoa khong thanh cong\n";
			}
			else
				cout << "Ban chua khoi tao danh sach\n";
			break;
		
		default:
			cout << "Ban chon thoat\n";
			break;
		}
		_getch();
	} while (chon >=1 && chon <= 5);
	
}