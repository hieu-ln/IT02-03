//chuong 5 bai 1
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
	n = 0;
}
void inputds()
{
	cout << "Nhap so dinh do thi n: "; 
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cout << "Nhap vao dong thu "<< i + 1 << ": ";
		for(int j = 0; j < n; j++)
			cin >> a[i][j];
	}
}
void outputds()
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
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
int main()
{
	initstack();
	initqueue();
	int chon;
	bool in = false;
	do{
		system("cls");
		cout << "1. Khoi tao ma tran ke va nhap\n"
			 << "2. Xuat ma tan ke\n"
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
			inputds();
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