#include <iostream>
#include <conio.h>
using namespace std;
const int MAX = 100;
void init (int a[], int &sp)
{
	sp = -1;
}

int ktStackRong (int a[], int sp)
{
	if (sp == -1)
		return 1;
	return 0;
}
int ktStackDay(int a[], int sp)
{
	if (sp == MAX - 1)
		return 1;
	else
		return 0;
}

void them(int a[], int &sp, int x)
{
		a[++sp] = x;
		
}
void xoa(int a[], int& sp, int& x)
{
	x = a[sp--];
}

int main()
{
	int a[100];
	int n,sp,x;
	init(a,sp);
	cout << "Nhap gia tri he so 10: ";
	cin >> n;
	int temp = n;
	
	do {
		x = temp % 2;
		them(a, sp, x);
		temp /= 2;
	} while (temp != 0 && !ktStackDay(a, sp));

	cout << "He nhi phan cua " << n << " la = ";
	while (!ktStackRong(a, sp))
	{
		xoa(a, sp, x);
		cout << x;
	}
	cout << endl;

	return 0;

}