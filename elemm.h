// Element type of a list node is defined here
// el_t can be changed by the client to fit its needs
// I use IFNDEF in case this file gets included more than once
// ---------------------------------------------------------

#ifndef A
#define A

#include <iostream>
#include <string>
using namespace std;

class el_t
{
 public:  // these will change depending
           // on the client needs
  int key;      // key
  string name;  // customer name
  //** add 2 more pieces of info here
  string course_name; // class name
  int course_number; // class number

 public:

  el_t();  // to create a blank el_t object
  el_t(int, string, string, int); // to create an initialized el_t object - useful for the client   ** add more arguments to create the object

 // The following functions are available to
 // the htable class to be able to
 // use different el_t without modifying the code

  int getkey(); // only the key part can be accessed by the user of this class.

  void setkey(int); // only the key part can be accessed by the user of this class.


  // In linked list search,
  //    == is used to compare node elements
  // but what does it mean for this client to compare
  // node elements?  
  bool operator==(el_t);  // overload == for search
  bool operator!=(el_t);  // overload != for search

  // This overloads cout for the el_t object
  // This is a friend function since the receiver object is not el_t
  friend ostream& operator<<(ostream&, const el_t&);


};

#endif
