#include<iostream>
#include<fstream>
#include<stdlib.h>
#include <bits/stdc++.h>
using namespace std;
int Free[20],u,v,s,n;
int b[20][20];
queue <int> q;
// Queue
struct Node
{
	int info;
	Node* link;
};
Node* front, * rear;
void Qinit()
{
	front = NULL;
	rear = NULL;
}
void Qpush(int x)
{
	Node* p;
	p = new Node;
	p->info = x;
	p->link = NULL;
	if (rear == NULL)
	{
		front = p;
	}
	else
		rear->link = p;
	rear = p;
}
int Qpop(int &x)
{
	if (front != NULL)
	{
		Node* p = front;
		x = p->info;
		front = front->link;
		if (front == NULL)
		{
			rear = NULL;
		}
		delete p;
		return 1;
	}
	return 0;
}

void DFS(int u)
{
    cout << u << endl;
    Free[u] = false;
    for (int v = 1; v <= n; v++)
        if (b[u][v] == 1 && Free[v])
            DFS(v);
}
void BFS(int s)
{
     q.push(s);
     Free[s]=0;
     while (!q.empty())
     {
        int u = q.front();
        q.pop();
 
        cout << u << endl;
 
        for (int v=1; v<=n; v++)
            if (Free[v] && b[u][v]==1)
            {
                Free[v] = 0;
                q.push(v);
            }
     }
}
//8.5
void Search_by_BFS(int x, int v)
{
	int w, p;
	Qpush(v);
	C[v] = 0;
	while (front != NULL)
	{
		Qpop(p);
		if (x == p)
		{
			cout << x << " ton tai." << endl;
			return;
		}
		for (w = 0; w < n; w++)
			if (C[w] && a[p][w] == 1)
			{
				Qpush(w);
				C[w] = 0;
			}
	}
	cout << x << " khong ton tai.\n";
}

void output_DFS()
{
	for (int i = 0; i < ndfs; i++)
		cout << dfs[i] << "\t";

}
void output_BFS()
{
	for (int i = 0; i < nbfs; i++)
		cout << bfs[i] << "\t";

}

int main()
{
	//8.1
	ifstream dothi("do-thi-1.txt");
	if(! dothi.is_open())
    {
        cout << "Khong the mo file.\n";
        return 0;
    }
    else {
        dothi >> n;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                dothi >> b[i][j];
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << b[i][j];
            cout << " ";
        }
        cout << "\n";
    }
    cout <<"======================================================================================================" <<endl;
    cout <<"8.2: DFS"<<endl;
    for (int i = 1; i <= n; i++)
        Free[i] = 1;
    DFS(s);
    cout <<"======================================================================================================"<<endl;
    cout <<"8.3: BFS"<<endl;
    for (int i=1; i<=n; i++)
        Free[i]=1;
    BFS(s);
    dothi.close();
	cout << "Tim dinh: \n";
	init_BFS();
	cout << "Nhap dinh bat dau: "; cin >> bt;
	cout << "Nhap dinh can tim: "; cin >> x;
	Search_by_BFS(x, bt);
    system("pause");
	return 0;
	
}


