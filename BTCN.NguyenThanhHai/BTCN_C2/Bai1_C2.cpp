#include<iostream>
#include <conio.h>
using namespace std;

struct node
{
	int data;
	node* next;
	node* pre;
};
node* first, *last;
void init()
{
	first = NULL;
	last = NULL;
}
void insert_First(int x)
{
	node* p = new node;
	p->data = x;
	p->next = NULL;
	p->pre = NULL;
	if (first != NULL)
	{
		first->pre = p;
	}
	else {
		last = p;
	}
	first = p;

}
void insert_Last(int x)
{
	node* p = new node;
	p->data = x;
	p->next = NULL;
	p->pre = last;
	if (last != NULL)
		last->next = p;
	else
		first = p;
	last = p;
}
void insert_At(int k, int x)
{
	node* p = first;
	if (p != NULL)
	{
		for (int i = 0; i < k - 1; i++)
		{
			p = p->next;
		}
		node* temp = new node;
		temp->data = x;
		temp->next = p->next;
		temp->pre = p;
		p->next->pre = temp;
		p->next = temp;
	}
}
void printProccess()
{
	node* p = first;
	while (p != NULL)
	{
		cout << p->data << "\t";
		p = p->next;
	}
}
int deleteAt(int k)
{
	node* p = first;
	if (p != NULL)
	{
		for (int i = 0; i < k - 1; i++)
		{
			p = p->next;
		}
		node* temp = p->next;
		node* p2 = temp->next;
		p->next = p2;
		p2->pre = p;
		delete(temp);
		return 1;
	}
	return 0;
}
int deleteFirst()
{
	if (first != NULL)
	{
		node* p = first;
		first = first->next;
		delete(p);
		if (first != NULL)
		{
			first->pre = NULL;
		}
		else {
			last = NULL;
		}
		return 1;
	}
	return 0;
}
int deleteLast()
{
	if (last != NULL)
	{
		node* p = last;
		last = last->pre;
		delete(p);
		if (last != NULL)
		{
			last->next = NULL;
		}
		else {
			first = NULL;
		}
		return 1;
	}
	return 0;
}
int search(int x)
{
	int i = 0;
	node* p = first;
	while (p != NULL && p->data != x)
	{
		i++;
		p = p->next;
	}
	if (p != NULL)
		return i;
	return -1;
}
int Search_Delete(int x, int n)
{
	if (search(x) == 0)
		return deleteFirst();
	else
		if (search(x) == n - 1)
			return deleteLast();
		else
			return deleteAt(search(x));
	return 0;
}
int main()
{
	int n, x, chon;
	int k;
	bool in = false;
	init();
	do {
		system("cls");
		cout << "Menu\n";
		cout << "1.Tao danh sach\n"
			<< "2.Xuat danh sach\n"
			<< "3.Tim kiem\n"
			<< "4.Them vao cuoi\n"
			<< "5.Xoa cuoi\n"
			<< "6.Xoa gia tri o vi tri tuong ung\n"
			<< "7.Tim va xoa\n"
			<< "8.Thoat\n";
		cout << "Ban chon: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
			cout << "Nhap so luong phan tu: ";
			cin >> n;
			for (int i = 0; i < n; i++)
			{
				cout << "Nhap vao phan tu thu: " << i + 1 << ": ";
				cin >> x;
				insert_Last(x);
			}
			in = true;
			break;
		case 2:
			if (in)
			{
				printProccess();
				cout << endl;
			}
			else
				cout << "Chua tao danh sach\n";
			break;
		case 3:
			if (in)
			{
				cout << "Nhap vao gia tri can tim: ";
				cin >> x;
				if (search(x) != -1)
					cout << "Gia tri " << x << "  xua hien o dia chi " << search(x) << ".\n";
				else
					cout << "Khong ton tai gia tri " << x << endl;
			}
			else
				cout << "Chua tao danh sach\n";
			break;
		case 4:
			if (in)
			{
				cout << "Nhap vao gia tri can them vao cuoi: ";
				cin >> x;
				insert_Last(x);
			}
			else
				cout << "Chua tao danh sach\n";
			break;
		case 5:
			if (in)
			{
				if (deleteLast())
					cout << "Xoa thanh cong\n";
				else
					cout << "Xoa khong thanh cong!\n";
			}
			else
				cout << "Chua tao danh sach\n";
			break;
		case 6:
			if (in)
			{
				do {
					cout << "Nhap vao vi tri can xoa: ";
					cin >> k;
					if (k > n)
						cout << "Vi tri khong ton tai\n";
				} while (k > n);
				deleteAt(k);
			}
			else
				cout << "Chua tao danh sach\n";
			break;
		case 7:
			if (in)
			{
				cout << "Nhap vao gia tri can xoa: ";
				cin >> x;
				Search_Delete(x, n);
				cout << "Xoa thanh cong\n";
			}
			else
				cout << "Chua tao danh sach\n";
			break;
		default:
			cout << "Ban chon thoat";
		}
		_getch();
	} while (chon >= 1 && chon <= 7);
	return 0;
}