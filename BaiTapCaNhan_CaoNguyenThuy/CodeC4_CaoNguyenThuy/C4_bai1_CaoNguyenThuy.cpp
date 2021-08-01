#include <iostream>
#include <conio.h>
using namespace std;

struct Node
{
	struct Node *left;
	struct Node *right;
	int data;
};
typedef struct Node NODE;
typedef NODE *Tree;
void Init(Tree &t)
{
	t = NULL;
}
void insertNode(Tree &t, int x)
{
	if (t == NULL)
	{
		NODE *p = new NODE;
		p->data = x;
		p->left = NULL;
		p->right = NULL;
		t = p;
	}
	else
	{
		if(t->data > x)
			insertNode(t->left,x);
		else
			if(t->data < x)
				insertNode(t->right,x);
	}
}
void nhap(Tree &t)
{
	int x;
	cout << "Nhap x: ";
	cin >> x;
	insertNode(t,x);
}
void NLR(Tree t)
{
	if (t != NULL)
	{
		cout << t->data << "\t";
		NLR(t->left);
		NLR(t->right);
	}
}
void LNR(Tree t)
{
	if(t != NULL)
	{
		LNR(t->left);
		cout << t->data << "\t";
		LNR(t->right);
	}
}
void LRN(Tree t)
{
	if (t != NULL)
	{
		LRN(t->left);
		LRN(t->right);
		cout << t->data << "\t";
	}
}
NODE *TimKiem(Tree t, int x)
{
	if (t == NULL)
		return NULL;
	else
	{
		if (x < t->data)
			TimKiem(t->left,x);
		else
			if (x > t->data)
				TimKiem(t->right,x);
			else
				return t;
	}
}
void xoa(Tree &t, int data)
{
	if (t == NULL)
		return;
	else
		if(data < t->data)
			xoa(t->left,data);
		else
			if (data > t->data)
				xoa(t->right,data);
			else
			{
				NODE *X = t;
				if(t->left == NULL)
					t = t->right;
				else
					if (t->right == NULL)
						t = t->left;
				delete X;
			}
}
int main()
{
	int chon;
	Tree t;
	bool in = false;
	do{
		system("cls");
		cout << "MENU\n"
			<< "1. Khoi tao cay nhi phan.\n"
			<< "2. Them mot phan tu vao cay.\n"
			<< "3. Tim mot phan tu trong cay.\n"
			<< "4. Xoa mot nut trong cay.\n"
			<< "5. Duyet NLR.\n"
			<< "6. Duyet LNR.\n"
			<< "7. Duyet LRN.\n"
			<< "8. Thoat.\nBan chon: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
			Init(t);
			cout << "Khoi tao cay thanh cong.\n";
			in = true;
			break;
		case 2:
			if (in)
			{
				nhap(t);
				cout << "Them thanh cong!\n";
			}
			else
				cout << "Ban chua khoi tao!\n";
			break;
		case 3:
			if (in)
			{
				int x;
				cout << "Nhap vao phan tu can tim kiem: ";
				cin >> x;
				NODE *p = TimKiem(t,x);
				if (p == NULL)
					cout << "Phan tu " << x << " khong ton tai trong cay\n";
				else
					cout << "Phan tu " << x << " co ton tai trong cay\n";
			}
			else
				cout << "Ban chua khoi tao!\n";
			break;
		case 4:
			if (in)
			{
				int data;
				cout << "Nhap vao gia tri can xoa: ";
				cin >> data;
				NODE *q = TimKiem(t,data);
				if (q == NULL)
					cout << "Khong co phan tu trong cay de xoa\n";
				else
				{
					xoa(t,data);
					cout << "Xoa thanh cong\n";
				}
			}
			else
				cout << "Ban chua khoi tao!\n";
			break;
		case 5:
			if (in)
			{
				cout << "Cay nhi phan tim kiem: ";
				NLR(t);
			}
			else
				cout << "Ban chua khoi tao!\n";
			break;
		case 6:
			if (in)
			{
				cout << "Cay nhi phan tim kiem: ";
				LNR(t);
			}
			else
				cout << "Ban chua khoi tao!\n";
			break;
		case 7:
			if (in)
			{
				cout << "Cay nhi phan tim kiem: ";
				LRN(t);
			}
			else
				cout << "Ban chua khoi tao!\n";
			break;
		default:
			cout << "Ban chon thoat.\n";
		}
		_getch();
	} while(chon >= 1 && chon <= 7);
	return 0;
}