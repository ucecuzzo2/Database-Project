
// Put only the following in class slist.h 
//    inheriting everything from llist.h
//
// Then create slist.cpp with only the following functions
// Complete all ** parts 
//=================================================
// Name: Gerald Cordero 
// File: slist.h file
//=================================================

//**  // for includes

#include "llist.h"


//llist class is the base class and the slist is the class that will be derived  
// all the public members will now be utlize in slist 

class slist : public llist //**
{

 public:
 
  slist();   // constructor. cout "in slist constructor".
             // Make it do nothing else.
             // Experiment and see what happens.
             // Taking this out completely would not work.
             // But note that there is no destructor.
             // PLEASE DO NOT delete the couts in slist and llist
             // constructors and destructors for HW6!!!!!

  int search(el_t);
    // search through the list to see if any node contains the key.
    // If so, return its position (>=1). Otherwise, return 0.


  // New function for Htable
  el_t search2(el_t);
  //copy search as search2 and then change it to return the found element itself instead of the position (an blank element is returned if not found)
  //No other changes should be necessary to use an element object.

    
    void replace(el_t,  int);
    // go to the Ith node (if I is between 1 and Count) and 
    // replace the element there with the new element. 
    // If I was an illegal value, throw OutOfRange 
    
    bool operator==(const slist&);
    // checks to see of the two lists look the same
    

};

