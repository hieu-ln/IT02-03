#include <iostream>
#include <conio.h>
using namespace std;
#define MAX 100
int a[MAX];
int front, rear; // câu 7.1

void init(int a[], int& front, int& rear)
{
	front = -1;
	rear = -1;
} // câu 7.2
int isEmpty()
{
	if (front == NULL)
		return 1;
	return 0;
} // câu 7.3
int isFull()
{
	if ((rear - front) == MAX - 1)
		return 1;
	return 0;
} // câu 7.4
int Pust(int a[], int& front, int& rear, int x)
{
	if (isFull())
		return 0;
	else
	{
		if (front == -1)
			front = 0;
		if (rear == MAX - 1)
			rear = -1;
		a[++rear] = x;
		return 1;
	}
} // câu 7.5
int Pop(int a[], int& x)
{
	if (front != -1)
	{
		x = a[front];
		if (front == rear)
		{
			front = -1;
			rear = -1;
		}
		else
		{
			front++;
			if (front > MAX - 1)
				front = 0;
		}
		return 1;
	}
	return 0;
} // câu 7.6

int main()
{
	int choose, x;
	bool create = false;
	do {
		system("cls");
		cout << "MENU\n"
			<< "1. Create an empty list.\n"
			<< "2. Check the list is empty.\n"
			<< "3. Check the list is full.\n"
			<< "4. Add value into the list.\n"
			<< "5. Take value out the list.\n"
			<< "6. Exit.\n You choose: ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			cout << "You choose 'Create an empty list'.\n";
			init(a, front, rear);
			cout << "Proccess complete.\n";
			create = true;
			break;
		case 2:
			if (create)
			{
				cout << "You choose 'Check the list empty.\n";
				if (isEmpty() == 1)
					cout << "Your list is empty.\n";
				else
					cout << "Your list is not empty.\n";
			}
			else
				cout << "You have not create an empty list yet. Please choose 'Create an empty list'.\n";
			break;
		case 3:
			if (create)
			{
				cout << "You choose 'Check the list full.\n";
				if (isFull() == 1)
					cout << "Your list is full.\n";
				else
					cout << "Your list is not full.\n";
			}
			else
				cout << "You have not create an empty list yet. Please choose 'Create an empty list'.\n";
			break;
		case 4:
			if (create)
			{
				cout << "You choose 'Add value into the list'.\n";
				cout << "Please input a value that you want to add: ";
				cin >> x;
				if (Pust(a, front, rear, x))
					cout << "Proccess complete.\n";
				else
					cout << "Proccess fail.\n";
			}
			else
				cout << "You have not create an empty list yet. Please choose 'Create an empty list'.\n";
			break;
		case 5:
			if (create)
			{
				cout << "You choose 'Take value out the list'.\n";
				cout << "Please input a value that you want to take: ";
				cin >> x;
				if (Pop(a, x))
					cout << "Proccess complete.\n";
				else
					cout << "Proccess fail.\n";
			}
			else
				cout << "You have not create an empty list yet. Please choose 'Create an empty list'.\n";
			break;
		default:
			cout << "You choose 'Exit'. See you again!\n";
			return 0;
		}
		_getch();
	} while (choose >= 1 && choose <= 5);
	return 0;
}



