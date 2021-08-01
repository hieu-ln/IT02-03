#include <iostream>
#include <conio.h>
using namespace std;
const int MAX = 100;
void init (int a[], int &sp)
{
	sp = -1;
}
void nhap(int a[], int &sp)
{
	for (int i = 0 ; i < sp ; i++)
		{
			cout << "Nhap phan tu thu " << i << ":";
			cin >> a[i];
		}
}
void xuat(int a[], int sp)
{
	for (int i = sp-1 ; i >= 0  ; i--)
				cout << a[i] << endl;
		cout << endl;
}
int ktStackRong (int a[], int sp)
{
	if (sp == -1)
		return 1;
	return 0;
}
int ktStackDay (int a[], int sp)
{
	if (sp == MAX -1)
		return 1;
	return 0;
}
int them(int a[], int &sp, int x)
{
	if(sp < MAX -1)
	{
		a[sp++] = x;
		return 1;
	}
	return 0;
}
int xoa (int a[] , int &sp, int &x)
{
	if (sp != 1)
	{
		x = a[sp--];
		return 1;
	}
	return 0;
}
int main()
{
	int a[MAX];
	int sp,chon,x;
	bool check = false;
	init (a,sp);
	do{
	system("cls");
	cout <<"BAI TAP CHUONG 2\n";
	cout <<"1.nhap stack\n";
	cout <<"2.xuat stack\n";
	cout <<"3.kiem tra stack rong\n";
	cout <<"4.kiem tra stack day\n";
	cout <<"5.them 1 phan tu vao stack\n";
	cout <<"6.xoa 1 phan tu ra khoi stack\n";
	cout <<"7.ban chon thoat\n";
	cout <<"ban chon: ";
	cin >> chon;
	switch (chon)
	{
	case 1:
		cout << "nhap so phan tu cho stack: ";
		cin >> sp;
		nhap(a,sp);
		check = true;
		break;
	case 2:
		if(check)
		{
			xuat(a,sp);
		}
		else
			cout << "vui long nhap gia tri stack\n";
		break;
	case 3:
		if(ktStackRong(a,sp) == 1)
			cout << "Stack rong!\n";
		else
			cout << "Stack dang chua cac gia tri phan tu\n";
		break;
	case 4:
		if(ktStackDay(a,sp) == 1)
			cout << "Stack day!\n";
		else
			cout << "Stack chua day\n";
		break;
	case 5:
		cout <<"nhap gia tri can them:";
		cin >> x;
		if( them(a,sp,x) == 1)
			cout << "them thanh cong\n";
		else
			cout << "khong the them phan tu\n";
		break;
	case 6:
		if(ktStackRong(a,sp) == 1)
			cout << "khong the xoa \n";
		else
			xoa(a,sp,x);
		break;
	default:
		cout << "Ban chon thoat\n";
	}
	_getch();
	}while(chon >= 1 && chon <= 6);
	return 0;
}
