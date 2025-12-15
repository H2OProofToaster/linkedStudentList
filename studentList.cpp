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
void deleteStudent(Node* &head);

//Loops to run commands
int main()
{
  //vector<student*> studentList; //Vector of pointers to students structs
  Node* head = nullptr;
  bool quit = false; //Flip to quit
  char actions[4][7] = {"ADD", "DELETE", "PRINT", "QUIT"}; //Allowed actions to do

  //DEBUG
  //int iterations = 0;
  
  //Loops and asks for actions each time
  while(!quit)
    {
      //Quit
      if(quit) {return 0;}
  
      //Get action
      cout << "What is your action? (ADD, DELETE, PRINT, or QUIT)" << &endl;
      char action[7];
      cin.get(action, 7);

      //Print which action
      //cout << "Debug; action: " << action << &endl;

      if(strcmp(action, actions[0]) == 0) {/*cout << "ran add" << &endl; */add(studentList);} //Add  
      else if(strcmp(action, actions[1]) == 0) {/*cout << "ran delete" << &endl; */deleteStudent(studentList);} //Delete
      else if(strcmp(action, actions[2]) == 0) {/*cout << "ran print" << &endl; */printStudents(studentList);} //Print
      else if(strcmp(action, actions[3]) == 0) {/*cout << "ran quit" << &endl; */quit = !quit;} //Quit
      else {cout << "no action" << &endl;}
      
      //Reset action
      for(int i = 0; i++; i < strlen(action))
	{
	  action[i] = '\0';
	}
      
      //iterations++;
    }
}

//Does not sort by GPA yet
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
  if(head == nullptr)
    { head = new Node(s); }

  //Go to next node
  else
    { insert(head->getNext(), s); }
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
