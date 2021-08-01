#include <iostream>
#include <conio.h>
using namespace std;
const int MAX = 100;

void nhapds (int a[], int n)
{
	for (int i = 0 ; i < n ; i++)
	{
		cout << "Nhap phan tu thu " << i+1 << ": ";
		cin >> a[i];
	}

}
void xuatds  (int a[], int n)
{
	cout << "Danh sach dang luu tru : \n";
	for (int i = 0 ; i < n ; i++)
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
void InsertionSort (int a[], int n)
{
	int x, i, j;
	for(int i = 1; i < n; i++)
	{
		x = a[i];		// biến x lưu giá trị a[i]
		 j = i - 1;
		while(0 <= j && x < a[j])
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j+1] = x;
	}

}
void SelectionSort (int a[], int n)
{
	int  min_pos, i, j;
for(i=0; i<n-1; i++)
{
	min_pos= i;
	for (j=i+1;j<n;j++)
		if (a[j]<a[min_pos])
			min_pos=j; //min_pos là vị trí chứa giá trị hiện tại nhỏ nhất
	swap(a[min_pos], a[i]);
}

}
void InterchangeSort(int a[], int n)
{
for (int i = 0; i < n - 1; i++)
	for (int j = i + 1;j < n; j++)
		if (a[i] > a[j])
			swap(a[i], a[j]); // đổi chỗ a[i] và a[j]
}

void BubbleSort(int a[], int n)
{
for(int i=0; i<n-1; i++)
	for(int j=n-1;j>i; j--)
		if(a[j-1] >a[j]) // xét điều kiện phần tử sau nhỏ hơn phần tử trước
			swap(a[j],a[j-1]);// hoán vị a[j] với a[j-1]
		
}

void QuickSort(int a[], int left, int right)
{
	int x = a[(left+right)/2];
	int i = left;
	int j = right;
	while(i < j) 
	{
	        while(a[i] < x) i++;
	        while(a[j] > x) j--;
			        if(i <= j){
		swap(a[i], a[j]);
		i++; j--;
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
	if (j >= n)	// nếu vị trí j không tồn tại trong danh sách đang xét thì thoát khỏi chương trình
		return;
	if (j+1 < n)        // nếu tồn tại vị trí j+1 trong danh sách đang xét thì thoát khỏi chương trình
		if ( a[j]<a[j+1] )	// nếu vị trí j không tồn tại phần tử a[j] < a[j+1]
			j++;

	if (a[i] >= a[j] ) 
		return;
	else {
		int x = a[i];
		a[i] = a[j];
		a[j] = x;
		shift(a, j, n);
	}
}

void HeapSort(int a[], int n)
{
	int i = n/2;
	while (i >= 0)	// tạo Heap ban đầu
	{	
		shift(a, i, n-1);	i --;	
	}
	int right = n-1;	// right là vị trí cuối Heap đang xét
	while (right > 0)
	{	
		swap(a[0], a[right]); // hoán vị phần tử a[0] cho phần tử cuối Heap đang xét
		right --;	// giới hạn lại phần tử cuối đang xét
		if (right > 0)	// Kiểm tra dãy đang xét còn nhiều hơn 1 phần tử
			shift(a, 0, right);	// tạo Heap lại tại vị trí 0
	}

}

int timkiemtuantu (int a[], int n, int X)
{
	int i = 0;
	while(i < n && a[i] != X)
		i++;
	if(i < n)
		return i;		// x trong danh sách a, và nằm ở vị trí i.
	return -1;		// không tìm thấy X trong danh sách a.

}
int timkiemnhiphan (int a[] , int n, int X)
{
	
	int left = 0, right = n - 1, mid;
	while(left <= right)
	{
		mid = (left+right)/2;
		if(a[mid] == X) return mid;
		if(X > a[mid]) left = mid+1;
		else right = mid-1;
	}
	return -1;	// không tìm thấy X trong danh sách a.

}

int main()
{
	int a[MAX];
	int n,x,chon;
	bool check = false;
	bool sapxep = false;
	do{
	system("cls");
	cout << "BAI TAP CHUONG 3\n";
	cout << "1.Nhap danh sach\n";
	cout << "2.Xuat danh sach\n";
	cout << "3.Sap xep tang dan bang InsertionSort\n";
	cout << "4.Sap xep tang dan bang SelectionSort\n";
	cout << "5.Sap xep tang dan bang InterchageSort\n";
	cout << "6.Sap xep tang dan bang BubbleSort\n";
	cout << "7.Sap xep tang dan bang QuickSort\n";
	cout << "8.Sap xep tang dan bang HeapSort\n";
	cout << "9.Tim kiem tuan tu\n";
	cout << "10.Tim kiem nhi phan\n";
	cout << "Ban chon: ";
	cin >> chon;
	switch (chon)
	{
	case 1:
		cout << "Nhap so luong phan tu: ";
		cin >> n;
		nhapds(a,n);
		check = true;
		break;
	case 2:
		if (check)
			xuatds(a,n);
		else
			cout <<"Vui long nhap phan tu\n";
		break;
	case 3:
		if (check)
		{
			InsertionSort(a,n);
			cout << "Sap xep thanh cong\n";
		}
		else
			cout <<"Vui long nhap phan tu\n";
		sapxep = true;
		break;
	case 4:
		if (check)
		{
			SelectionSort(a,n);
			cout << "Sap xep thanh cong\n";
		}
		else
			cout <<"Vui long nhap phan tu\n";
		sapxep = true;
		break;
	case 5:
		if (check)
		{
			InterchangeSort(a,n);
			cout << "Sap xep thanh cong\n";
		}
		else
			cout <<"Vui long nhap phan tu\n";
		sapxep = true;
		break;
	case 6:
		if (check)
		{
			BubbleSort(a,n);
			cout << "Sap xep thanh cong\n";
		}
		else
			cout <<"Vui long nhap phan tu\n";
		sapxep = true;
		break;
	case 7:
		if (check)
		{
			QuickSort(a,0,n-1);
			cout << "Sap xep thanh cong\n";
		}
		else
			cout <<"Vui long nhap phan tu\n";
		sapxep = true;
		break;
	case 8:
		if (check)
		{
			HeapSort(a,n);
			cout << "Sap xep thanh cong\n";
		}
		else
			cout <<"Vui long nhap phan tu\n";
		sapxep = true;
		break;
	case 9:
		if (check)
		{
			cout << "Nhap phan tu can tim kiem: ";
			cin >> x;
			if (timkiemtuantu(a,n,x) != -1)
				cout << "tim thay " << x << " tai vi tri thu " << timkiemtuantu(a,n,x) + 1 << "\n";
			else
				cout << "khong tim thay " << x << "\n";
		}
		else
			cout <<"Vui long nhap phan tu\n";
		break;
	case 10:
		if (check)
		{
			if (sapxep)
			{
				cout << "Nhap phan tu can tim kiem: ";
				cin >> x;
				if (timkiemnhiphan(a,n,x) != -1)
					cout << "tim thay " << x << " tai vi tri thu " << timkiemnhiphan(a,n,x) + 1 << "\n";
				else
					cout << "khong tim thay " << x << "\n";
			}
			else
				cout << "Mang chua duoc sap xep\n";
		}
		else
				cout <<"Vui long nhap phan tu\n";
			break;
	default:
		cout << "Ban chon thoat\n";
	}
	_getch();
	}while (chon >= 1 && chon <= 10);
	return 0;
}