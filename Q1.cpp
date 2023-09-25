#include <iostream>
using namespace std;
template<typename T>
class node {
public:
	T data;
	node<T> *next;
	node( T  d)
	{data = d;
		next = nullptr;
	}

};
template<typename T>

class linkedList {
public:
	node<T>* head;
	linkedList()
	{
		head = nullptr;
	}
	void insertAtEnd(T  d)
	{
		node<T>* current;
		node<T>* newnode = new node<T>(d);
		
		if (head == nullptr)
		{
			head = newnode;
		}
		else {
			current = head;
			while (current->next != nullptr)
			{
				current = current->next;
			}
			current->next = newnode;
		}
	}

	void display() {
		node<T>* current = head;
		while (current) {
			std::cout << current->data << " ";
			current = current->next;
		}
	
	}
	void makeSublists(int k)
	{
		if (k <= 0)
		{
			cout << "Invalide value of k.";
			return;
		}
		linkedList<int> sublist;
		linkedList<linkedList<int>> l3;
		node<T>* current = head;
		while (current != nullptr)
		{
			for (int i = 0; i < k && current!=nullptr; i++)
			{
				sublist.insertAtEnd(current->data);
				current = current->next;
			}
			l3.insertAtEnd(sublist);
			sublist.head = nullptr;
		}

		if (current != nullptr)
		{
			while (current != nullptr)
			{
				sublist.insertAtEnd(current->data);
				current = current->next;
			}
			
			l3.insertAtEnd(sublist);
		}
		node<linkedList<int>>* c = l3.head;
	//	current = l3.head;
		while (c != nullptr)
		{
			cout << "[";
			c->data.display();
			cout << "]->";
			
			c = c->next;
		}
	}

};
int main()
{
	linkedList<int> l1;
	int n = 25;
	for (int i = 0; i < n; i++)
	{
		l1.insertAtEnd(i + 1);
	}
	l1.makeSublists(5);
}