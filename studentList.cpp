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

//Default parameter functions
Node* deleteStudent(Node* head, int ID = -1)
{
  //Get ID first time
  if(ID == -1)
    {
      int ID = 0;
      cout << "What is the ID of the student to delete?" << endl;
      cin >> ID;
      cin.ignore();
    }

  //Catch end of list
  if(head == nullptr) { return nullptr; }

  //Current node matches ID
  if(head->getStudent()->getID() == ID) { return head->getNext(); } //Return node to delete's next node

  //Go to next
  Node* newNext = deleteStudent(head, ID);

  //Catch match
  if(newNext != nullptr)
    {
      head->~Node(); //Delete match
      head->setNext(newNext); //Fix next
    }
}

float averageGPA(Node* head, float avg = 0.0f)
{
  avg += head->getStudent()->getGPA();
  avg = avg / 2;

  if(head->getNext() == nullptr) { return avg; }
  else { averageGPA(head->getNext(), avg); }
}

//Loops to run commands
int main()
{
  //vector<student*> studentList; //Vector of pointers to students structs
  Node* head = nullptr;
  bool quit = false; //Flip to quit
  char actions[5][8] = {"ADD", "DELETE", "PRINT", "QUIT", "AVERAGE"}; //Allowed actions to do

  //DEBUG
  //int iterations = 0;
  
  //Loops and asks for actions each time
  while(!quit)
    {
      //Quit
      if(quit) {return 0;}
  
      //Get action
      cout << "What is your action? (ADD, DELETE, PRINT, AVERAGE, or QUIT)" << &endl;
      char action[8];
      cin.get(action, 8);

      //Print which action
      //cout << "Debug; action: " << action << &endl;

      if(strcmp(action, actions[0]) == 0) { add(head); } //Add  
      else if(strcmp(action, actions[1]) == 0) { deleteStudent(head); } //Delete
      else if(strcmp(action, actions[2]) == 0) { cout << "Students" << endl; printStudents(head); cin.ignore(); } //Print
      else if(strcmp(action, actions[4]) == 0) { cout << fixed << setprecision(2) << averageGPA(head); cin.ignore(); } //Average
      else if(strcmp(action, actions[3]) == 0) { quit = !quit; } //Quit
      else { cout << "no action" << &endl; }
      
      //Reset action
      for(int i = 0; i++; i < strlen(action))
	{
	  action[i] = '\0';
	}
      
      //iterations++;
    }
}

//Does not sort by ID yet
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

  //Add to end of linked list
  insert(head, newS);
}

void insert(Node* &head, Student* s)
{
  //End of list
  if(head == nullptr) { head = new Node(s); }

  //Go to next node
  else { Node* temp = head->getNext(); insert(temp, s); }
}

void printStudents(Node* head)
{
  cout << "DEBUG: print call";
  if(head == nullptr) { return; }
  
  cout << fixed << setprecision(2);
  cout << head->getStudent()->getFirstName() << " " << head->getStudent()->getLastName() << ", " << head->getStudent()->getID() << ", " << head->getStudent()->getGPA() << endl;

  printStudents(head->getNext());
}     
  
/*
void add(vector<student*> &vect)
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

  //Make struct
  student* newStudent = new student;
  strcpy((*newStudent).firstName, firstName);
  strcpy((*newStudent).lastName, lastName);
  (*newStudent).studentID = studentID;
  (*newStudent).GPA = GPA;

  //Add struct to vector
  vect.push_back(newStudent);
}

void printStudents(vector<student*> vect)
{
  cout << "Students" << &endl;
  for(int i = 0; i < vect.size(); i++)
    {
      cout << fixed << setprecision(2);
      cout << (*vect[i]).firstName << " " << (*vect[i]).lastName << ", " << (*vect[i]).studentID << ", " << (*vect[i]).GPA << &endl;
    }
  cin.ignore();
}
  
void deleteStudent(vector<student*> &vect)
{
  int ID = 0;
  cout << "What is the ID of the student to delete?" << &endl;
  cin >> ID;
  cin.ignore();
  
  for(int i = 0; i < vect.size(); i++)
    {
      if((*vect[i]).studentID == ID)
	{
	  delete vect[i];
	  vect.erase(vect.begin() + i);
	  return;
	}
    }
}
*/
