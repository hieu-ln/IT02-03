#include <iostream>
#include <conio.h>
using namespace std;

struct Node {
	int sm;
	int hs;
	Node *next;
};

struct List {
	Node *head, *tail;
};

void Init(List &l) {
	l.head = l.tail = NULL;
}

Node *creatNode(int hs, int sm) {
	Node *p = new Node;
	if (p == NULL) exit(1);
	p->sm = sm;
	p->hs = hs;
	p->next = NULL;
	return p;
}

Node* addnode(Node* start, int coeff, int power)
{
	// Create a new node
	Node* newnode = new Node;
	newnode->hs = coeff;
	newnode->sm = power;
	newnode->next = NULL;

	// If linked list is empty
	if (start == NULL)
		return newnode;

	// If linked list has nodes
	Node* ptr = start;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = newnode;

	return start;
}

void addTail(List &l, Node *p) {
	if (l.head == NULL) l.head = l.tail = p;
	else {
		l.tail->next = p;
		l.tail = p; // cap nhap l.tail
	}
}

void nhap(List &l) {
	int x, n;
	cout << "\nNhap bac cua da thuc: "; cin >> n;
	for (int i = n; i >= 0; i--) {
		cout << "\nNhap he so cua x^" << i << ": ";
		cin >> x;
		Node *p = creatNode(x, i);
		addTail(l, p);
	}
}

void cong(List &l, List l1, List l2) {
	Node *p = new Node, *q = new Node;
	if (l1.head->sm >= l2.head->sm) {
		l = l1;
		p = l2.head;
	}
	else {
		l = l2;
		p = l1.head;
	}

	q = l.head;
	while (q->sm > p->sm) q = q->next; // tim dc q sao cho q->sm == p->sm
	while (q != NULL) {
		q->hs = q->hs + p->hs;
		p = p->next;
		q = q->next;
	}
}
void tru(List &l, List l1, List l2)
{
	Node *p = new Node, *q = new Node;
	if (l1.head->sm >= l2.head->sm) {
		l = l1;
		p = l2.head;
	}
	else {
		l = l2;
		p = l1.head;
	}

	q = l.head;
	while (q->sm > p->sm) q = q->next; // tim dc q sao cho q->sm == p->sm
	while (q != NULL) {
		q->hs = q->hs - p->hs;
		p = p->next; q = q->next;
	}

}

void chia(List &l, List l1, List l2) {
	cout << "Too hard to achieve";

}


void xuat(List l) {
	Node *ptr = l.head;
	while (ptr->next != NULL)
	{
		cout << ptr->hs << "x^" << ptr->sm;
		if (ptr->next != NULL && ptr->next->hs >= 0) cout << " + ";
		ptr = ptr->next;
	}
	cout << ptr->hs << "\n";
}

void removeDuplicates(Node* start)
{
	Node *ptr1, *ptr2, *dup;
	ptr1 = start;

	/* Pick elements one by one */
	while (ptr1 != NULL && ptr1->next != NULL) {
		ptr2 = ptr1;


		while (ptr2->next != NULL) {


			if (ptr1->sm == ptr2->next->sm) {

				ptr1->hs = ptr1->hs + ptr2->next->hs;
				dup = ptr2->next;
				ptr2->next = ptr2->next->next;

				delete (dup);
			}
			else
				ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
}

Node* multiply(Node* poly1, Node* poly2,
	Node* poly3)
{

	Node *ptr1, *ptr2;
	ptr1 = poly1;
	ptr2 = poly2;
	while (ptr1 != NULL) {
		while (ptr2 != NULL) {
			int coeff, power;

			coeff = ptr1->hs * ptr2->hs;

			power = ptr1->sm + ptr2->sm;

			poly3 = addnode(poly3, coeff, power);

			ptr2 = ptr2->next;
		}
		ptr2 = poly2;

		ptr1 = ptr1->next;
	}

	removeDuplicates(poly3);
	return poly3;
}


void MENU()
{
	List tong, hieu, tich, thuong, l1, l2;
	Init(tong);Init(hieu);Init(tich);Init(thuong);
	Init(l1); Init(l2);
	cout << "\nNhap P(x): "; nhap(l1);
	cout << "\nNhap Q(x): "; nhap(l2);
	int chon;
	do {
		system("cls");
		cout << "1. Xuat da thuc P(x): \n2. Xuat da thuc Q(x): \n3. Tong hai da thuc\n4. Hieu hai da thuc \n5. Tich hai da thuc \n6. Thuong hai da thuc \n7. Thoat \nBam chon: ";
		cin >> chon;
		cout << endl;
		switch (chon)
		{
		case 1:
			cout << "Da thuc P(X) ";
			cout << "\nP(x) = "; xuat(l1);
			cout << "Bam phim Enter de tiep tuc ";
			break;
		case 2:
			cout << "da thuc Q(x) ";
			cout << "\nQ(x) = "; xuat(l2);
			cout << "Bam phim Enter de tiep tuc ";
			break;
		case 3:
			cout << "\nP(x): ";xuat(l1);
			cout << "\nQ(x): ";xuat(l2);
			cout << " Tong hai da thuc: " << endl;
			cong(tong, l1, l2);
			cout << "R(x) = "; xuat(tong);
			cout << "Bam phim Enter de tiep tuc ";
			break;
		case 4:
			cout << "\nP(x): ";xuat(l1);
			cout << "\nQ(x): ";xuat(l2);
			cout << "Hieu hai da thuc " << endl;
			tru(hieu, l1, l2);
			cout << "R(x) = "; xuat(hieu);
			cout << "Bam phim Enter de tiep tuc ";
			break;
		case 5:
			cout << "\nP(x): ";xuat(l1);
			cout << "\nQ(x): ";xuat(l2);
			cout << "Tich hai da thuc " << endl;
			tich.head = multiply(l1.head, l2.head, tich.head);
			cout << "R(x) = "; xuat(tich);
			cout << "Bam phim Enter de tiep tuc ";
			break;
		case 6:
			cout << "\nP(x): ";xuat(l1);
			cout << "\nQ(x): ";xuat(l2);
			cout << "Thuong hai da thuc " << endl;
			chia(thuong, l1, l2);
			cout << "R(x) = "; xuat(thuong);
			cout << "Bam phim Enter de tiep tuc ";
			break;
		default:
			cout << "CHAO TAM BIET !!! -_- " << endl;
		}
		_getch();
	} while (chon > 0 && chon < 7);
}


int main() {
	MENU();
	system("pause");
	return 0;
}
