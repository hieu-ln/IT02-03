#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;
//khai bao ma tran bang mang hai chieu
#define MAX 20
int A[MAX][MAX];
int n;
char vertex[MAX];
//khoi tao ma tran ke
void InitGraph()
{
	n = 0;
}
//nhap ma tran ke
void inputGraph()
{
	cout << "Nhap so dinh do thi n: ";
	cin >> n;
	for (int i = 0; i<n; i++)
	{
		cout << "Nhap ten dinh: ";
		cin >> vertex[i];
		cout << "Nhap vao dong thu " << i + 1 << ": ";
		for (int j = 0; j<n; j++)
			cin >> A[i][j];
	}
}
//xuat ma tran ke
void outputGraph()
{
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}
}

//khai bao TapE
int E1[MAX];
int E2[MAX];
int wE[MAX];
int nE = 0;
//khai bao TapE
int T1[MAX];
int T2[MAX];
int wT[MAX];
int nT = 0;
void taoE()
{
	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++)
			if (A[i][j] != 0)
			{
				E1[nE] = i;
				E2[nE] = j;
				wE[nE] = A[i][j];
				A[i][j] = 0;
				A[j][i] = 0;
				nE++;
			}
}
int TonTai(int d, int D[], int nD)
{
	for (int i = 0; i<nD; i++)
		if (D[i] == d)
			return 1;
	return 0;
}
void kruskal()
{
	for (int i = 0; i<nE; i++)
	{
		if (TonTai(E1[i], T1, nT) == 1 && TonTai(E2[i], T2, nT) == 1)
			continue;
		if (TonTai(E1[i], T2, nT) == 1 && TonTai(E2[i], T1, nT) == 1)
			continue;
		T1[nT] = E1[i];
		T2[nT] = E2[i];
		wT[nT] = wE[i];
		nT++;
		if (nT == n - 1)
			break;
	}
}
void output()
{
	int tong = 0;
	for (int i = 0; i<nT; i++)
	{
		cout << endl << "(" << T1[i] << "," << T2[i] << ") = " << wT[i];
		tong += wT[i];
	}
	cout << "\n Tong = " << tong;
}

int main()
{
	int choice;
	system("cls");
	cout << "----- BAI TAP 4 - CHUONG 6 -----\n";
	cout << "1. Khoi tao Ma Tran Ke rong\n";
	cout << "2. Nhap Ma Tran Ke\n";
	cout << "3. Xuat Ma Tran Ke\n";
	cout << "4. Tim cay khung toi tieu bang thuat giai KRUSKAL\n";
	cout << "5. Thoat\n";
	do {
		cout << "\nVui long nhap so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			InitGraph();
			cout << "Ban vua khoi tao thanh cong Ma Tran Ke!\n";
			break;
		case 2:
			inputGraph();
			break;
		case 3:
			outputGraph();
			break;
		case 4:
			taoE();
			kruskal();
			cout << "Cay khung toi tieu:";
			output();
			break;
		case 5:
			cout << "Tam Biet \n";
			break;
		default:
			break;
		}
	} while (choice != 5);
	system("pause");
	return 0;
}