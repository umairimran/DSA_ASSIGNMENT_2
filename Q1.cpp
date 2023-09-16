#include <iostream>
using namespace std;
class node {
public:
	int data;
	node* next;
	node* subLinkedList;
	node(int d)
	{
		data = d;
		next = nullptr;
		subLinkedList = nullptr;

	}
};
class linkedList {
public:
	node* head;
	linkedList()
	{
		head = nullptr;
	}
	void insertInList(int d)
	{
		node* current = head;
		node* newNode = new node(d);
		if (head == nullptr)
		{
			head = newNode;
		}
		else {
			while (current->next != NULL)
			{
				current = current->next;
			}
			current->next = newNode;
		}
	}
	void print()
	{
		node* current = head;
		while (current != NULL)
		{
			cout << current->data << " ";
			current = current->next;
		}
	}
	void createSubList(int k)
	{
		linkedList l2;
		int count = 1;
		node* current = head;
		while (current->next != nullptr)
		{

			count++;
			current = current->next;
		}
		if (count % k == 0)
		{
			current = head;
			count = 1;
			l2.insertInList(0);
			l2.head->subLinkedList = current;

			while (current->next != nullptr)
			{
				if (count == k)
				{
					l2.insertInList(0);
					node* current2 = l2.head;
					while (current2->next != nullptr)
					{
						current2 = current2->next;
					}
					node* temp = current->next;
					current2->subLinkedList = temp;
					current->next = nullptr;
					current = temp;


					count = 1;
					continue;
				}
				count++;
				current = current->next;

			}

			node* current = l2.head;
			while (current != nullptr)
			{
				node* subListPrint = current->subLinkedList;
				cout << "[ ";
				while (subListPrint != nullptr)
				{
					cout << subListPrint->data << ",";
					subListPrint = subListPrint->next;

				}
				cout << "]->";
				current = current->next;
			}

		}
		if (count % k != 0)
		{
			int sublistsToMake = count / k;


		}
		if (count < k)
		{


		}


	}


};
int main()
{
	linkedList l1;
	for (int i = 1; i < 16; i++)
	{
		l1.insertInList(i);
	}

	l1.createSubList(3);
}