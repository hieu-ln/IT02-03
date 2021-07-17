//CTDL & GT _ bai lam them _ bai 13
#include<iostream>
#include <conio.h>
using namespace std;
const int MAXSIZE = 101;

void khoitao(double a[],int n)
{
	for(int i = 0; i <= n; i++)
		a[i] = 0;
}
void nhapDathuc(double a[], int n, char kt)
{
		for(int i = n; i >= 0; i--)
	{
		cout << "Nhap vao he so " << kt << " : ";
		cin >> a[i];
		kt++;
	}
}
void xuatDathuc(double a[], int n)
{
		for(int i = n; i >= 0; i--)
	{
		if(i == n)
			cout << a[i] << "x^" << i;
		else
			if(i == 0)
			{
				if(a[i] >= 0)
					cout << " + " << a[i];
				else
					cout << " " << a[i];
				cout << endl;
			}
			else
				if(a[i] >= 0)
					cout << " + " << a[i] << "x^" << i;
				else
					cout << " " << a[i]<< "x^" << i;
	}
}
void copy(double a[],double b[], int n)
{
	for(int i = 0; i <= n; i++)
		b[i] = a[i];
}
void tichDathuc(double a[], double b[], double c[], int n, int m)
{
	for(int i = n; i >= 0; i--)
		for(int j = m; j >= 0; j--)
			c[i+j] += (a[i] * b[j]);
}
void tongDathuc(double a[], double b[],double c[],int n, int m)
{
	if(n >= m)
	{
		copy(a,c,n);
		for(int i = m; i >= 0; i--)
			c[i] += b[i];
	}
	else
	{
		copy(b,c,m);
		for(int i = n; i >= 0; i--)
			c[i] += a[i];
	}
}
void hieuDathuc(double a[], double b[],double c[],int n, int m)
{
	if(n >= m)
	{
		copy(a,c,n);
		for(int i = m; i >= 0; i--)
			c[i] -= b[i];
	}
	else
	{
		copy(b,c,m);
		for(int i = n; i >= 0; i--)
			c[i] -= a[i];
	}
}
void thuongDathuc(double a[], double b[], double c[], int n, int m, int k)
{
	double tam[MAXSIZE], d[MAXSIZE] = {0};
	int j = 0;
	copy(a,tam,n);
	c[k] = tam[n] / b[m];
	for(int i = m; i >= 0; i--)
	{
		int e = n - j;
		d[e] = c[k] * b[i];
		j++;
	}
	k--;
	j = 0;
	while(k >= 0)
	{
		for(int i = n; i >= 0; i--)
			tam[i] = tam[i] - d[i];
		n--;
		c[k] = tam[n] / b[m];
		for(int i = m; i >= 0; i--)
		{
			int e = n - j;
			d[e] = c[k] * b[m];
			j++;
		}
		j = 0;
		k--;
	}
}
int main()
{
	double a[MAXSIZE], b[MAXSIZE], tong[MAXSIZE], tich[MAXSIZE], hieu[MAXSIZE], thuong[MAXSIZE];
	int n, m, chon;
	char kt = 'a';
	do{
		system("cls");
		cout << "Menu\n";
		cout << "1. Tong\n2. Hieu\n3. Tich\n4. Thuong\n5. Thoat\n";
		cout << "Ban chon: ";
		cin >> chon;
		if(chon >= 5)
		{
			cout << "Ban chon thoat\n";
			break;
		}
		//da thuc 1
		do{
			cout << "Nhap vao cap cua da thu thu 1: ";
			cin >> n;
			if(n <= 0 || n >= MAXSIZE)
				cout << "Nhap sai.Nhap lai\n";
		}while(n <= 0 || n >= MAXSIZE);
		cout << "Nhap da thuc thu 1:\n";
		nhapDathuc(a,n,kt);
		xuatDathuc(a,n);
		//da thuc 2
		do{
			cout << "Nhap vao cap cua da thu thu 2: ";
			cin >> m;
			if(m <= 0 || m >= MAXSIZE)
				cout << "Nhap sai.Nhap lai\n";
		}while(m <= 0 || m >= MAXSIZE);
		cout << "Nhap da thuc thu 2:\n";
		nhapDathuc(b,m,kt);
		xuatDathuc(b,m);
		switch(chon)
		{
		case 1:
			tongDathuc(a,b,tong,n,m);
			cout << "Tong 2 da thuc: ";
			if(n >= m)
				xuatDathuc(tong,n);
			else
				xuatDathuc(tong,m);
			break;
		case 2:
			hieuDathuc(a,b,hieu,n,m);
			cout << "Hieu 2 da thuc: ";
			if(n >= m)
				xuatDathuc(hieu,n);
			else
				xuatDathuc(hieu,m);
			break;
		case 3:
			khoitao(tich,n + m);
			tichDathuc(a,b,tich,n,m);
			cout << "Tich 2 da thuc: ";
			xuatDathuc(tich,n + m);
			break;
		case 4:
			if(n < m)
				cout << "Cap da thuc 1 phai lon hoan cap da thuc 2\n";
			else
			{
				int k = n - m;
				thuongDathuc(a,b,thuong,n,m,k);
				cout << "Thuong 2 da thuc la: ";
				xuatDathuc(thuong,k);
			}
			break;
		}
		_getch();
	}while(chon >= 1 && chon <= 4);
	return 0;
}