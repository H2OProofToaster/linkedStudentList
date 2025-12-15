#ifndef NODE_H
#define NODE_H

#include "Student.h"

// Node class holds a Student pointer and a link to the next Node in the list
class Node {
private:
    Student* student; // pointer to Student
    Node* next;       // pointer to next Node

public:
    // Constructor takes a Student pointer
    Node(Student* s);

    // Destructor
    ~Node();

    // Returns pointer to the next Node
    Node* getNext();

    // Returns pointer to the Student
    Student* getStudent();

    // Sets the next Node pointer
    void setNext(Node* n);
};

#endif
