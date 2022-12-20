// CS311 Yoshii S22 - Hash Table - complete all ** parts.
// Note: this class does not know the parts of element except for key
// so that it would work even if each element in the hash table changed
//  NEVER delete my comments!!
//-----------------------------------------------------

// ============================================
// HW#: HW8 Hash Table
// Name: Gerald Cordero
// File Type: implementation htable.cpp
// =============================================
#include <iostream>
#include "htable.h"
using namespace std;


htable::htable()
{}

htable::~htable()
{}

// a simple hash function that uses % TSIZE simply
int htable::hash(int key)
{   

 return key % TSIZE; // mod the intger key by the table size

}

// adds the element to the table and returns slot#
// retrieve the key part of the element
int htable::add(el_t element )
{
  htable H;
  slist S;
  int slot = hash(element.getkey());  // hash with the key part of the element
  H.table[slot].addRear(element);
  // Note that this means adding the element to a slist in the slot (call addRear)
   
  // if someone gives you a element object just go to the slot # and add it to the table
}

// finds element using the skey and returns the found element itself
// or a blank element  -- there is no cout in here
el_t htable::find(int skey)
{ 
 int slot = hash(skey); // hash with skey given element
 el_t selement;  // this is the element to look for in slist
 selement.setkey(slot); // initialize selement with just the skey (call setkey)
 slist Slist;
 Slist.search2(selement);
 return selement; // return founf elemenet
 //** // call slist's search2 with selement which returns the found element 
 //** // return the found element from here (it could be blank)
}

// finds the element given the key  and deletes it from the table.
//  Returns the slot number.
int htable::deleteIt(int key)
{
  
 int slot = hash(key); // hash with skey
 el_t selement;  // this is the element to look for in slist
 selement.setkey(slot); //  initialize selement with just the skey
 slist Slist; //  call slist's search which gives you the location I and then deleteIth
 Slist.search(selement); // give you the location Ith 
 Slist.deleteIth(slot,selement); // parameter int a el_t
 return slot; // returns the slot number 
  //** //  return the slot number
  
}

// fills the table using the specified input file 
void htable::fillTable(istream& fin)
{ int akey;
  string Name, pet,food;
  el_t E;
  slist S;
  htable H;
  //  model this after HW6 to get data from the file the user specified
  //  which elem and slist functions do you call? List them here first.
  while (fin >> akey) {  // grabs the sreach key which would give you the slot
    //cout << "Key:" << E.key << endl;
    fin >> Name;
    //cout << "Name:" << E.name << endl;
    fin >> pet;
    //cout << "Pet:" << E.pet << endl;
    fin >> food;
    //cout << "Food:" << E.food << endl;
    E = el_t(akey,Name,pet,food); // call constructor
    (H.table[TSIZE]).addRear(E); // add object to table using slist function
    // fin other parts and create an element
    // YOu can call the add function to add the created element to the table
    //akey++;
  }   
 // S.displayAll();
   
    //fin other parts to create an element
}

// displays the entire table with slot#s too
void htable::displayTable()
{
  slist S;
  el_t E;
  htable H;
  for (int i = 0; i < 37; i++)
    { cout << i << ":";
      S.displayAll();
      //** // call slist's displayAll
    }
 
}

// saves into the specified file in the same format as the input file
void htable::saveTable(ostream& fout) 
{
  // for each non-empty slot of the table, retrieve the slist to a local variable
  // and fout each removed element.

   //fout << "newout.txt"; // prints to a file
  slist S;
  el_t E;
  htable H;
  
  
  for (int i = 0; i < 37; i++)
    { 
      if (S.isEmpty() ) {
      fout << E << endl;
      //S.displayAll();
      //** // call slist's displayAll
    }
  }
}
 

  

