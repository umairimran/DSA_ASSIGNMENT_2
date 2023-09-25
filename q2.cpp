#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;
template <typename T>
class node {
public:
	T data;
	node* up;
	node* down;
	node* left;
	node* right;
	node* next;
	bool visited;
	node(T value)
	{
		data = value;
		up = nullptr;
		down = nullptr;
		right = nullptr;
		next = nullptr;
		down = nullptr;
		visited = false;
	}

};

template <typename T>
class linkedList { 
public:
	node<T>* head;
	int rows; 
	int cols;
	linkedList()
	{
		head = nullptr;
		rows = 0;
		cols = 0;
	}
	void insert(T value)
	{
		node <T> *newNode = new node<T>(value);
		if (head == nullptr)
		{
			head = newNode;

		}
		else {
			node<T>* current = head;
			while (current->next != nullptr)
			{
				current = current->next;
			}
			current->next = newNode;
			current->next->next = nullptr;
		}
	}
	void print(int rows,int cols) {
		this->rows = rows;
		this->cols = cols;
		linkedList<int> maze;
		node<linkedList<int>>* current;
		current = head;
		node<linkedList<int>>* l=head;
		linkedList <int> l2;		
		bool connected = false;
	
		while (current->next!=nullptr)
		{
			node <int>* subcurrent = current->data.head;		
			node<int>* subcurrent2=nullptr;
			if (current != nullptr)
			{
				connected = true;
				subcurrent2 = current->next->data.head;
			}
			if (connected == true)
			{
				while (subcurrent != nullptr)
				{
					if (subcurrent!= nullptr)
					{
						subcurrent->right = subcurrent->next;
						
						if (subcurrent->right != nullptr)
						{
						  subcurrent->right->left = subcurrent;
						
						subcurrent2->right = subcurrent2->next;

						subcurrent2->right->left = subcurrent2;
						}

					}
					subcurrent->down = subcurrent2;
					subcurrent2->up = subcurrent;
					subcurrent = subcurrent -> next;
					subcurrent2 = subcurrent2->next;
				}
				
			}
		


			

			current = current->next;
		}
	

		l2.head = l->data.head;
	
		printMaze(l2.head);
		
		


		
	}
	void readFromFile(string filename);
	void printMaze(node<int> * h);
	int clueRow(int data);
	int clueCol(int data);
	
	void eliteNode(node<int>* h);
	void eliteNodeFound(int d);


};
int main()
{
	linkedList<int> l;
	l.readFromFile("maze.txt");
	
}

template<typename T>
void linkedList<T>::printMaze(node<int> * h)
{
	node<int>* current = h;
	while (current != nullptr)
	{
		node<int>* subcurrent = current;;
		while (subcurrent != nullptr)
		{
			cout << subcurrent->data << "  ";
			subcurrent = subcurrent->right;
		}
		cout << endl;
		current = current->down;
	}
	
	eliteNode(h);

}

template<typename T>
int linkedList<T>::clueRow(int data)
{
	int sum=0;
	while (data > 0) {
		int digit = data % 10; // Extract the last digit
		sum += digit; // Add the digit to the sum
		data /= 10; // Remove the last digit
	}
	sum = sum % rows;
	sum += 1;
	return sum;
}

template<typename T>
int linkedList<T>::clueCol(int data)
{
	int count=0;
	while (data > 0) {
		int digit = data % 10; // Extract the last digit
		count++; // Add the digit to the sum
		data /= 10; // Remove the last digit
	}
	return count;;
}

template<typename T>
void linkedList<T>::eliteNode(node<int>* h)
{
	node<int>* current = h;

	bool eliteFound = false;
	int rowClue;
	int colClue;
    node<int>* temp=new node<int>(-1);
	cout << endl << endl << endl;
	while (eliteFound == false)
	{   
		
		rowClue = clueRow( current->data);
		colClue = clueCol(current->data);

		current = h;
		for (int i = 1; i < rowClue; i++)
		{
			current = current->down;
		}
		for (int j = 1; j < colClue; j++)
		{
			current = current->right;
		}
		if (temp->data == current->data) 
		{
			eliteFound = true;
			eliteNodeFound(current->data);
			break;
		}
		if (current->visited == true)
		{
			cout << "\nNo elite node in maze \n";
			break;
		}
		current->visited = true;
		cout << " -> " << current->data;
		temp = current;
		



		
	}
	cout << endl << endl << endl;
	cout << endl << endl << endl;
}

template<typename T>
void linkedList<T>::eliteNodeFound(int d)
{
	cout << "\n\n\nElite node: " << d;
}


template<typename T>
void  linkedList<T>::readFromFile(string filename)
{

	linkedList<linkedList<int>> l;
	ifstream inputFile(filename);
	if (!inputFile.is_open())
	{
		cout << "Unable to open input file." << endl;
		return;
	}
	string line;
	while (getline(inputFile, line))
	{
		istringstream iss(line);
		string token;
		rows += 1;

		linkedList<int> ll;
		while (getline(iss, token, ','))

		{
			int value = stoi(token);

			cols += 1;
			ll.insert(value);
		}
		l.insert(ll);

	}
	cols =cols / rows;
	
	
	
	
	l.print(rows,cols);

}
