// Note that the client knows about elem.h functions.
// It can create el_t objects.
// Note that el_t X; will create a blank element X using the regular constructor.  
// Note that the second constructor of el_t can be used to
// create key+other info to add to the table. e.g. el_t X(30, "mary"...);
//-----------------------------------------------

//============================================
// Name: Gerald Cordero
// File type: client hw8client.cpp (tester)
//===========================================
#include "htablee.h"
#include "elemm.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{ 
  //** // cout an explanation of what this App should be used for. 


cout << "This app is used for college students to input classes into a school database for the computer science department. This allows users to store there full name, course number, and class name."<< endl;


  htable HT;
  string fname; // file name - decided to get the file name here
            // in the client in case the way I get them is application dependent

  cout << "\n\nWhat is the input file? (.txt file)";
  cin >> fname;
  
  ifstream fin (fname.c_str(), ios::in);
  HT.fillTable(fin);
  // make sure some of elements collide. 
  HT.displayTable();
  cout << endl;

  // this is the output file - newout.txt
  ofstream fout ("newout.txt", ios::out);  

  int selection;
  do {

  cout << "MENU: ---- " << endl; 
  cout << "1 Add an element" << endl; 
  cout << "2 Find an element" << endl;
  cout << "3 Delete an element" << endl;
  cout << "4 Display the table" << endl;
  cout << "5 Save the table to a file" << endl;    
  cout << "6 Quit" << endl;
  cin >> selection;

      int thekey; // customer key
      string thename; // user name  
      string theNum; // customer pet
      int theCourseName; // customer food  
      el_t theelement; // el_t object 
      int s;

    

    switch (selection) {

    case 1:  // Add and indicate slot
      cout << "What is the key to add? ";
      cin >> thekey;
      cout << "What is the client name? ";
      cin >> thename;
      cout << "What class do you want to input? ";
      cin >> theNum;
      cout << "What is the class number? ";
      cin >> theCourseName;
      //** //  Here get two more pieces of info
      //  Create the element with all the info using the 2nd constructor
	    theelement = el_t(thekey,thename,theNum,theCourseName); // call el_t second constcutor  
      s = HT.add(theelement);
      cout << "Added the element in slot " << s << endl;
      break;

    case 2: // Find and indicate element
      cout << "What is the key to find? ";
      cin >> thekey;
      theelement =  HT.find(thekey); // find based on thekey
      cout << "Found this:" << endl;
      cout << theelement << endl;
      break;      

    case 3: // Delete and indicate slot
      cout << "What is the key to find? ";
      cin >> thekey;
      s  =  HT.deleteIt(thekey); // find and delete it based on thekey
      if (s == -1) cout << "Not found!" << endl; else
      cout << "Found it and deleted it from slot:" << s << endl;
      break;      

    case 4: // Display
      cout << "The current contents are: " << endl;
      HT.displayTable();
      break;

    case 5: // Save in the same format as input file
      HT.saveTable(fout);
      cout << "Saved the updated table in newout.txt" << endl;
      break;

    default:
      cout << "bye" << endl;
    }
  }
  while (selection != 6);
  fin.close();
  fout.close();
 }


