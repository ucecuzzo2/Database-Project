//INSTRUCTION:
//It helps to first create if-then-else structure to fill in later.
//- Make sure PURPOSE and PARAMETER comments are given in detail
//  You can copy from a Word document to emacs (contrl-right click)
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes
//  NEVER delete my comments!!!!
//EMACS HINT:
//  cntr-K cuts and cntr-Y pastes. 
//  Esc x replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++

// ====================================================
//Your name: Gerald Cordero
//Complier:  g++
//File type: llist.cpp implementation file
//=====================================================
#include<iostream>
#include"llist.h" 
using namespace std;

//private uses : pointers Front,Rear,and Count 
// el_t int is data type integer used in parameters 

llist::llist() { //constructor 
  //cout << "... in llist constructor..." << endl; //cout for HW3P2 removed for hw7 
  this->Front = this->Rear = NULL; // set f and r to NUll
  this->Count = 0; // count set to 0
}

// correct the destructor 
llist::~llist(){
  
  //cout << ".... in llist destructor..." << endl;  removed for hw7
  
  Node* P = this->Front; //pointer p is pointing to the front node
  while(!isEmpty()) { // while p is not empty call deleteFront to delete all nodes
    P = P->Next;
    deleteFront(P->Elem); //this would repeatadly delete all nodes
  }
  
}

//PURPOSE: return true if front and rear are both pointing to null and count is 0.
//PARAMETER: takes no parameter 
bool llist::isEmpty() { 

  if (this->Front == NULL && this->Rear == NULL && this->Count == 0 ) {
    return true; 
  } else {
    return false;
  }
  
  
} // be sure to check all 3 data members // end of function


//PURPOSE: display each element of the list starting from Front, enclosed in  [ ] followed by endl.
// exmaple is [1 2 3] with blanks in between. 
// special case : if the list is empty, display [ empty ]. 
//PARAMETER: takes no parameter
void llist::displayAll() {   // be sure to display horizontally in [  ] with
// blanks between elements e.g. [ 1 2 3 4]
// You MUST use while (P != NULL) loop or you will not get the credit!
  
  Node *P = this->Front; // new node name ptr is now the front 
  if (isEmpty()) { // the node p is empty call empty function 
    cout << "[empty]" << endl; // print special case
    return;
  } // else display 
  cout << "[";
  while(P != NULL) {
   cout <<  P->Elem << " ";
   P = P->Next; // update the next
  } // end of while
  cout << "]";
  cout << endl;
 } // end of function 
  


//PURPOSE: add a node to the rear 
//PARAMETER: int named NewNum
void llist::addRear(el_t NewNum) { 

  Node *node = new Node; // create a new node
  node->Elem = NewNum; // set elem to the new num
  node->Next = NULL; // set next to null 

  if (isEmpty()) { // if it is empty 
    this->Front = node; // set both front an rear to the node
    this->Rear = node;
    Count++; // count updated
    //return;
  } else {

  Node* temp = this->Front; // temp set to this->Front   @@ you do not need a loop to add to Rear
  while(temp->Next != NULL) { // if temp->next does not equal null keep traversing
    temp = temp->Next; // keeps traversing 
  }
  // breaks out the while 
 Rear->Next = node; // rear would pount to the new node
 Rear = Rear->Next;
 Rear->Elem = NewNum;
 Rear->Next = NULL; // points to NULL 
 Count++; //count updated

}
    
} // comment the 2 cases

//PURPOSE: add to the front of the list check for special and reg case 
//PARAMETER: NewNUm
void llist::addFront(el_t NewNum) { 

  
  if (isEmpty()) { //checks for first node then create a node 
    Node *node = new Node; // new node 
    node->Elem = NewNum; // node set to newnum 
    this->Front = node; // front is assigned to new node 
    this->Rear = node; // rear is pointed to new node 
    node->Next = NULL; // the new nodes next is assigned to NULL
    Count++;
  } else { //reg case
    
    Node *node1 = new Node; // creates a new node
    node1->Elem = NewNum; // assigns the new node a 
    node1->Next = this->Front; // new node is pointed to the front 
    this->Front = node1; // front is now assigned to the new node 
    Count++;
  }
  
  
} // comment the 2 cases


//PURPOSE: delete the front node must check for special, reg, and empty case 
//PARAMETER: Old num
void llist::deleteFront(el_t& OldNum) {
  // if it is empty throw an exception underflow
  Node* first = this->Front;
  //Node* second = this->Front->Next; //this gives use the location of second node 
  
  if (isEmpty()) {
    throw Underflow{}; // throw underflow   @@ this is not working for Case 18
  }
  if (this->Front == this->Rear) { // checks if there is only one node
    //OldNum = this->Front->Elem;
    delete first; // delete the head 
    this->Front = NULL; // set both front and rear to null 
    this->Rear = NULL;
    Count--; // update count 
  } else { // regular case 
    Node* second = this->Front->Next;
    OldNum = this->Front->Elem;
    Node *temp = this->Front;
    this->Front = this->Front->Next; // assign the node after the front node to become the new front node 
    delete temp; // then delete the head 
    Count--;
  }
  // case if it is not the star node
  
  }

//} // comment the 3 cases

// correct delete rear 
//PURPOSE:delete the node from the rear of the list 
//PARAMETER: OldNum
void llist::deleteRear(el_t& OldNum){
  if (isEmpty()) { // check if empty throw an exception 
    throw Underflow{};
  }
   if (this->Front == this->Rear) { // checks if there is only one node
    OldNum = this->Rear->Elem;
    Node *first = this->Front; // first assigned front 
    delete first;  // delete the front 
    this->Front = NULL; // set both rear and front to null 
    this->Rear = NULL; // assigned to rear 
    
    Count--;
  } else { // regular case
    OldNum = this->Rear->Elem;
    Node *ptr = this->Front;
     while (ptr->Next != this->Rear) {
       ptr = ptr->Next;
     }
     delete this->Rear;
     this->Rear = ptr;
     this->Rear->Next = NULL;
     Count--;
  }
} // comment the 3 cases



/* --- harder ones for case 2 and 3 follow -- */

// Utility Function to move a local pointer to the Jth node
void llist::moveTo(int J, Node*& temp) {
  
  // If you want to go to the Jth node, P has to move J-1 times.
  temp = this->Front;

  for (int K = 1; K <= J-1; K++) {  // for J-1 times
   temp = temp->Next;
 }

// now you are at the Jth node
// moves temp J-1 times to go to the Jth node  
// for ( int K = ... ) temp = temp->Next;
}

//PURPOSE: delete a node at the ith node 
//PARAMETER: Int I and elment type int OldNum 
void llist::deleteIth(int I, el_t& OldNum) {

  // error case
  if (I > Count || I < 1) {
    throw OutOfRange{};
    //Count--;
  }
  // special case 
  if (I == 1) { // if I = 1 delete front
    deleteFront(OldNum); // call delete front
  } else if (I == Count) {
    deleteRear(OldNum);
    
  } else {
    OldNum = this->Rear->Elem;
    Node *prev; 
    Node *jth;
    int i = I+1; // get to pos I + 1 
    moveTo(i,jth); // I+1 is the argument @@ just say I+1 as the argument
    //cout << "jth node : " << i << endl;
    int q = I-1; // get to pos I - 1 
    moveTo(q,prev);     //@@ just say I-1 as the argument
    //cout << "prev node: " << q << endl;
    delete prev->Next; // delete prev->next
    prev->Next = jth; // move prev->next to jth
    Count--;
  }
  
  
  
  
  } // must use moveTo to move local pointers. Be sure to comment to which node you are moving them. Do not forget to set OldNum.  


//PURPOSE: insert a node at the ith node 
//PARAMETER: int I and element type int newNum
void llist::insertIth(int I, el_t newNum) {

  // error case
  if (I > Count+1 || I < 1) {
    throw OutOfRange{};
  }
  // special case 
  if (I == 1) { // if (I = 1) add to the front of the list 
    addFront(newNum); // call addFront
  } else if (I == Count+1) { // If (I = Count+1) add to the rear of list
    addRear(newNum); // call addRear
  } else { 
    Node *jth; // jth node
    Node *prev ; //  prev node 
    Node *node = new Node ; //new node 
    node->Elem = newNum; // set to net num 
    node->Next = NULL; // set to null
    moveTo(I,jth);
    //cout << "jth node: " << I << endl;
    int i = I-1; // this would get us to the previous node
    moveTo(i,prev);  //I-1 is the argument //@@ just say I-1 as the argument
    //cout << "Previous node: " << i << endl;
    prev->Next = node; // prev node goes to new node 
    node->Next = jth; // new node points to jth node 
    Count++;
    
  }
    
}
  
  
 // must use moveTo to move local pointers. Be sure to comment to which node you are moving them.

//PURPOSE: Copy Constructor to allow pass by value and return by value of a llist
//PARAMETER: &Original
llist::llist(const llist& Original) { 
//  this->'s data members need to be initialized here first
 Front = NULL; Rear = NULL; Count = 0;
 el_t x;
 Node *ptr = Original.Front;
 while (ptr != NULL) {
  this->addRear(ptr->Elem);
  ptr = ptr->Next;
 }
//  this-> object has to be built up by allocating new cells
//  and copying the values from Original into each cell as we did with 
//  operator= above. To do this,
 //copy here the (**) lines in Operator Overloading of = but note that it is Original and not OtherOne.

    //  Nothing to return because this is a constructor.

} // use my code

//PURPOSE: Overloading of = (returns a reference to a llist)
//PARAMETER: &Other one
llist& llist::operator=(const llist& OtherOne) {
 el_t x;
  // First make sure this-> and OtherOne are not the same object.
 // To do this, compare the pointers to the objects .
  if (&OtherOne != this)  // if not the same
   {
  // this-> object has to be emptied first.
    while (! this->isEmpty() )
     this->deleteRear(x);  
     // this-> object has to be built up by allocating new cells with OtherOne elements (**)
      Node* P;  // local pointer for OtherOne
      P = OtherOne.Front;
        while (P != NULL)  // a loop which repeats until you reach the end of OtherOne. 
        {
           this->addRear(P->Elem);    //P’s element is added to this->
           P = P->Next;                         // Go to the next node in OtherOne   
         } 
      }// end of if              
     return *this;    // return the result unconditionally.  Note that the result is returned by reference.
  
  
  
  
} // use my code