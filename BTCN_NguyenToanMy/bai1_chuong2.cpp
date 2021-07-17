#include <iostream>
#include <conio.h>
using namespace std;

struct Node
{
	int giatri;
	Node *next;
	Node *pre;
};
Node *first , *last;
void init()
{
	first = NULL;
	last = NULL;
}
void chentruoc (int x)
{
	Node *p = new Node;
	p->giatri = x;
	p->next = first;
	p->pre = NULL;
	if ( first != NULL)
	{
		first->pre = p;
	}
	else
		last = p;
	first = p;
}
void chensau (int x)
{
	Node *p = new Node;
	p->giatri = x;
	p->next = NULL;
	p->pre = last;
	if (last != NULL)
	{
		last ->next = p;
	}
	else
		first = p;
	last = p;
}
void xuat ()
{
	Node *p = first;
	while (p != NULL)
	{
		cout << p ->giatri << "\t";
		p = p->next;
	}
}
int timgiatri (int x)
{
	Node *p = first;
	int i = 0;
	while (p != NULL && p->giatri != x)
	{
		i++;
		p = p->next;
	}
	if (p != NULL)
		return i;
	return -1;
}
int xoadau ()
{
	if (first != NULL)
	{
		Node* p = first; 
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
int xoacuoi ()
{
	if (last != NULL)
	{
		Node *p = last;
		last = last->pre;
		if (last != NULL)
			last ->next = NULL;
		else
			first = NULL;
		delete p;
		return 1;
	}
	return 0;
}
int xoatai1diem(int k)
{
	Node* p = first;
	if (p != NULL)
	{
		for (int i = 0; i < k - 1; i++)
		{
			p = p->next;     
		}
		Node* temp = p->next; 
		Node* p2 = temp->next;
		p->next = p2;
		p2->pre = p;
		delete(temp);
		return 1;
	}
	return 0;
}
int timvaxoa (int x, int n)
{
	if (timgiatri(x) == 1)
	{
		return xoadau();
	}
	else if (timgiatri(x) == n)
	{
		return xoacuoi();
	}
	else {
		return xoatai1diem(timgiatri(x)+1);
	}
	return 0;
}
int main()
{
	int n,x,chon,k;
	bool check = false;
	init();
	do{
	system("cls");
	cout <<"BAI THUC HANH 1\n";
	cout <<"1.Nhap danh sach\n";
	cout <<"2.Xuat danh sach\n";
	cout <<"3.Tim mot phan tu trong danh sach\n";
	cout <<"4.Them phan tu vao cuoi danh sach\n";
	cout <<"5.Xoa phan tu cuoi danh sach\n";
	cout <<"6.Xoa phan tu tai vi tri bat ki\n";
	cout <<"7.Tim mot phan tu trong danh sach roi xoa\n";
	cout <<"8.Ban chon thoat\n";
	cout <<"Ban chon: ";
	cin >> chon;
	switch (chon)
	{
	case 1:
		cout <<"Nhap so phan tu: ";
		cin >> n;
		for (int i = 0 ; i < n ; i++)
		{
			cout << "Nhap phan tu thu " << i+1 <<": ";
			cin >> x;
			chensau(x);
		}
		check = true;
		break;
	case 2:
		if (check)
			xuat();
		else
			cout <<"Vui long nhap danh sach\n";
		break;
	case 3:
		if(check)
		{
			cout << "Nhap gia tri can tim: ";
			cin >> x;
			if (timgiatri(x) != -1)
				cout << "tim thay " << x << " tai vi tri thu " << timgiatri(x)+1 <<"\n";
			else
				cout << "khong tim thay gia tri\n";
		}
		else
			cout <<"Vui long nhap danh sach\n";
		break;
	case 4:
		if(check)
		{
			cout <<"Nhap gia tri can chen: ";
			cin >> x;
			chensau(x);
			xuat();
		}
		else
			cout <<"Vui long nhap danh sach\n";
		break;
	case 5:
		if(check)
		{
			xoacuoi();
			xuat();
		}
		else
			cout <<"Vui long nhap danh sach\n";
		break;
	case 6:
		if(check)
		{
			cout <<"Nhap vi tri can xoa: ";
			cin >> k;
			xoatai1diem(k);
		}
		else
			cout <<"Vui long nhap danh sach\n";
		break;
	case 7:
		if(check)
		{
			cout <<"Nhap vi tri can tim: ";
			cin >> k;
			timvaxoa(x,n);
			xuat();
		}
		else
			cout <<"Vui long nhap danh sach\n";
		break;
	default:
		cout << "Ban chon thoat!\n";
	}
	_getch();
	}while(chon >= 1 && chon <= 7);

	return 0;
}