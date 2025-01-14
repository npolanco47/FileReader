#include <iostream>
#include <fstream> //for File I/O
#include <string>
    //d
using namespace std;

int main()
{
  string fileName; //to get the name of the file to open
  string line; //to store a single line of a text file
  fstream fileStream; //to open a file for reading
  int counter = 0;
  int number_characters = 0;
  char answer = ' ';
  do{
  cout<<"What file do you want to open? ";
  getline(cin, fileName);
 
  fileStream.open(fileName.c_str(),ios::in);//STEP 1: open the fileStream for input, using the fileName specified
  if(fileStream.is_open() /*STEP 2: check to see if the fileStream huccessfully opened*/ )
  {
    cout<<fileName<<" opened.\nFILE CONTENTS:\n";
  
   
   while(!fileStream.eof())
   {
   getline(fileStream, line);
   line.length();

    if(!line.empty())
    {
     cout << line << endl;
      counter = counter +1 ;
      number_characters=line.length() + number_characters;
    }   
   
    
  }
    fileStream.close();
   }
   else
   {
     cout << fileName << " could not be opened.\n";
   }

    cout<<"METADATA\n";
     cout <<"File: "<< fileName<< endl;
     cout <<"Lines: " << counter<< endl;
     cout <<"Characters: " << number_characters<< endl;
counter =0;
number_characters=0;

    //STEP 3: repeat the following until the end-of-file (eof) has been reached...
    // 3A: read a line from fileStream into the variable line
    // 3B: display the line, followed by an endline
  
   //STEP 4: close the fileStream
  cout << "Analyze another file (y/n)? ";
  cin >> answer;
  cin.ignore();
} while (answer == 'y'|| answer == 'Y');

  return 0;
}
