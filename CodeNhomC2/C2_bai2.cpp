#include <iostream>
#include <conio.h>
using namespace std;
void nhap(int a[], int n)
{
	cout << "Nhap " << n << " so nguyen: " << endl;;
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]= ";
		cin >> a[i];
	}
}
void xuat(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "\t";
	cout << endl;
}
int tim(int a[], int n, int x)
{
	int i = 0;
	while (i < n && a[i] != x)
		i++;
	if (i == n)
		return -1;
	return i;
}
int them(int a[], int& n, int vt, int gt)
{
	if (vt >= 0 && vt <= n - 1)//vt đã hợp lệ
	{
		if (n + 1 <= 100)
		{
			for (int k = n - 1; k >= vt; k--)
				// n = 5;		   2 5 4 8 6 9; vt = 3, gt = 10
				// sau khi thỏa đk 2 5 4 8 8 6 9
				a[k + 1] = a[k];
			a[vt] = gt; // 2 5 4 10 8 6 9
			n++; // n = 6
			return 1; // them thanh cong
		}
		else
			return 0;
	}
	else
		return 0; // them khong thanh cong, vt ko hop le
}
int xoa(int a[], int& n, int x) // x la phan tu muon xoa
{
	if (x >= 0 && x < n)
	{
		for (int i = x; i <= n - 1; i++)  // 2 3 5 7 8 9
			a[i] = a[i + 1];                // 0 1 2 3 4 5
		n--;

		return 1;
	}
	return 0;
}
void timvaxoa(int a[], int &n, int x)
{

	if (tim(a, n, x) != -1)
	{
		int k = tim(a, n, x);
		xoa(a, n, k);
	}
	else
		cout << "khong tim dc vi tri can xoa\n";
}
int main()
{
	int chon,n;
	const long max = 100;
	int a[max];
	bool input = false;
	do {
		system("cls");
		cout << "MENU Chuc Nang: " << endl;
		cout << "1.Nhap \n2.Xuat \n3.Tim \n4.Them vi tri \n5.Tim & xoa phan tu \nBan chon? : ";
		cin >> chon;
		switch (chon)
		{
		case 1:
		{
			cout << "Moi ban nhap n phan tu: " << endl;
			cin >> n;
			while (n < 1 || n > max)
			{
				cout << "Nhap sai! Nhap lai: ";
				cin >> n;
			}//while
			nhap(a, n);
			input = true;
			break;
		}
		case 2:
		{
			if (input)
				xuat(a, n);
			else
				cout << "Vui long nhap mang!!\n";
			break;
		}
		case 3:
		{
			if (input)
			{
				int x;
				cout << "Nhap x: ";
				cin >> x;
				int vt = tim(a, n, x);
				if (vt != -1)
					cout << x << " co trong mang tai vi tri dau tien thu " << vt << endl;
				else
					cout << x << " khong co trong mang!\n";
			}
			else
				cout << "Vui long nhap mang!!\n";
			break;
		}
		case 4:
		{
			int vt, gt;
			if (input)
			{
				cout << "Nhap vi tri can them: ";
				cin >> vt;
				cout << "Nhap gia tri can them: ";
				cin >> gt;
				if (them(a, n, vt, gt))
					cout << "Qua trinh them thanh cong! Chon XUAT de xem ket qua\n";
				else
					cout << "Qua trinh them khong thanh cong!\n";
			}
			else
				cout << "Vui long nhap mang!\n";
			break;
		}
		case 5:
		{
			if (input)
			{
				int x, vt;
				cout << "Nhap x can tim & thuc hien xoa: ";
				cin >> x;
				timvaxoa(a, n, x);
				cout << "Muon xem ket qua chon XUAT\n";
			}
			else
				cout << "Vui long nhap mang!\n";
		}
		}//sw
		_getch();
	} while (n < 10 && n > 0);
}