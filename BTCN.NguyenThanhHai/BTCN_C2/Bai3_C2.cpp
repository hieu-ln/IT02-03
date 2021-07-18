#include <iostream>
#include <conio.h>
using namespace std;

struct Node
{
	int info;
	Node *link;
};
Node * first;
void init()
{
	first = NULL;
}
void Process_list()
{
	Node *p;
	p = first;
	while (p != NULL)
	{
		cout << p->info << "\t";
		p = p->link;
	}
}
void Insert_last(int x)
{
	Node *p;
	p = new Node;
	p->info = x;
	p->link = NULL;
	if (first == NULL)
		first = p;
	else
	{
		Node *q = first;
		while (q->link != NULL)
			q = q->link;
		q->link = p;
	}
}
int Search(int x)
{
	Node *p = first;
	int i = 0;
	while ((p != NULL) && (p->info != x))
	{
		i++;
		p = p->link;
	}
	if (p != NULL)
		return i;
	return -1;
}
void Insert_first(int x)
{
	Node *p;
	p = new Node;
	p->info = x;
	p->link = first;
	first = p;
}
int Delete_first()
{
	if (first != NULL)
	{
		Node *p = first;
		first = first->link;
		delete p;
		return 1;
	}
	return 0;
}
int Delete_last()
{
	if (first != NULL)
	{
		Node *p, *q;
		p = first; q = NULL;
		if (p != NULL)
			while (p->link != NULL)
			{
				q = p; p = p->link;
			}
		if (p != first)
			q->link = NULL;
		else   first = NULL;
		delete p;
		return 1;
	}
	return 0;
}
void Delete_At(int k)
{
	Node *p = first;
	for (int i = 0; i < k - 1; i++)
		p = p->link;
	Node* temp = p->link;
	Node* p2 = temp->link;
	p->link = p2;
	delete(temp);
}
int main()
{
	int n, x, y, chon;
	bool in = false;
	do {
		system("cls");
		cout << "Menu\n";
		cout << "1. Khoi tao danh sach va nhap phan tu\n"
			<< "2. Xuat dan sach\n"
			<< "3. Tim 1 phan tu trong danh sach\n"
			<< "4. Them dau\n"
			<< "5. Them cuoi\n"
			<< "6. Xoa dau\n"
			<< "7. Xoa cuoi\n"
			<< "8. Tim kiem va xoa\n"
			<< "9. Thoat\n";
		cout << "Ban chon: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
			init();
			cout << "Nhap vao so phan tu cua danh sach: ";
			cin >> n;
			for (int i = 0; i < n; i++)
			{
				cout << "Nhap vao phan tu thu: " << i + 1 << ": ";
				cin >> y;
				Insert_last(y);
			}
			in = true;
			break;
		case 2:
			if (in == true)
				Process_list();
			else
				cout << "Chua nhap danh sach\n";
			break;
		case 3:
			if (in == true)
			{
				cout << "Nhap gia tri ban can tim: ";
				cin >> x;
				if (Search(x) != -1)
					cout << x << " xuat hien o vi tri " << Search(x) + 1 << endl;
				else
					cout << x << " khong co trong danh sach\n";
			}
			else
				cout << "Chua nhap danh sach\n";
			break;
		case 4:
			if (in == true)
			{
				cout << "Nhap gia tri ban can them vao dau: ";
				cin >> x;
				Insert_first(x);
				cout << "them thanh cong\n";
			}
			else
				cout << "Chua khoi tao danh sach\n";
			break;
		case 5:
			if (in == true)
			{
				cout << "Nhap gia tri ban can them vao cuoi: ";
				cin >> x;
				Insert_first(x);
				cout << "them thanh cong\n";
			}
			else
				cout << "Chua khoi tao danh sach\n";
			break;
		case 6:
			if (in == true)
			{
				if (Delete_first() == 1)
					cout << "Xoa thanh cong\n";
				else
					cout << "Xoa khong thanh cong\n";
			}
			else
				cout << "Chua khoi tao danh sach\n";
			break;
		case 7:
			if (in == true)
			{
				if (Delete_last() == 1)
					cout << "Xoa thanh cong\n";
				else
					cout << "Xoa khong thanh cong\n";
			}
			else
				cout << "Chua khoi tao danh sach\n";
			break;
		case 8:
			if (in == true)
			{
				cout << "Nhap gia tri ban can xoa: ";
				cin >> x;
				if (Search(x) != -1)
				{
					Delete_At(Search(x));
					cout << "Xoa thanh cong" << endl;
				}
				else
					cout << x << " khong co trong danh sach\n";
			}
			else
				cout << "Chua khoi tao danh sach\n";
			break;
		default:
			cout << "Ban chon thoat\n";
		}
		_getch();
	} while (chon >= 1 && chon <= 8);
	return 0;
}
