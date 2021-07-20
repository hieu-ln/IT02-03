#include <iostream>
#include <conio.h>
using namespace std;
int const MAXSIZE = 100;
int front;
int rear;

void init(int a[], int &front, int &rear)
{
	front = -1;
	rear = -1;
}
bool isFull(int a[], int rear)
{
	if(rear == MAXSIZE - 1)
		return true;
	return false;
}
bool isEmpty(int a[], int front, int rear)
{
	if(front == - 1 && rear == -1)
		return true;
	return false;
}
int Push(int a[], int &front, int &rear, int x)
{
	if (rear - front == MAXSIZE - 1) 
		return 0;
	else
	{
		if (front == -1) 
			front = 0;
		if (rear == MAXSIZE - 1) 
		{
			for(int i = front; i<=rear; i++) 
				a[i-front]=a[i];
			rear = MAXSIZE -1-front;
			front = 0; 
		}
		a[++rear] = x;
		return 1;
	}
}
int Pop(int a[], int &x, int &front, int &rear)
{
	if (front != -1)
	{
		x = a[front];
		if (front == rear) 
		{
			front = - 1;
			rear = -1;
		}
		else 
		{
			front++;
			if (front > MAXSIZE -1) 
				front = 0;
		}
		return 1;
	} return 0;
}
void xuat(int a[], int front, int rear)
{
	for(int i = front; i <= rear; i++)
		cout << a[i] << "\t";
	cout << endl;
}
int main()
{
	int x, chon, a[MAXSIZE];
	bool in = false;
	do{
		system("cls");
		cout << "Menu\n";
		cout << "1. Tao queue rong\n"
			 << "2. Ktra queue rong\n"
			 << "3. Ktra queue day\n"
			 << "4. Them 1 phan tu\n"
			 << "5. Xoa 1 phan tu\n"
			 << "6. xuat\n"
			 << "7. Thoat\n";
		cout << "Ban chon: ";
		cin >> chon;
		switch(chon)
		{
		case 1:
			init(a,front,rear);
			cout << "Tao danh sach thanh cong\n";
			in = true;
			break;
		case 2:
			if(in == true)
			{
				if(isEmpty(a,front,rear) == true)
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
				if(isFull(a,rear) == true)
					cout << "Queue day\n";
				else
					cout << "Queue chua day\n";
			}
			else
				cout << "Chua tao danh sach\n";
			break;
		case 4:
			if(in == true)
			{
				cout << "Nhap vao 1 gia tri can them: ";
				cin >> x;
				int tam1 = Push(a,front,rear,x);
				if(tam1 != 0)
					cout << "Them thanh cong\n";
				else
					cout << "Queue da day\n";
			}
			else
				cout << "Chua tao danh sach\n";
			break;
		case 5:
			if(in == true)
			{
				int tam2 = Pop(a,x,front,rear);
				if(tam2 != 0)
					cout << "xoa thanh cong\n";
				else
					cout << "Queue rong\n";
			}
			else
				cout << "Chua tao danh sach\n";
			break;
		case 6:
			if(in == true)
				if(front == -1 && rear == -1)
					cout << "Queue rong\n";
				else
					xuat(a,front,rear);
			else
				cout << "Chua tao danh sach\n";
			break;
		default:
			cout << "Ban chon thoat\n";
		}
		_getch();
	}while(chon >= 1 && chon <= 6);
	return 0;
}