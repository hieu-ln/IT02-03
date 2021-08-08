#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#define MAX 20
using namespace std;

int a[MAX][MAX];
int n = 0;

int E1[MAX];
int E2[MAX];
int wE[MAX];
int nE = 0;

int T1[MAX];
int T2[MAX];
int wT[MAX];
int nT = 0;

	// Danh sach ham
void khoiTaoMaTranRong();
void input();
void inputByFile();
void outputMaTranKe();
int TonTai(int d, int D[], int nD);
void XoaViTriE(int i);
void XoaCanhE(int u, int v);
void prim(int s);
void output();

	// Chuong trinh chinh
int main()
{
	int s;
	int chon;
	bool in = false;

	do {
		system("cls");
		cout << "-----Menu-----\n"
			<< "1. Nhap ma tran ke (bang file)\n"
			<< "2. Xuat ma tran ke\n"
			<< "3. Tim cay khung toi thieu\n"
			<< "4. Thoat\n"
			<< "Ban chon: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
			if (in)
			{
				khoiTaoMaTranRong();
				n = 0;

				inputByFile();
			}
			else
			{
				inputByFile();
				in = true;
			}
			break;
		case 2:
			if (in)
			{
				outputMaTranKe();
			}
			else
				cout << "Khong co du lieu\n";
			break;
		case 3:
			if (in)
			{
				cout << "Vui long nhap dinh bat dau: ";
				do {
					cin >> s;
					if (s < 1 || s > n)
						cout << "Nhap sai. Nhap lai: ";
				} while (s < 1 || s > n);

				s--;
				prim(s);
				cout << "Ket qua cay khung toi thieu:\n";
				output();
			}
			else
				cout << "Khog co du lieu\n";
			break;
		default:
			cout << "---Ket thuc chuong trinh---\n";
		}
		_getch();
	} while (chon >= 1 && chon <= 3);

	return 0;
}

	// Dinh nghia ham
void khoiTaoMaTranRong()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = 0;
}
void input()
{
	cout << "*Lien ket : nhap Trong So w\n*Khong lien ket : 0\n";
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap trong so cho dong thu " << i + 1 << ": ";
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	}

	cout << "Luu do thi thanh cong. Chon xuat de kiem tra\n";
}
void inputByFile()
{
	ifstream dataFile;
	string nameFile;

	cin.ignore();
	cout << "Nhap ten file: ";
	getline(cin, nameFile);
	dataFile.open(nameFile, ios::in);
	if (dataFile.is_open())
	{
		dataFile >> n;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				dataFile >> a[i][j];

		cout << "*Luu do thi thanh cong. Chon xuat de kiem tra\n";
		dataFile.close();
	}
	else
		cout << "*Khong the mo file. Vui long kiem tra\n";
}
void outputMaTranKe()
{
	cout << "Do thi dang luu tru:\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j] << "\t";
		cout << endl;
	}
}
int TonTai(int d, int D[], int nD)
{
	for (int i = 0; i < nD; i++)
		if(D[i] == d)
			return 1;
	return 0;
}
void XoaViTriE(int i)
{
	for (int j = i; j < nE; j++)
	{
		E1[j] = E1[j + 1];
		E2[j] = E2[j + 1];
		wE[j] = wE[j + 1];
	}
	nE--;
}
void XoaCanhE(int u, int v)
{
	bool flag = false;
	int i = 0;

	while (i < nE && !flag)
	{
		if (E1[i] == u && E2[i] == v)
		{
			XoaViTriE(i);
			flag = true;
		}
		i++;
	}
}
void prim(int s)
{
	int u = s, min, i, d1, d2;
	bool flag = false;

    while (nT < n - 1)
    {
        for (int v = 0; v < n; v++)
			if (a[u][v] != 0 && TonTai(v, T2, nT) == 0)
			{
				E1[nE] = u;
				E2[nE] = v;
				wE[nE] = a[u][v];
				nE++;
			}

		i = 0;
		flag = false;
		while (i < nE && !flag)
		{
			if (TonTai(E2[i], T2, nT) == 0)
			{
				min = wE[i];
				d1 = E1[i];
				d2 = E2[i];
				flag = true;
    	    }
			i++;
		}

		for (i = 0; i < nE; i++)
      		if (TonTai(E2[i], T2, nT) == 0 && min > wE[i])
			{
				min = wE[i];
				d1 = E1[i];
				d2 = E2[i];
			}

		T1[nT] = d1;
		T2[nT] = d2; 
        wT[nT] = a[d1][d2]; 
        a[d1][d2] = 0;
		a[d2][d1] = 0;
        nT++;
		XoaCanhE(d1, d2);
		u = d2;
     }
}
void output()
{
	int tong = 0;

	for (int i = 0; i < nT; i++)
	{
		cout << endl << "(" << T1[i] << "," << T2[i] << ") = " << wT[i];
		tong += wT[i];
	}
	cout << "\nTong = " << tong << endl;
}
