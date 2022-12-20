// Complete all functions with their comments
// NEVER delete my comments!!
// ====================================================
//Your name: Gerald Cordero 
//Complier:  g++
//File type: slist.cpp implementation file
//=====================================================

#include<iostream>
#include"slist.h" 

using namespace std;


// ** Make sure llist constructor and destructors have couts in them


// do not change this one
slist::slist() {
//cout << "slist constructor:" << endl;
  
}


el_t slist::search2(el_t X)  {

  el_t M = el_t(X);
  el_t B;
  Node *ptr = this->Front; // ptr pointed to head
  Node *temp = this->Front;
  int pos = 1; //  assigned to one 
  // searches the list and finds the pos 
  if (isEmpty()) { // checks if list is empty
    //cout << "0" << endl; // return 0 blank element
    return B; // return blank
  }
  while (ptr != NULL) { // till ptr does not equal NULL 
    if (ptr->Elem == X) { //if key euqals node elem 
    return ptr->Elem; //  return the found element 
    } 
    pos++; // update pos
    ptr = ptr->Next; // go to next node 
  }    
  // error case not in the list
  if (pos < 0) { // if pos is less than 0 
    //cout << "0" << endl; // not found return 0 blank element
    return B; // return blank
  }
  
  
}

// positions always start at 1
// need to find the pos at the element index 
int slist::search(el_t key)  {

  Node *ptr = this->Front; // ptr pointed to head
  Node *temp = this->Front;
  int pos = 1; //  assigned to one 
  // searches the list and finds the pos 
  if (isEmpty()) { // checks if list is empty
    return 0; // return 0
  }
  while (ptr != NULL) { // till ptr does not equal NULL 
    if (key == ptr->Elem) { //if key euqals node elem 
      return pos; //  return that position
    } 
    pos++; // update pos
    ptr = ptr->Next; // go to next node 
  }    
  // error case not in the list
  if (pos < 0) { // if pos is less than key or less than 0 return 0 
    return 0; // return error
  }

}
 

// don't forget to throw OutOfRange for bad pos 
// You must use moveTo to go to the pos
// will go to the Ith node and replace the elememnt with a new one 
void slist::replace(el_t element, int pos){
  
  Node *ptr; // node for argument moveTo
  // parameter (Jth,Node)
  if(pos == 0 || pos > this->Count) { // if pos == 0 and pos is greater than the count of the list then throw outofRange exception
    throw OutOfRange{}; // throw exception
  } else if (pos == 1) { // this case checks if we replace at the head 
    deleteFront(element); // call delete front 
    addFront(element); // than add front to replace the old elem
  } else {
  int i = pos-1; //  int i is pos -1 
  moveTo(i,ptr); // traverses to the previous node before the Jth node
  ptr = ptr->Next; // ptr goes to ptr next
  ptr->Elem = element; // ptr data assigned to the new elem to be replaced
 } // end if if else 
  
}

bool slist::operator==(const slist& OtherOne) {
  
  //slist First; 
  Node *first = this->Front; //  assigned to front
  Node *second = OtherOne.Front; // assigned to front

   if (isEmpty() && second == NULL) { //  if the list is empty return true
    return true;
  } 

  if (this->Count == OtherOne.Count) { //  if the count is the 
    while(first->Next != NULL && second->Next !=NULL) {
      if (first->Elem != second->Elem) {
        return false;
      }
      first = first->Next;
      second = second->Next;
    }
    if (first->Next == NULL && second->Next == NULL) {
      return true;
    }
  } else {
    if (this->Count != OtherOne.Count) {
      return false;
    }
  }
  
  
  
  
 
  
  
  
}
