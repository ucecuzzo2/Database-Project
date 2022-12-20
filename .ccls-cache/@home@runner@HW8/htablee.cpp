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
#include "htablee.h"
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
  
  int slot = hash(element.getkey());  // hash with the key part of the element
  table[slot].addRear(element);
  return slot;
  // Note that this means adding the element to a slist in the slot (call addRear)
   
  // if someone gives you a element object just go to the slot # and add it to the table
}

// finds element using the skey and returns the found element itself
// or a blank element  -- there is no cout in here
el_t htable::find(int skey)
{ 
 int slot = hash(skey); // hash with skey given element
 el_t selement;  // this is the element to look for in slist
 selement.setkey(skey); // initialize selement with just the skey (call setkey)
 el_t S;
 S = table[slot].search2(selement);
  //** // call slist's search2 with selement which returns the found element 
 return S; // return found elemenet
 
 //** // return the found element from here (it could be blank)
}

// finds the element given the key  and deletes it from the table.
//  Returns the slot number.
int htable::deleteIt(int key)
{

 int Search;
 int slot = hash(key); // hash with skey
 el_t selement;  // this is the element to look for in slist
 selement.setkey(key); //  initialize selement with just the skey
 Search = table[slot].search(selement); // search
 if (Search != -1) { // if valid
   table[slot].deleteIth(Search,selement); // delete it
 } 
 return slot; // returns the slot number 
  //** //  return the slot number
}

// fills the table using the specified input file 
void htable::fillTable(istream& fin)
{ 
  int akey;
  string Name,Course_name;
  int Course_num;
  //  model this after HW6 to get data from the file the user specified
  //  which elem and slist functions do you call? List them here first.
  while (fin >> akey) {  // grabs the sreach key which would give you the slot
    //cout << "Key:" << E.key << endl;
    fin >> Name;
    //cout << "Name:" << E.name << endl;
    fin >> Course_name;
    //cout << "Pet:" << E.pet << endl;
    fin >> Course_num;
    //cout << "Food:" << E.food << endl;
    el_t All_elem(akey,Name,Course_name,Course_num); // call constructor
    add(All_elem);// add object to table using slist function
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

  for (int i = 0; i < 37; i++)
    { cout << i << ":";
      table[i].displayAll();
      //** // call slist's displayAll
    }
}

// saves into the specified file in the same format as the input file
void htable::saveTable(ostream& fout) 
{
  // for each non-empty slot of the table, retrieve the slist to a local variable
  // and fout each removed element.
  //fout << "newout.txt"; // prints to a file
  el_t E;
  for (int i = 0; i < 37; i++) // iterate through slots 
    { 
      if (!table[i].isEmpty()) {
        while(!table[i].isEmpty()) {
          table[i].deleteFront(E); // call deleteFront
          fout << E << endl; // fout to file
        }
    }
  }
}
 

  

