#include <iostream>
#include<stdio.h>
using namespace std;
#define MAX 20
int a[MAX][MAX];
int v;
int C[100];
int bfs[100];
int dfs[100];
int nbfs = 0;
int ndfs = 0;

struct Node
{
	int info;
	Node* link;
};
Node* first[MAX];
int n;
Node* sp;
Node* front, * rear;


void init()			//khoi tao
{
	for (int i = 0; i < n; i++)
		first[i] = NULL;
}

void input_dsk()		//7.1 nhap danh sach
{
	int d, x, m;
	cout << "Nhap so dinh do thi n: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "\n Nhap dinh thu " << i + 1 << ": ";
		cin >> d;
		insert_first(first[i], d);
		cout << "Nhap vao so dinh ke cua " << d << ": ";
		cin >> m;
		for (int j = 0; j < m; j++)
		{
			cin >> x;
			insert_first(first[i], x);
		}
	}

}

void output(Node* f)
{
	if (f != NULL)
	{
		Node* p = f;
		while (p != NULL)
		{
			cout << p->info << " ";
			p = p->link;
		}
	}
}

void output_dsk()
{
	if (n > 0)
		for (int i = 0; i < n; i++)
		{
			cout << endl << "Danh sach thu " << i + 1 << ": ";
			output(first[i]);
		}
	else
		cout << "Danh sach rong!";
}

void insert_first(Node*& f, int x)
{
	Node* p;
	p = new Node;
	p->info = x;
	p->link = f;
	f = p;
}

void khoitaodinh()
{
	for (int i = 0; i < n; i++)
		C[i] = 1;
}

//QUEUE
void init_queue()
{
	front = NULL;
	rear = NULL;

}

int isEmptyQ()
{
	if (front == NULL)
		return 1;
	return 0;
}

int push_queue( int x)
{
	Node* p = new Node;
	p->info = x;
	p->link = NULL;
	if (rear == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}

int pop_queue(int &x)
{
	if (front != NULL)
	{
		Node* p = front;
		x = p->info;
		front = p->link;
		if (front == NULL)
		{
			rear = NULL;
		}
		delete p;
		return 1;
	}
	return 0;

}

void BFS(int v)		//7.3
{
	int w, p;
	push_queue(v);
	C[v];
	while (front != NULL)
	{
		pop_queue(p);
		bfs[nbfs] = p;
		nbfs++;
		for (int w = 0; w < n; w++)
			if (C[w] && a[p][w] == 1)
			{
				push_queue(w);
				C[w] = 0;
			}
	}
}

//STACK
void init_stack()
{
	sp = NULL;
}

int isEmpty()
{
	if (sp == NULL)
		return 1;
	return 0;
}

int push_stack( int x)
{
	Node* p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
}

int pop_stack(int& x)
{
	if (sp != NULL)
	{
		Node* p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}

void DFS_stack(int s)		//7.4
{
	push_stack(s);
	dfs[ndfs] = s;
	ndfs++;
	C[s] = 0;
	int v = -1, u = s;
	while (isEmpty() == 0)
	{
		if (v == n)
			pop_stack(u);
		for (v = 0; v < n; v++)
			if (a[u][v] !=0 && C[v] == 1)
			{
				push_stack(u);
				push_stack(v);
				dfs[ndfs] = v;
				ndfs++;
				C[v] = 0;
				u = v;
				break;
			}
	}
}	   

void SearchBFS(int x, int v)		//7.5
{
	int p;
	Node* w;
	push_queue(v);
	C[v] = 0;
	while (front != NULL)
	{
		pop_queue(p);
		if (x == p)
		{
			cout << " Tim thay x= " << x << endl;
			return;
		}
		w = first[p];
		while (w != NULL)
		{
			if (C[w->info])
			{
				push_queue(w->info);
				C[w->info] = 0;
			}
			w = w->link;
		}
	}
}

int main()
{
	int x;
	init_queue();
	khoitaodinh();
	cout << " Vui long nhap gia tri x can tim: ";
	cin >> x;
	SearchBFS(x, 0);

	
	system("pause");
	return 0;

}