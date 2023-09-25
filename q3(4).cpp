#include <iostream>
#include <Windows.h>
#include <cstdlib>
using namespace std;
class node {
	friend class linkedList;
public:
	int data;
	bool visited;
	node* right;
	node* up;
	node* left;
	node* down;
	node(int d)
	{
		data = d;
		visited = false;
		right = nullptr;
		up = nullptr;
		left = nullptr;
		down = nullptr;
	}
	
	
};
class linkedList {
	
public:
	node* head;
	linkedList()
	{
		head = nullptr;
	}
	void makePattern(int number);
	
	int* seperateDigitsOfTime(string time);
//     0  1
//     2  3
//     4  5
	void digit_0_pattern();
	void digit_1_pattern();
	void digit_2_pattern();
	void digit_3_pattern();
	void digit_4_pattern();
	void digit_5_pattern();
	void digit_6_pattern();
	void digit_7_pattern();
	void digit_8_pattern();
	void digit_9_pattern();

    void displayTime(int* &numbers);
	void additionOfMinutes(int minutes,string & time);
	void subtractionOfMinutes(int minutes,string & time);
	void additionOfHours(int hours,string  & time);
	void subtractionOfHours(int hours,string & time);
	void print(int x,int y);
	void gotoxy(int x,int y);
    int getXCoordinate()
    {
        HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO  bufferInfo;
        GetConsoleScreenBufferInfo(hconsole, &bufferInfo);
        int currentX = bufferInfo.dwCursorPosition.X;
        int currentY = bufferInfo.dwCursorPosition.Y;
        return currentX;

    }
    int getYCoordinate()
    {
        HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO  bufferInfo;
        GetConsoleScreenBufferInfo(hconsole, &bufferInfo);
        int currentX = bufferInfo.dwCursorPosition.X;
        int currentY = bufferInfo.dwCursorPosition.Y;
        return currentY;
    }
};
int main()
{
    string time;	
    linkedList l;
    cout << "Enter Time [00:00] :";
        cin >> time;
      
        int* timeDigits = l.seperateDigitsOfTime(time);
        l.displayTime(timeDigits);
        int choice = 0;
        int i = 0;
       
            
            cout << " 1:Addition Of Minutes: \n";
            cout << " 2:Subtraction of minutes: \n";
            cout << " 3:Addition of hours: \n";
            cout << " 4:Subtraction of hours: \n";
            cin >> choice;
            
            switch (choice)

            {
            case 1:
                cout << "Enter minutes: ";
                cin >> choice;

                l.additionOfMinutes(choice, time);
           
                Sleep(300);
                break;
            case 2:
                cout << "Enter minutes : ";
                cin >> choice;

                l.subtractionOfMinutes(choice, time);
                break;
            case 3:
                cout << "Enter hours :";
                cin >> choice;

                l.additionOfHours(choice, time);
                break;
            case 4:
                cout << "Enter hours : ";
                cin >> choice;

                l.subtractionOfHours(choice, time);
                break;
            }

        
  
}

void linkedList::print(int x,int y)
{
   
    node* current = head;
    bool ok = true;
    while (ok == true)
    {
        ok = false;
        if (current->right != nullptr && current->right->visited == false)
        {
            
            if (current->right->data == 5 && current->right->up == nullptr && current->right->down == nullptr && current->right->right == nullptr)
            {
                ok = false;
                cout << "*******" << endl;
                current->visited = true;
            }
            else {
            ok = true;
           
            cout << "*******" << endl;
            current->visited = true;
            }

            if ((current->right->up != nullptr && current->right->up->visited == false) ||
                (current->right->down != nullptr && current->right->down->visited == false) ||
                (current->right->right != nullptr && current->right->right->visited == false) ||
                (current->right->left != nullptr && current->right->left->visited == false))
            {
                current = current->right;
            }
        }
        if (current->left != nullptr && current->left->visited == false)
        {
            if (current->left->data == 4 && current->left->up == nullptr && current->left->down == nullptr && current->left->left == nullptr)
            {
                ok = false;
                cout << "*******" << endl;
                current->visited = true;
            }
            else {
             ok = true;
             cout << "*******" << endl;
             current->visited = true;
            }

            if ((current->left->up != nullptr && current->left->up->visited == false) ||
                (current->left->down != nullptr && current->left->down->visited == false) ||
                (current->left->right != nullptr && current->left->right->visited == false) ||
                (current->left->left != nullptr && current->left->left->visited == false))
            {
                current = current->left;
            }

        }
        if (current->up != nullptr && current->up->visited == false)
        {
            if (  current->up->data==3
                && current->up->left == nullptr && current->up->right == nullptr)
            {
                current->visited = true;
                ok = false;

 
                int currentX = getXCoordinate();
                int currentY = getYCoordinate();
                gotoxy(currentX + 6, currentY - 2);
                cout << "*";
                gotoxy(currentX +6, currentY - 3);
                cout << "*";
                gotoxy(currentX, currentY);

            }
  
            else if (current->up->data == 3  && current->up->right == nullptr && current->up->left != nullptr)
            {
                current->visited = true;
                ok = false;
              
                int currentX = getXCoordinate();
                int currentY = getYCoordinate();
                gotoxy(getXCoordinate() +6, getYCoordinate() - 2);
                cout << "*";
                gotoxy(currentX, currentY);
       
                

            }
            else if (current->up->data == 1 && current->up->right == nullptr && current->up->up == nullptr)
            {
                current->visited = true;
                current->up->data = 99;  
                int currentX = getXCoordinate();
                int currentY = getYCoordinate();
              

                


                gotoxy(getXCoordinate() + 6, getYCoordinate() - 2);
                cout << "*";
                gotoxy(currentX, currentY);
                if (current->up->data == 99 &&
                    current->data == 3 &&
                    current->left->data == 2
                    && current->left->down!=nullptr)
                {
                    current->visited = false;
                    current = current->left;
                    
                }
            }
            else {
                ok = true;
                cout << "*" << endl;  
                current->visited = true;
            }

            if (current->up->up != nullptr 
                && current->up->up->visited == false
                
                )
            {
                current = current->up;

            }
        }
        if (current->down != nullptr && current->down->visited == false)
        {

            if (current->down->data == 4 && current->down->down == nullptr
                && current->down->right == nullptr && current->down->left == nullptr)
            {
             
                cout << "*" << endl;
            }
            else if ((current->down->data == 3 || current->down->data==5))
            {
               
                cout << "      *" << endl;
                current->visited = true;

            }
            else {
            ok = true;
            cout << "*" << endl;
            current->visited = true;
            }
            if (current->down->data == 5 && current->down->down == nullptr && current->down->right == nullptr && current->down->left == nullptr)
            {
                ok = false;
            }
            if ((current->down->up != nullptr && current->down->up->visited == false) ||
                (current->down->down != nullptr && current->down->down->visited == false) ||
                (current->down->right != nullptr && current->down->right->visited == false) ||
                (current->down->left != nullptr && current->down->left->visited == false))
            {
                current = current->down;
            } 

        }
    }
}



int * linkedList::seperateDigitsOfTime(string time)
{
   
    int * numbers=new int[4];
    numbers[0] = int(time[0] - 48);
    numbers[1] = int(time[1] - 48);
    numbers[2] = int(time[3] - 48);
    numbers[3] = int(time[4] - 48);
 
    return numbers;
 
    
   /* gotoxy(50,50);*/
}

void linkedList::digit_0_pattern()
{
    node* current = nullptr;
    head = new node(0);
    current = head;
    current->right = new node(1);
    current->right->left = current;
    current->down = new node(2);
    current->down->up = current;
    current = current->down;
    current->down = new node(4);
    current->down->up = current;
    current = current->down;
    current->right = new node(5);
    current->right->left = current;
    current = current->right;
    current->up = new node(3);
    current->up->down = current;
    current = current->up;
    current->up = head->right;



}

void linkedList::digit_1_pattern()
{
    node* current;
    head = new node(0);
    current = head;
    current->down = new node(2);
    current->down->up = current;
    current = current->down;
    current->down = new node(4);
    current->down->up = current;
    current = current->down;
    current->down = nullptr;
}

void linkedList::digit_2_pattern()
{
    node* current;
    head = new node(0);
    current = head;
    current->right = new node(1);
    current->right->left = current;
    current = current->right;
    current->down = new node(3);
    current->down->up = current;
    current = current->down;
    current->left = new node(2);
    current->left->right = current;
    current = current->left;
    current->down = new node(4);
    current->down->up = current;
    current = current->down;
    current->right = new node(5);
    current->right->left = current;
    current = current->right;

}

void linkedList::digit_3_pattern()
{
    node* current = nullptr;
    head = new node(0);
    current = head;
    current->right = new node(1);
    current->right->left = current;
    current = current->right;
    current->down = new node(3);
    current->down->up = current;
    current = current->down;
    current->left = new node(2);
    current->left->right = current;
    current->down = new node(5);
    current->down->up = current;
    current = current->down;
    current->left = new node(4);
    current->left->right = current;
    current = current->left;
}

void linkedList::digit_4_pattern()
{
    node* current = nullptr;
    head = new node(0);
    current = head;
    current->down = new node(2);
    current->down->up = current;
    current = current->down;
    current->right = new node(3);
    current->right->left = current;
    current = current->right;
    current->up = new node(1);
    current->up->down = current;
    current->down = new node(5);
    current->down->up = current;
    current = current->down;
}

void linkedList::digit_5_pattern()
{
    node* current = nullptr;
    head = new node(0);
    current = head;
    current->right = new node(1);
    current->right->left = current;
    current->down = new node(2);
    current->down->up = current;
    current = current->down;
    current->right = new node(3);
    current->right->left = current;
    current = current->right;
    current->down = new node(5);
    current->down->up = current;
    current = current->down;
    current->left = new node(4);
    current->left->right = current;
    current = current->left;
}

void linkedList::digit_6_pattern()
{
    node* c = nullptr;
    head = new node(0);
    c = head;
    c->right = new node(1);
    c->right->left = c;
    c->down = new node(2);
    c->down->up = c;
    c = c->down;
    c->right = new node(3);
    c->right->left = c;
    c->down = new node(4);
    c->down->up = c;
    c = c->down;
    c->right = new node(5);
    c->right->left = c;
    c = c->right;
    c->up = c->left->up->right;
   // c->left->up->right->down = c;
}

void linkedList::digit_7_pattern()
{
    node* current;
    head = new node(0);
    current = head;
    current->right = new node(1);
    current->right->left = current;
    current = current->right;
    current->down = new node(3);
    current->down->up = current;
    current = current->down;
    current->down = new node(5);
    current->down->up = current;
    current = current->down;
}

void linkedList::digit_8_pattern()
{
    node* current = nullptr;
    head = new node(0);
    current = head;
    current->right = new node(1);
    current->right->left = current;
    current->down = new node(2);
    current->down->up = current;
    current = current->down;

    current->right = new node(3);
    current->right->left = current;
    current->right->up = current->up->right;
   // current->up->right->down = current->right;
    current->down = new node(4);
    current->down->up = current;
    current = current->down;
    current->right = new node(5);
    current->right->up = current->up->right;
    //current->up->right->down = current->right;
    current = current->right;
}

void linkedList::digit_9_pattern()
{
    node* current = nullptr;
    head = new node(0);
    current = head;
    current->right = new node(1);
    current->right->left = current;
    current->down = new node(2);
    current->down->up = current;
    current = current->down;
    current->right = new node(3);
    current->right->left = current;
    current = current->right;
    current->up = current->left->up->right;
    //current->left->up->right->down = current;
    current->down = new node(5);
    current->down->up = current;
    current = current->down;

}



void linkedList::displayTime(int*& numbers)
{
    linkedList l[4];
   
    if (numbers[0] < 0 || numbers[0]>2)
    {
        cout << endl << "Entered Wrong :" << endl;;
        exit(0);

    }
    if (numbers[0] == 1 && (numbers[1] < 0 || numbers[1]>9))
    {
        cout << endl << "Entered Wrong :" << endl;;
        exit(0);
    }
    if (numbers[0] == 2 && (numbers[1] < 0 || numbers[1]>4))
    {
        cout << endl << "Entered Wrong :" << endl;;
        exit(0);
    }
    if (numbers[2] < 0 || numbers[2]>6)
    {
        cout << endl << "Entered Wrong :" << endl;;
        exit(0);
    }
    if ((numbers[2] > 0 && numbers[2] < 7) && (numbers[3] < 0 || numbers[3]>9))
    {
        cout << endl << "Entered Wrong :" << endl;;
        exit(0);
    }

    l[0].makePattern(numbers[0]);
    l[1].makePattern(numbers[1]);
    l[2].makePattern(numbers[2]);
    l[3].makePattern(numbers[3]);
    l[0].print(5,5);
    cout << endl << endl<<endl;
    l[1].print(10,10);
    cout << endl << endl << endl;
    l[2].print(20,20);
    cout << endl << endl << endl << endl;
    l[3].print(30,30);
    cout << endl << endl << endl << endl;
}

void linkedList::additionOfMinutes(int minutes, string  & time)
{
  
    
    int* numbers = seperateDigitsOfTime(time);
   
    int currentMinutes = (numbers[2] * 10) + numbers[3];
    currentMinutes += minutes;
    if (currentMinutes >= 60)
    {
        int hours = currentMinutes / 60;
        cout << hours << endl;
  
        
        numbers[3] = currentMinutes % 10;;
        numbers[2] = currentMinutes / 10;
        system("CLS");
        additionOfHours(hours, time);
       currentMinutes %= 60;
    }
    else {
        numbers[3] = currentMinutes % 10;;
        numbers[2] = currentMinutes / 10;
        system("CLS");

        displayTime(numbers);
    }

}
void linkedList::additionOfHours(int hours, string & time)
{
    int* numbers = seperateDigitsOfTime(time);
    int currentHours = (numbers[0] * 10) + numbers[1];
    currentHours += hours;
    if (currentHours >= 24)
    {
        currentHours %= 24;
    }
    numbers[1] = currentHours % 10;;
    numbers[0] = currentHours/10;
    system("CLS");
    displayTime(numbers);



  
}
void linkedList::subtractionOfHours(int hours, string & time)
{
    int* numbers = seperateDigitsOfTime(time);
    int currentHours = (numbers[0] * 10) + numbers[1];
    currentHours -= hours;
    if (currentHours < 0)
    {
        currentHours = 24 + currentHours;
    }
    numbers[1] = currentHours % 10;;
    numbers[0] = currentHours / 10;
    system("CLS");
    displayTime(numbers);
}
void linkedList::subtractionOfMinutes(int minutes, string  & time)
{
    int* numbers = seperateDigitsOfTime(time);
    int currentMinutes = (numbers[0] * 10) + numbers[1];
    currentMinutes -= minutes;
    if (currentMinutes < 0)
    {
        int hours = (-currentMinutes + 59) / 60;

        currentMinutes = 60 - (-currentMinutes % 60);
        numbers[3] = currentMinutes % 10;;
        numbers[2] = currentMinutes / 10;
        system("CLS");
                subtractionOfHours(hours,time);
    }
    numbers[3] = currentMinutes % 10;;
    numbers[2] = currentMinutes / 10;
    system("CLS");
    displayTime(numbers);
}



inline void linkedList::gotoxy(int x, int y)
{
    COORD pos = { x,y };

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);


}


void linkedList::makePattern(int number)
{	//swtich case for the making of linkedlist patterns
    for (int i = 0; i < 4; i++)
    {
        switch (number) {
        case 0:
            // Case 0
            digit_0_pattern();

            break;
        case 1:
            // Case 1
            digit_1_pattern();
            break;
        case 2:
            // Case 2
            digit_2_pattern();
            break;
        case 3:
            // Case 3
            digit_3_pattern();
            break;
        case 4:
            // Case 4
            digit_4_pattern();
            break;
        case 5:
            // Case 5
            digit_5_pattern();
            break;
        case 6:
            // Case 6
            digit_6_pattern();
            break;
        case 7:
            // Case 7
            digit_7_pattern();
            break;
        case 8:
            // Case 8
            digit_8_pattern();
            break;
        case 9:
            //case 9
            digit_9_pattern();
            break;

      



        }
    }
}