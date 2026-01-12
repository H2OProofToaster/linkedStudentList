#include "student.h"
#include <cstring>

Student::Student(char* f, char* l, int i, float g)
{
  setFirstName(f);
  setLastName(l);
  setID(i);
  setGPA(g);
}

Student::~Student() {}

char* Student::getFirstName() { return firstName; }
void Student::setFirstName(char* n) { strcpy(firstName, n); }

char* Student::getLastName() { return lastName; }
void Student::setLastName(char* n) { strcpy(lastName, n); }

int Student::getID() { return studentID; }
void Student::setID(int i) { studentID = i; }

float Student::getGPA() { return GPA; }
void Student::setGPA(float g) { GPA = g; }
