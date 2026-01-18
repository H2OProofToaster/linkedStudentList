#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>
#include <limits>
#include "Node.h"
#include "student.h"

using namespace std;

//Student struct
/*struct student
{
   char firstName[30];
   char lastName[30];
   int studentID;
   float GPA;
};*/

//Prototypes
void add(Node* &head); //Prompts user for student info and adds to head
void insert(Node* &head, Student* s); //Takes created student pointer and adds to head
void printStudents(Node* head);
void deleteStudent(Node* &head, int ID = -1);
float averageGPA(Node* head, float avg = 0.0f);
void deleteAll(Node* &head);

//Loops to run commands
int main()
{
  Node* head = nullptr;
  bool quit = false; //Flip to quit
  char actions[5][8] = {"ADD", "DELETE", "PRINT", "QUIT", "AVERAGE"}; //Allowed actions to do
  
  //Loops and asks for actions each time
  while(!quit)
  {
    //Quit
    if(quit) {return 0;}

    //Get action
    cout << "What is your action? (ADD, DELETE, PRINT, AVERAGE, or QUIT)" << &endl;
    char action[8];
    cin.get(action, 8);

    if(strcmp(action, actions[0]) == 0)
	  {
	    add(head);
	  }
    else if(strcmp(action, actions[1]) == 0)
	  {
	    deleteStudent(head);
	  }
    else if(strcmp(action, actions[2]) == 0)
	  {
	    cout << "Students" << endl;
	    printStudents(head);
	    cin.ignore();
	  }
    else if(strcmp(action, actions[4]) == 0)
	  {
	    float out = averageGPA(head);
	    if(out == -1.0f) { cout << "WHY ARE YOU AVERAGING AN EMPTY LIST" << endl; }
	    else { cout << fixed << setprecision(2) << out << endl; }
	    cin.ignore();
	  }
    else if(strcmp(action, actions[3]) == 0)
	  {
        deleteAll(head);
	    quit = !quit;
	  }
    else
	  {
	    cout << "no action" << &endl;
	  }

    //Reset action
    for(int i = 0; i++; i < strlen(action))
    {
      action[i] = '\0';
    }
  }
}

void add(Node* &head)
{
  //Get input
  char firstName[30];
  cout << "What is the first name of the student to add?" << &endl;
  cin.ignore();
  cin.get(firstName, 31);

  char lastName[30];
  cout << "What is the last name of the student to add?" << &endl;
  cin.ignore();
  cin.get(lastName, 31);

  int studentID = 0;
  cout << "What is the ID of the student to add?" << &endl;
  cin >> studentID;
  cin.ignore();

  float GPA = 0.0;
  cout << "What is the GPA of the student to add?" << &endl;
  cin >> GPA;
  cin.ignore();

  //Make new student
  Student* newS = new Student(firstName, lastName, studentID, GPA);

  insert(head, newS);
}

void insert(Node* &head, Student* s)
{
  if(head == nullptr) //End of list
  {
    head = new Node(s);
  }
  else if(s->getID() < head->getStudent()->getID()) //Smaller than head
  {
    Node* temp = head;
    head = new Node(s);
    head->setNext(temp);
  }
  else if(head->getNext() == nullptr) //Bigger than last in list
{
  head->setNext(new Node(s));
}
  else if(s->getID() < head->getNext()->getStudent()->getID()) //Smaller than the next one
    {
      Node* temp = new Node(s);
      temp->setNext(head->getNext());
      head->setNext(temp);
    }
  else //Iterate
    {
      Node* temp = head->getNext();
      insert(temp, s);
    }
}

void printStudents(Node* head)
{
  if(head == nullptr) { return; }
  
  cout << fixed << setprecision(2);
  cout << head->getStudent()->getFirstName() << " " << head->getStudent()->getLastName() << ", " << head->getStudent()->getID() << ", " << head->getStudent()->getGPA() << " at " << head << " pointing to " << head->getNext() << endl;

  printStudents(head->getNext());
}     

void deleteStudent(Node* &head, int ID)
{
  //Get ID first time
  if(ID == -1)
    {
      int newID = 0;
      cout << "What is the ID of the student to delete?" << endl;
      cin >> newID;
      cin.ignore();
      ID = newID;
    }

  //One element list
  if (head->getStudent()->getID() == ID && head->getNext() == nullptr) {
      delete head;
      head = nullptr;
      return;
  }

  //First element match
  if (head->getStudent()->getID() == ID) {
      Node* temp = head;
      head = head->getNext();
      delete temp;
      return;
  }

  //End of list
  if (head->getNext()->getStudent()->getID() == ID && head->getNext()->getNext() == nullptr) {
      delete head->getNext();
      head->setNext(nullptr);
      return;
  }

  //Next match
  if (head->getNext()->getStudent()->getID() == ID) {
      Node* temp = head->getNext()->getNext();
      delete head->getNext();
      head->setNext(temp);
      return;
  }

  Node* temp = head->getNext();
  deleteStudent(temp, ID);
}

float averageGPA(Node* head, float avg)
{
  if(head == nullptr) { return -1.0f; }
  
  avg += head->getStudent()->getGPA();
  if(avg != head->getStudent()->getGPA()) { avg = avg / 2; }

  if(head->getNext() == nullptr) { return avg; }
  return averageGPA(head->getNext(), avg);
}

void deleteAll(Node* &head) {
    if (head == nullptr) { return; }
    if (head->getNext() == nullptr) {
        delete head;
        return;
    }
    deleteAll(head);
    delete head;
}