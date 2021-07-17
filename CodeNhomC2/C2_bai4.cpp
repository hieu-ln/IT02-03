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
	first = NULL;
}
void Process_list()
{
	Node *p = first;
	while(p != NULL)
	{
		cout << p->info <<"\t";
		p=p->link;
	}
}
Node *search(int x)
{
	Node *p = first;
	while((p != NULL) && (p->info != x))
		p = p->link;
		return p;
}
Node *createNode(int x)
{
	Node *p = new Node;
	if(p == NULL)
	{
		return NULL;
	}
	p->info = x;
	p->link = NULL;
	return p;
}
void Insert_first(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = first;
	first = p;
}
void Insert_last(int y)
{	
	Node *p = new Node;
	p->info = y;      
	p->link = NULL;    
	if(first == NULL)
		first = p;
	else
	{	
		Node *q = first;
	while(q->link != NULL)
		q = q->link;
		q->link = p;
	}
}
void Insert_first_ds(int &n)
{
	int x;
	cout <<"Moi ban nhap n:";
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cout <<"Moi ban nhap gia tri:" << endl;
		cin >> x;
		Insert_first(i);
	}
}
void Insert_last_ds(int &n)
{
	int x;
	cout <<"Moi ban nhap n:";
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cout <<"Moi ban nhap gia tri:" << endl;
		cin >> x;
		Insert_last(i);
	}
}
int Insert_k(int y,int x)
{
	Node *kq = search(y);
	if(kq == NULL) 
		return 0;
	Node *p = new Node ;
	p->info = x;
	if(kq->link == NULL)
		p->link = NULL;
	else
		p->link = kq->link;
	kq->link = p;
	return 1;
}
int Delete(int x)
{
    if (first != NULL)
    {
        Node* p, * q;
        p = first;
        q = first;

        while (p->info != x && p->link != NULL)
        {
            q = p;
            p = p->link;
        }

        if (p != first && p->link != NULL)
        {
            if (p->link != NULL)
                q->link = p->link;
            else
                q->link = NULL;
            delete p;
            return 1;
        }
        else if (p == first)
        {
            first = p->link;
            delete p;
            return 1;
        }
        else if (p->link == NULL && p->info == x)
        {
            q->link = NULL;
            delete p;
            return 1;
        }
        else
            return 0;
    }
    return 0;
}
int main()
{
	int chon;
	bool fl = false;
	do{
		system("cls");
		cout <<"MENU:\n"
			<<"1.Khoi tao danh sach.\n"
			<<"2.Xuat danh sach.\n"
			<<"3.Them n phan tu vao dau danh sach.\n"
			<<"4.Them n phan tu vao cuoi danh sach.\n"
			<<"5.Them phan tu vao vi tri sau node bat ki.\n"
			<<"6.Tim kiem phan tu.\n"
			<<"7.Tim va xoa.\n"
            <<"8.Thoat\n";
		cin >> chon;
		switch(chon)
		{
		case 1:
			{
			init();
			cout <<"Ban da khoi tao danh sach thanh cong!\n";
			fl = true;
			}
			break;
		case 2:
			if(fl == true)
			{
				Process_list();
			}
			else
				cout <<"Ban chua khoi tao danh sach!!!\n";
			break;
		case 3:
			if(fl == true)
			{
				int n;	
				Insert_first_ds(n);
				cout <<"Da them vao danh sach.Xuat de xem.\n";
			}
			else
				cout <<"Ban chua khoi tao danh sach!!!\n";
			break;
		case 4:
			if(fl == true)
			{
				int n;	
				Insert_last_ds(n);
				cout <<"Da them vao danh sach.Xuat de xem.\n";
			}
			else
				cout <<"Ban chua khoi tao danh sach!!!\n";
			break;
		case 5:
			if(fl == true)
			{
				int x,y;
				cout <<"Moi ban nhap gia tri node can them sau:";
				cin >> y;
				cout <<"Moi ban nhap gia tri them:";
				cin >> x;
				if(Insert_k(y,x))
				    cout <<"Da them o vi tri ban chon.Xuat ds de xem\n";
				else
					cout <<"Them khong thanh cong!\n";
			}
			else
				cout <<"Ban chua khoi tao danh sach\n";
			break;
		case 6:
			if(fl == true)
			{
				int x;
				cout <<"Nhap gia tri ban muon tim:";
				cin >> x;
				if(search(x))
					cout << x <<" co trong danh sach.\n";
				else
					cout << x <<" k co trong danh sach.\n";
			}
			else
				cout <<"Ban chua khoi tao danh sach!!!\n";
			break;
		case 7:
			if(fl == true)
			{
				int x;
				cout <<"Nhap x can tim:";
	            cin >> x;
				if(Delete(x))
				cout << x <<" duoc tim thay va da bi xoa!.Xuat de xem\n";
				else
					cout << x <<" Khong tim thay!\n"; 
				
			}
			break;		
		default:
			cout <<"Ban chon thoat!!!\n";
			break;
		}
		_getch();
	}while(chon >= 1 && chon < 8);
	return 0;
}