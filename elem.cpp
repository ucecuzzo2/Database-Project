// Element type of a list node is defined here
// el_t can be changed by the client to fit its needs
// Edit ** parts
//----------------------------------------------------

#include "elemm.h"

// blank element
el_t::el_t()
{
  key = -1;  // cannot be 0 because 0 is a valid key
  // initialize other parts to be blanks
  name = ""; // name assigned to blank  
  course_name = ""; // food assigned to blank 
  course_number = 0; // pet assigned to 0
}

// initializing constructor to create an el_t object 
el_t::el_t(int akey, string user_name, string class_name,int num)
{
  key = akey;
  name = user_name;
  course_name = class_name;
  course_number = num;
  
  //  initialize other parts to be the arguments
}

// ONLY the key part should be available to the user of this class
int el_t::getkey()
{
  return key; // returns the key part 
}

// ONLY the key part should be available to the user of this class 
void el_t::setkey(int akey)
{
  key = akey;
}
  
// overload == for search based on the key part only
bool el_t::operator==(el_t OtherOne)
{
  if (this->key == OtherOne.key) return true; else return false;
}

bool el_t::operator!=(el_t OtherOne)
{
  if (this->key != OtherOne.key) return true; else return false;
}

// overload cout 
ostream& operator<<(ostream& os, const el_t& E)  
{  
  //os << E.key << " " << ** // display other parts of E in a nice way
  os << E.key << " " << E.name << " " << E.course_name << " " << E.course_number << endl;
  return os;  // returns outputstrem back to the client
}  




