#include <iostream>
#include <conio.h>
using namespace std;

struct Node
{
	struct Node *left;
	struct Node *right;
	int data;
};
Node *root; 
struct Stack {
	Node* data;
	Stack* next;
};
Stack* sp;
Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
void tree_empty()
{
	root = NULL; 
}
void push(Node* x)
{
	Stack* p = new Stack;
	p->data = x;
	p->next = sp;
	sp = p;
}
int pop(Node* x)
{
	if (sp != NULL)
	{
		Stack* p = sp;
		x = p->data;
		sp = p->next;
		delete(p);
		return 1;
	}
	return 0;
}
int isEmpty()
{
	if (sp == NULL)
		return 1;
	return 0;
	
}
void insertNode(Node *&root, int x)
{
	Node *p = root;
	Node *tam = NULL;
	Node *t = newNode(x);
	while(p != NULL)
	{
		tam = p;
		if(p->data == x)
			return;
		else
			if(x < p->data)
				p = p ->left;
			else
				p = p ->right;
	}
	if(tam == NULL)
		root = t;
	else
		if(x < tam->data)
			tam->left = t;
		else
			tam->right = t;
}
void nhap(Node *&p)
{
	int x;
	cout << "Nhap x: ";
	cin >> x;
	insertNode(p,x);
}
void LRN(Node *p)
{
	if (p != NULL)
	{
		LRN(p->left);
		LRN(p->right);
		cout << p->data << "\t";
	}
}
void NLR(Node* root)
{
	Node* p;
	if (root != NULL)
	{
		push(root);
	}
	while (!isEmpty())
	{
		p = sp->data;
		pop(p);
		cout << p->data << " ";
		if (p->right != NULL)
			push(p->right);
		if (p->left != NULL)
			push(p->left);
	}
}
void LNR(Node* root)
{
	Node* p = root;
	while (p != NULL||!isEmpty())
	{
		if (p != NULL)
		{
			push(p);
			p = p->left;
		}
		else {
			p = sp->data;
			pop(p);
			cout << p->data << " ";
			p = p->right;
		}
	}
}
Node *search(Node *p, int x)
{
	while (p!= NULL)
	{
		if (p->data == x)
			return p;
		else
			if (p->data > x)
				p = p->left;
			else	
				p = p->right;
	}
	return NULL;
}
void searchStandFor(Node *&p, Node  *&q)
{
	 if (q->left == NULL)
	{	
	              p->data = q->data;
	              p = q;
	              q  = q->right;
	}
	else 
	              searchStandFor(p, q->left);
}

int Delete(Node *&p, int x)
{
	if (p == NULL) 
		return 0;
	if (p->data == x)
	{	
		Node *t = p; 
		if (p->left == NULL)
				p = p->right;
	    else 
			if (p -> right == NULL)
				p = p->left;
	        else		// có 2 con
				searchStandFor(t, p->right);
	    delete p;
		return 1;
	}
	if(p->data < x) 
		return Delete(p->right, x);
	if(p->data > x) 
		return Delete(p->left, x);
}

int main()
{
	int chon;
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
			tree_empty();
			cout << "Khoi tao cay thanh cong.\n";
			in = true;
			break;
		case 2:
			if (in)
			{
				nhap(root);
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
				Node *p = search(root,x);
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
				Node *q = search(root,data);
				if (q == NULL)
					cout << "Khong co phan tu trong cay de xoa\n";
				else
				{
					Delete(root,data);
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
				NLR(root);
			}
			else
				cout << "Ban chua khoi tao!\n";
			break;
		case 6:
			if (in)
			{
				cout << "Cay nhi phan tim kiem: ";
				LNR(root);
			}
			else
				cout << "Ban chua khoi tao!\n";
			break;
		case 7:
			if (in)
			{
				cout << "Cay nhi phan tim kiem: ";
				LRN(root);
				cout << endl;
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