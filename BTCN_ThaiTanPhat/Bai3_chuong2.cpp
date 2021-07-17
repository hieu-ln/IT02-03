#include<iostream>
#include<conio.h>
using namespace std;

struct Node
{
	int info;
	Node *link;
};
Node *first;
void init()
{
	first=NULL;
}
void inert_first(int x)
{
	Node *p=new Node();
	p->info=x;
	p->link=first;
	first=p;
	
}
void inert_last(int x)
{
	Node *p=new Node();
	p->info=x;
	p->link=NULL;
	if(first==NULL)
		first=p;
	else
	{
		Node *q=first;	
		while(q->link !=NULL)
			q=q->link;
		q->link=p;
	}

}
void xuat()
{
	Node *p=first;
	while(p!=NULL)
	{
		cout << p ->info <<"\t";
		p=p->link;
	}
}
Node *seach(int x)
{
	Node *p=first;
	while(p!=NULL && p->info !=x)
		p=p->link;
	return p;
}
int delete_first()
{
	if(first != NULL)
	{
		Node *p=first;
		first=first->link;
		delete p;
		return 1;
	}
	return 0;
}
int delete_last()
{
	if(first != NULL)
	{
		Node *p=first;
		Node *q=NULL;
		if(p!=NULL)
			while(p->link!=NULL)
			{
				q=p;p=p->link;
			}
		if(p!=first)
			q->link=NULL;
		else
			first = NULL;
		delete p;
		return 1;
	}
	return 0;
}
int delete_node(int x)
{
	Node *q=seach(x);
	if(q==NULL) return 0;
	if(q ->link==NULL) return 0;
	Node *p=q->link;
	q->link=p->link;
	delete p;
	return 1;
}
int main()
{
	int chon;
	bool in=false;
	do{

		system("cls");
		cout << "1. Khoi tao\n2. Them dau\n3. Them cuoi\n4. Xuat\n5. Tim kiem\n6. Xoa dau\n7. Xoa cuoi\n8. Tim va xoa\n9. Thoat\n Ban chon: ";
		cin >> chon;
		switch (chon)
		{
			case 1:
				{
					init();
					in=true;
					if(in)
						cout << "Khoi tao thành công\n";
					break;
				
				}
			case 2:
				{
					if(in)
					{
						int x;
						cout << "Ban hay nhap gia tri node: ";
						cin >> x;
						inert_first(x);
					}
					else
						cout << "Hay khoi tao node!!";
					break;
				}
			case 3:
			{
					if(in)
					{
						int x;
						cout << "Ban hay nhap gia tri node: ";
						cin >> x;
						inert_last(x);
					}
					else
						cout << "Hay khoi tao node!!";
					break;
			}
			case 4:
				{
					if(in)
					{
						cout << "Node dang luu tru\n";
						xuat();
					}
					else
						cout << "Node rong!!";
					break;
				}
			case 5:
				{
					if(in)
					{
						int x;
						cout << "Nhap gia tri ban can tim kiem: ";
						cin >> x;
						if(seach(x))
							cout << "Phan tu co trong node!";
						else
							cout << "Phan tu khong co trong node!\n";
					}
					else
						cout <<"Hay khoi tao Node!\n";
					break;
				}
			case 6:
				{
					if(in)
					{
						if(delete_first())
							cout<< "Xoa thanh cong!";
						else 
							cout << "Xoa khong thanh cong!";
					}
					else
						cout <<"Hay khoi tao Node!\n";
					break;
				}
			case 7:
				{
					if(in)
					{
						if(delete_last())
							cout<< "Xoa thanh cong!";
						else 
							cout << "Xoa khong thanh cong!";
					}
					else
						cout <<"Hay khoi tao Node!\n";
					break;
				}
			case 8:
				{
					if(in)
					{
						int x;
						cout << "nhap x: ";
						cin >> x;
						if (delete_node(x))
							cout<< "Xoa thanh cong!";
						else 
							cout << "Xoa khong thanh cong vi x khong co trong node!";
					}
					else
						cout <<"Hay khoi tao Node!\n";
					break;
				}
			default:
				cout << "Ban chon thoat!\n";
		}
		_getch();
	}while(chon >=1  && chon <= 8);
	
	return  0;
}