#include <iostream>
#include <conio.h>
using namespace std;
const int MAXSIZE = 100;
int sp;

void init(int a[], int &sp)
{
	sp = -1;
}
void xuat(int a[], int sp)
{
	for (int i = sp; i >= 0; i--)
		cout << a[i] << "\t";
	cout << endl;
}
int Push(int a[], int &sp, int x)
{
	if (sp< MAXSIZE - 1)
	{
		a[++sp] = x;
		return 1;
	}
	return 0;
}
int Pop(int a[], int &sp, int &x)
{
	if (sp != -1)
	{
		x = a[sp--];
		return 1;
	}
	return 0;
}
int isFull(int a[], int sp)
{
	if (sp == MAXSIZE - 1)
		return 1;
	return 0;
}
int isEmpty(int a[], int sp)
{
	if (sp == -1)
		return 1;
	return 0;
}

int main()
{
	int a[MAXSIZE], chon;
	bool in = false;
	do {
		system("cls");
		cout << "Menu\n";
		cout << "1. Khoi tao stack rong\n"
			<< "2. Kiem tra stack rong\n"
			<< "3. Kiem tra stack day\n"
			<< "4. Them 1 phan tu\n"
			<< "5. Xoa 1 phan tu\n"
			<< "6. Xuat stack\n"
			<< "7. Thoat\n";
		cout << "Ban chon: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
			init(a, sp);
			cout << "Tao stack thanh cong\n";
			in = true;
			break;
		case 2:
			if (in == true)
				if (isEmpty(a, sp) == 1)
					cout << "Stack rong\n";
				else
					cout << "Stack khong rong\n";
			else
				cout << "Chua tao stack\n";
			break;
		case 3:
			if (in == true)
				if (isFull(a, sp) == 1)
					cout << "Stack day\n";
				else
					cout << "Stack chua day\n";
			else
				cout << "Chua tao stack\n";
			break;
		case 4:
			if (in == true)
			{
				int x, tam1;
				cout << "Nhap gia tri ban muon them: ";
				cin >> x;
				tam1 = Push(a, sp, x);
				if (tam1 == 1)
					cout << "Them thanh cong\n";
				else
					cout << "Stack da day\n";
			}
			else
				cout << "Chua tao stack\n";
			break;
		case 5:
			if (in == true)
			{
				int y;
				int tam2 = Pop(a, sp, y);
				if (tam2 == 1)
					cout << "Xoa 1 phan tu thanh cong\n";
				else
					cout << "Stack khong co phan tu nao\n";
			}
			else
				cout << "Chua tao stack\n";
			break;
		case 6:
			if (in == true)
				if (sp == -1)
					cout << "Stack chua co gia tri";
				else
					xuat(a, sp);
			else
				cout << "Chua tao stack\n";
			break;
		default:
			cout << "Ban chon thoat\n";
		}
		_getch();
	} while (chon >= 1 && chon <= 6);
	return 0;
}