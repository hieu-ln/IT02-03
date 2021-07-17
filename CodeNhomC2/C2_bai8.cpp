#include<iostream>
#include<conio.h>
using namespace std;
#define MAX 100

void init(int a[], int &sp)
{
	sp = -1;
}

int isEmpty(int a[],int sp)
{
	if(sp == -1)
		return 1;
	return 0;
}

int isFull(int a[],int sp)
{
	if(sp == MAX - 1)
		return 1;
	return 0;
}

int push(int a[],int &sp,int x)
{
	if(sp < MAX - 1)
	{
		a[++sp] = x;
		return 1;
	}
	return 0;
}

int pop(int a[],int &sp,int &x)
{
	if(sp != -1)
	{
		x = a[sp--];
		return 1;
	}
	return 0;
}

void DecTo(int a[],int sp,int x,int cs)
{
	do
	{
		push(a,sp,x % cs);
		x /= cs;
	}while(x > 0);
	
	int out;
	char b[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	while(sp != -1)
	{
		pop(a,sp,out);
		cout << b[out];
	}	
}

int main()
{
	int a[MAX];
	int sp;
	int x,cs,lc;
	init(a,sp);
	
	do{
		system("cls");
		do{
		cout << "1. Chuyen doi so hang thap phan sang he bat ky (2 - 36) \n"
			 << "2. Thoat.\n";
		cout << "Chon: ";
		cin >> lc;
		}while(lc <= 0 || lc > 2);
		
		switch(lc)
		{
			case 1:
				do{
					cout << "Ban muon doi sang co so: ";
					cin >> cs;
					}while(cs < 2 || cs > 36);
				cout << "Nhap so muon doi: ";
				cin >> x;
				cout << "Ket qua la: ";
				DecTo(a,sp,x,cs);
				break;
			default: cout << "Thoat!\n";
		}
		_getch();
					 
	}while(lc > 0 && lc < 2);
	
	return 0;
}
