//chuong 3 bai 1
#include <iostream>
#include <conio.h>
using namespace std;
const int MAXSIZE = 100;

void nhap(int a[], int n)
{
	cout << "Nhap vao " << n << " phan tu: ";
	for(int i = 0; i < n; i++)
		cin >> a[i];
}
void xuat(int a[], int n)
{
	for(int i = 0; i < n; i++)
		cout << a[i] << "\t";
	cout << endl;
}
void swap(int &a, int &b)
{
    int  c; 	
	c=a;	
	a=b;
	b=c;
}
void InsertionSort(int a[], int n)
{
	int x, j;
	for(int i = 1; i < n; i++)
	{
		x = a[i];		
		j = i - 1;
		while(0 <= j && x < a[j])
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j+1] = x;
	}
}
void SelectionSort(int a[], int n)
{
	int  min_pos, i, j;
	for(i=0; i<n-1; i++)
	{
		min_pos= i;
		for (j=i+1;j<n;j++)
			if (a[j]<a[min_pos])
				min_pos=j;
		swap(a[min_pos], a[i]);
	}
}
void InterchangeSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1;j < n; j++)
			if (a[i] > a[j])
				swap(a[i], a[j]); 
}
void BubbleSort(int a[], int n)
{
	for(int i=0; i<n-1; i++)
		for(int j=n-1;j>i; j--)
			if(a[j-1] >a[j]) 
				swap(a[j],a[j-1]); 
		
}
void QuickSort(int a[], int left, int right)
{
	int x = a[(left+right)/2];
	int i = left;
	int j = right;
	while(i < j) 
	{
	        while(a[i] < x) 
				i++;
	        while(a[j] > x) 
				j--;
			if(i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if(left < j)
	        QuickSort(a, left, j);
	if(i < right)
	        QuickSort(a, i, right);
}
void shift(int a[], int i, int n)
{
	int j = 2*i+1;
	if (j >= n)	
		return;
	if (j+1 < n)        
		if ( a[j]<a[j+1] )	
			j++;

	if (a[i] >= a[j] ) 
		return;
	else
	{
		int x = a[i];
		a[i] = a[j];
		a[j] = x;
		shift(a, j, n);
	}
}
void HeapSort(int a[], int n)
{
	int i = (n/2) - 1;
	while (i >= 0)	
	{	
		shift(a, i, n-1);	
		i--;	
	}
	int right = n-1;	
	while (right > 0)
	{	
		swap(a[0], a[right]); 
		right--;	
		if (right > 0)	
			shift(a, 0, right);	
	}
}
int Search(int a[], int n, int x)
{
	int i = 0;
	while(i < n && a[i] != x)
		i++;
	if(i < n)
		return i;		
	return -1;		
}
int BinarySearch(int a[], int n, int x)
{
	int left = 0, right = n - 1, mid;
	while(left <= right)
	{
		mid = (left+right)/2;
		if(a[mid] == x) return mid;
		if(x > a[mid]) left = mid+1;
		else right = mid-1;
	}
	return -1;	
}
int main()
{
	int a[MAXSIZE], n, chon;
	bool in = false;
	do{
			cout << "Nhap vao so luong ptu cua mang: ";
			cin >> n;
			if(n <= 0 || n > MAXSIZE)
				cout << "Nhap sai.Nhap lai\n";
		}while(n <= 0 || n > MAXSIZE);
		int l = 0, r = n - 1;
		nhap(a,n);
		cout << "Mang chua sap xep: ";
		xuat(a,n);
	do{
		cout << "Menu\n";
		cout << "1. Insertion sort\n"
			 << "2. Selection sort\n"
			 << "3. Interchange sort\n"
			 << "4. Bubble sort\n"
			 << "5. Quick sort\n"
			 << "6. Heap sort\n"
			 << "7. Search\n"
			 << "8. Binary search\n"
			 << "9. Thoat\n";
		cout << "Ban chon: ";
		cin >> chon;
		switch(chon)
		{
		case 1:
			InsertionSort(a,n);
			cout << "Mang sau sap xep: ";
			xuat(a,n);
			in = true;
			break;
		case 2:
			SelectionSort(a,n);
			cout << "Mang sau sap xep: ";
			xuat(a,n);
			in = true;
			break;
		case 3:
			InterchangeSort(a,n);
			cout << "Mang sau sap xep: ";
			xuat(a,n);
			in = true;
			break;
		case 4: 
			BubbleSort(a,n);
			cout << "Mang sau sap xep: ";
			xuat(a,n);
			in = true;
			break;
		case 5:
			QuickSort(a,l,r);
			cout << "Mang sau sap xep: ";
			xuat(a,n);
			in = true;
			break;
		case 6:
			HeapSort(a,n);
			cout << "Mang sau sap xep: ";
			xuat(a,n);
			in = true;
			break;
		case 7:
			int x;
			cout << "Nhap vao gia tri can tim kiem: ";
			cin >> x;
			if(Search(a,n,x) != -1)
				cout << x << " xuat hien o vi tri " << Search(a,n,x) + 1 << endl;
			else
				cout << x << " khong co trong danh sach\n";
			break;
		case 8:
			if(in == true)
			{
				int x;
				cout << "Nhap vao gia tri can tim kiem: ";
				cin >> x;
				if(BinarySearch(a,n,x) != -1)
					cout << x << " xuat hien o vi tri " << BinarySearch(a,n,x) + 1 << endl;
				else
					cout << x << " khong co trong danh sach\n";
			}
			else
				cout << "Danh sach chua duoc xep thu tu\n";
			break;
		default:
			cout << "Ban chon thoat\n";
		}
		_getch();
	}while(chon >= 1 && chon <= 8);
}





