//CS311 Yoshii S22 llist.h
//INSTRUCTION:
//Llist class - header file template 
//You must complete the ** parts and then complete llist.cpp
//Don't forget PURPOSE and PARAMETERS 

// =======================================================
// HW#: HW3P1 llist
// Your name: Gerald Cordero
// Compiler:  g++ 
// File type: headher file  llist.h
//=======================================================

// alias el_t : element type definition
//char el_t;  //is now a class
#include "elemm.h"

//a list node is defined here as a struct Node for now
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist : public el_t // we need to include el_t
{
  
 protected:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes

  // untility function to move to a specified node position
  void moveTo(int, Node*&);
  
 public:

  // Exception handling classes 
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  // return true if front and rear are both pointing to null and count is 0
  bool isEmpty();
    
  //display each element of the list starting from Front, enclosed in  [ ] followed by endl.
  void displayAll();

  //add to the front of the list check for special and reg case 
  void addFront(el_t);
    
  // add a node to the rear 
  void addRear(el_t);

  //delete the front node must check for special, reg, and empty case 
  void deleteFront(el_t&);
  
  //---------------------------------------
    
  //delete the node from the rear of the list 
  void deleteRear(el_t&);
    
  //delete a node at the ith node
  void deleteIth(int, el_t&);  // calls moveTo

  //insert a node at the ith node     
  void insertIth(int, el_t);   // calls moveTo

  //Copy Constructor to allow pass by value and return by value of a llist
  llist(const llist&);
  
  //Overloading of = (returns a reference to a llist)
  llist& operator=(const llist&); 

};
