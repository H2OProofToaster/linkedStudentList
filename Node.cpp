#include "Node.h"

// Constructor: sets the student pointer and initializes next to nullptr
Node::Node(Student* s) {
    student = s;
    next = nullptr;
}

// Destructor: deletes the student pointer to prevent memory leaks
Node::~Node() {
    delete student;
}

// Returns the next Node pointer
Node* Node::getNext() {
    return next;
}

// Returns the Student pointer
Student* Node::getStudent() {
    return student;
}

// Sets the next Node pointer
void Node::setNext(Node* n) {
    next = n;
}
