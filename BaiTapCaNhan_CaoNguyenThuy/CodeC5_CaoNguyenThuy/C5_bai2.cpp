//chuong 5 bai 2
#include <iostream>
#include <conio.h>
using namespace std;
int const MAXSIZE = 100;
int a[MAXSIZE][MAXSIZE];
int n;
int c[MAXSIZE]; 
int b[MAXSIZE];
int dfs[MAXSIZE]; 
int ndfs = 0; 
int bfs[100]; 
int nbfs=0; 

struct Node
{
	int info;
	Node *link;
};
Node *sp; 
Node * front, *rear;
Node *first[MAXSIZE];	
void initstack()
{
	sp = NULL;
}
void initqueue()
{
	front = NULL;
	rear = NULL;
}
void init()
{
	for(int i = 0; i < n; i++)
		first[i] = NULL;
}
void insert_last(Node *&f, int x)
{
	Node *p;
	p = new Node;
	p->info = x;
	p->link = f;
	if(f == NULL)
		f = p;
	else
	{
		Node *q = f;
		while(q->link != NULL)
			q = q->link;
		q->link = p;
	}
}
void khoitaoMTK()
{
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			a[i][j] = 0;
}
void input()
{
	char d,x;
	int m;
	cout << "Nhap so dinh do thi n: "; 
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cout << "\nNhap dinh thu " << i + 1 << ": ";
		cin >> d;
		insert_last(first[i], doiChar(d));
		cout << "Nhap vao so dinh ke cua " << d << ": ";
		cin >> m;
		for(int j = 0; j < m; j++)
		{
			cin >> x;
			insert_last(first[i],doiChar(x));
		}
   }
}
void output_list(Node *f)
{
	if (f != NULL)
	{
		Node *p = f;
		while (p != NULL)
		{
			cout << doiInt(p->info) << " ";
			p = p->link;
		}
	}
}
void outputds()
{
	if(n > 0)
		for(int i = 0; i < n; i++)
		{
			cout << endl << "Danh sach thu " << i+1 << ": ";
			output_list(first[i]);
		}
	else 
		cout << "rong";

}
int isEmpty()
{
	if (sp == NULL)
		return 1;
	return 0;
	
}
char doiInt(int gt)
{
	char kt ='A';
	for(int i = 0; i < gt; i++)
		kt++;
	return kt;
}
int doiChar(char kt)
{
	int gt = 0;
	if(kt >= 'a' && kt <= 'z')
		kt -= 32;
	for(char i = 'A'; i < kt; i++)
		gt++;
	return gt;
}
void Pushsta(int x)
{
	Node *p;
	p = new Node;
	p->info = x;
	p->link = sp;	
	sp = p;
}
int Popsta(int &x)
{
	if (sp!= NULL)
	{
		Node *p = sp;
		x = p -> info;
		sp= p ->link;
		delete p;
		return 1;
	}
	return 0;
}
void Pushqueue(int x)
{
	Node *p;
	p = new Node;
	p->info = x;
	p->link = NULL;	
	if (rear == NULL)
		front =p;
	else
		rear->link = p;
	rear = p;
}
int Popqueue(int &x)
{
	if (front!= NULL)
	{
		Node *p = front;
		x = p -> info;
		front = front ->link;
		if (front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}
void DFS(int s)
{       
    Pushsta(s); 
    dfs[ndfs] = s;
    ndfs++;
    c[s] = 0;
    int v = -1, u = s;
    while(!isEmpty())
    {
		if(v == n)
			Popsta(u);
		for(v = 0; v < n; v++)
			if(a[u][v] != 0 && c[v] == 1)
			{
				Pushsta(u);
  				Pushsta(v);
				dfs[ndfs] = v;
				ndfs++;
				c[v] = 0;
				u = v;
				break;
			}
     } 
} 
void outputDFS()
{
	for(int i = 0; i < ndfs; i++)
		cout << doiInt(dfs[i]) << "  ";
}
void khoitaochuaxet()
{
	for(int i = 0; i < n; i++)
		c[i] = 1;
}
void BFS(int v)
{
	int w, p;
	Pushqueue(v);
	c[v] = 0;
	while(front != NULL)
	{
		Popqueue(p);
		bfs[nbfs] = p;
		nbfs++;
		for(w = 0; w < n; w++)
			 if(c[w] && a[p][w] == 1)
			{
			   Pushqueue(w);
			   c[w] = 0;
			 }
	 }
}
void outputBFS()
{
	for(int i = 0; i < nbfs; i++) 
		cout << bfs[i] << " ";
}
void Search_by_BFS(int x, int v) 
{
	int w, p;
	Pushqueue(v);
	b[v] = 0;
	while(front != NULL)
	{
		Popqueue(p);
		if (x == p)
		{
			cout << doiInt(x) << " ton tai";
			return;
		}
		for(w = 0; w < n; w++)
			 if(b[w] && a[p][w] == 1)
			 {
			   Pushqueue(w);
			   b[w] = 0;
			 }
	}
	cout << doiInt(x) << " khong ton tai";
}
bool checkKT(char kt)
{
	if(kt >= 'A' && kt <= 'Z')
		return true;
	else
		if(kt >= 'a' && kt <= 'z')
			return true;
		else
			return false;
}
void chuyen1MTK(Node *f)
{
	Node *p = f;
	int i = p->info;
	p = p->link;
	while(p != NULL)
	{
		int j = p->info;
		a[i][j] = 1;
		p = p->link;
	}
}
void chuyenMTK()
{
	if(n > 0)
		for(int i = 0; i < n; i++)
			chuyen1MTK(first[i]);
	else 
		cout << "rong";

}
int main()
{
	initstack();
	initqueue();
	int chon;
	bool in = false;
	do{
		system("cls");
		cout << "1. Khoi tao ds ke va nhap\n"
			 << "2. Xuat ds ke\n"
			 << "3. Xuat theo BFS\n"
			 << "4. Xuat theo DFS\n"
			 << "4. Tim kiem\n"
			 << "5. Thoat\n";
		cout << "ban chon: ";
		cin >> chon;
		switch(chon)
		{
		case 1:
			init();
			input();
			in = true;
			break;
		case 2:
			if(in == true)
				outputds();
			else
				cout << "Chua khoi tao ds";
			break;
		case 3:
			if(in == true)
			{
				
				char kt;
				do{
					cout << "Nhap vao dinh bat dau: ";
					cin >> kt;
					if(checkKT(kt) == false)
						cout << "Vui long nhap ky tu\n";
				}while(checkKT(kt) == false);
				khoitaochuaxet();
				khoitaoMTK();
				BFS(doiChar(kt));
				outputBFS();
			}
			else
				cout << "Chua khoi tao ds";
			break;
		case 4:
			if(in == true)
			{
				
				char kt;
				do{
					cout << "Nhap vao dinh bat dau: ";
					cin >> kt;
					if(checkKT(kt) == false)
						cout << "Vui long nhap ky tu\n";
				}while(checkKT(kt) == false);
				khoitaochuaxet();
				khoitaoMTK();
				DFS(doiChar(kt));
				outputDFS();
			}
			else
				cout << "Chua khoi tao ds";
			break;
		case 5:
			if(in == true)
			{
				
				char b, f;
				do{
					cout << "Nhap vao dinh bat dau: ";
					cin >> b;
					if(checkKT(b) == false)
						cout << "Vui long nhap ky tu\n";
				}while(checkKT(b) == false);
				do{
					cout << "Nhap vao dinh muon tim kiem: ";
					cin >> f;
					if(checkKT(f) == false)
						cout << "Vui long nhap ky tu\n";
				}while(checkKT(f) == false);
				Search_by_BFS(doiChar(f),doiChar(b));
			}
			else
				cout << "Chua khoi tao ds";
			break;
		default:
			cout << "Ban chon thoat\n";
		}
		_getch();
	}while(chon >= 1 && chon <= 5);
	return 0;
}