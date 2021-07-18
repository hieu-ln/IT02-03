#include <iostream>
#include <conio.h>
using namespace std;

#define MAX1 100
#define MAX2 100

void input(int g[], int n);
void output(int g[], int n);
void PhanGiao(int g[], int a[],int b[], int n, int m);
void PhanBu(int u[], int a[], int b[], int n, int m);
void MENU();
int main()
{
	
	MENU();

	system("pause");
	return 0;
}

void input(int g[], int n)
{
		for (int i = 0; i < n; i++)
		{
			cout << " nhap phan tu thu " << i + 1 << " la:";
			cin >> g[i];
		}
	
	
}

void output(int g[], int n)
{
        for (int i = 0; i < n;i++)
			cout << g[i]<<", ";
			cout << endl;
		
}
void PhanGiao(int g[], int a[], int b[], int n, int m)
{
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			if (a[i] == b[j]) {
				g[i] = a[i];
				cout << g[i] << ", ";
			}
				
		}
	}
	cout << endl;
}
void PhanBu(int u[], int a[], int b[], int n, int m)
{
	

	
	int h = 0;
	for (int i = 0; i < n; i++)
	{
		u[i] = a[i];
		h++;
	}
	for (int i = 0;i < m; i++)
	{
		u[i + n] = b[i];
		h++;
	}

	for (int i = 0; i < n + m - 1;i++)
	{
		if (u[i] == u[i + 1])
			for (int j = i; j = n + m - 1; j++)
			{
				u[j] = u[j + 1];
				h--;
			}
	}
	for (int i = 1; i < h; i++)
		for (int j = 0;j < i; j++)
			if (u[i] == u[j])
			{
				for (int k = i; k < h;k++)
					u[k] = u[k + 1];
				for (int k = j; k < h - 1; k++)
					u[k] = u[k + 1];
				h=h-2;
				i=i-2;

			}
	
	    

			for (int i = 0; i < h;i++)
				cout << u[i] << ", ";
	cout << endl;
	
		
}
void MENU()
{ 
	int a[MAX1];
	int b[MAX2];
	int g[MAX1];
	int u[MAX1 + MAX2];
	int c, d;
	cout << " nhap so luong phan tu thu nhat: ";
	cin >> c;
	input(a, c);
	cout << " nhap so luong phan tu thu hai: ";
	cin >> d;
	input(b, d);

	int chon;
	do {
		system("cls");
		cout << "1. xuat phan tu trong danh sach thu nhat \n2. Xuat phan tu trong danh sach thu hai \n3. phan giao cua hai danh sach \n4.phan bu cua hai danh sach \n5.thoat\nBan chon: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
			cout << "phan tu trong danh sach thu nhat la: ";
			output(a, c);
			break;
		case 2:
			cout << " phan tu trong danh sach thu hai la: ";
			output(b, d);
			break;
		case 3:
			cout << " phan giao cua hai danh sach la: ";
			PhanGiao(g, a, b, c, d);
			break;
		case 4:
			cout << "phan bu cua hai danh sach la: ";
			PhanBu(u, a, b, c, d);
			break;
		default:
			cout << "Chao tam biet !!! " << endl;
			break;
		}
		_getch();
	} while (chon >0 && chon <5);
}


