#include <iostream>
using namespace std;
const int MAXSIZE = 1000;
int sp;

void init(int a[], int &sp)
{
	sp = -1;
}
void xuat(int a[], int sp)
{
	for (int i = sp; i >= 0; i--)
		cout << a[i];
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
int isFull(int a[], int sp)
{
	if (sp == MAXSIZE - 1)
		return 1;
	return 0;
}
int main()
{
	int x, tam, np[MAXSIZE], check;
	init(np, sp);
	do {
		cout << "Nhap vao 1 so nguyen duong: ";
		cin >> x;
		if (x < 0)
			cout << "Nhap sai. Nhap lai\n";
	} while (x < 0);
	tam = x;
	check = isFull(np, sp);
	while (tam != 0 && check != 1)
	{
		int y = tam % 2;
		tam = tam / 2;
		Push(np, sp, y);
		check = isFull(np, sp);
	}
	cout << "He nhi phan cua " << x << " = ";
	xuat(np, sp);
	return 0;
}