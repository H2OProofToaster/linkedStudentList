#ifndef STUDENT_H
#define STUDENT_H

class Student {
 public:
  //Con- and de-structors
  Student(char* f, char* l, int i, float g);
  ~Student();

  //Get- and set-ters
  char* getFirstName();
  void setFirstName(char* n);

  char* getLastName();
  void setLastName(char* n);

  int getID();
  void setID(int i);

  float getGPA();
  void setGPA(float g);

 private:
  char firstName[30];
  char lastName[30];
  int studentID;
  float GPA;
};

#endif
