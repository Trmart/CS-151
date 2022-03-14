//grades.cpp
//Write a C++ program that will sort the table by
// the last name and by SSN using a dummy csv data. 
//The user interacts with the program 
// Name(s): Taylor Martin
// Date:1/31/20
#include "grades.h"
#include <string> 
#include <iostream>
#include <fstream>
#include <iomanip> 

/*************************************
*           displayMenu              *
*     This function displays a menu  *
*                                    *
**************************************/
void displayMenu()
{

    cout <<  "**************************************\n"
             "*             Taylor Martin          *\n"
             "*    CS-151 PA2: Data Indexing Menu  *\n"
             "*                                    *\n"
             "**************************************\n";
    cout << "1.) Print data in ascending order by last name\n"; 
    cout << "2.) Print data in ascending order by first name \n"; 
    cout << "3.) Print data in ascending order by SSN \n"; 
    cout << "4.) Search by last name\n"; 
    cout << "5.) Search by SSN\n" ;
    cout << "6.) Exit\n";

}

/*************************************
*           Getchoice                *
* This function gets user input      *
*                                    *
**************************************/
int getChoice()
{
    int choice;
    cout << "Enter number to continue, or 6 to exit:  ";
    cin >> choice;
    while ((choice < 1 || choice > 5) && (choice !=6))
    {
        cout << "The only valid choices are 1-5, or enter 6 to exit the program."<<endl;
        cout << "Enter number to continue, or 6 to exit:  ";
        cin >> choice;
    }

    return choice;
}

/*************************************
*           readCsvToArray           *
*    This function copies csv data   *
*             to an array            *
**************************************/
void readCsvToArray(Student array[], int size, ifstream& file)
{
    string dummyString; 
    getline(file, dummyString);
    int index = 0; 
    char delim = ','; 
    while (!file.eof() && index < size)
    {
        
        file >> array[index].id >> delim; 
        getline(file, array[index].lastName, delim); 
        getline(file, array[index].firstName, delim); 
        getline(file, array[index].ssn, delim); 
        file >> array[index].test[0] >> delim; 
        file >> array[index].test[1] >> delim; 
        file >> array[index].test[2] >> delim; 
        file >> array[index].test[3] >> delim; 
        file >> array[index].final >> delim; 
        getline(file, array[index].letterGrade); 
        
        index++; 
    }

}

/*************************************
*           SortBySSN                *
* This function uses Bubble Sort     *
* to sort an array of pointers       *
*       in ascending order           *
*           based on SSN             *
**************************************/
void SortBySSN(Student *array[], int size)
{ bool madeAswap = true;
  int lastIndex = size-1; // Set lastIndex to size of array - 1
  Student *temp; 
  
  while (madeAswap)
   {
      madeAswap=false;//Set madeAswap flag to false
      for (int count = 0; count < lastIndex; count ++)//     For count = 0 to lastIndex
        {
          if (array[count]->ssn > array[count+1]->ssn) //If array[count] is greater than array[count + 1]
             {  temp = array[count];//Swap the contents of array[count] and array[count + 1]
                array[count]=array[count+1];
                array [count+1] = temp;
                madeAswap=true;//             Set madeAswap flag to true
             }//         End If

        }//     End For
     --lastIndex; //     Subtract 1 from lastIndex
    }// End While
}

// /*************************************
// *           SortByLastName           *
// * This function uses Bubble Sort     *
// * to sort an array of pointers based *
// *            on LastName             *
// *         in ascending order         *
// **************************************/
void SortByLastName(Student *array[], int size)
{ bool madeAswap = true;
  int lastIndex = size-1; // Set lastIndex to size of array - 1
  Student *temp; 
  while (madeAswap)
   {
      madeAswap=false;//Set madeAswap flag to false
      for (int count = 0; count < lastIndex; count ++)//     For count = 0 to lastIndex
        {
          if (array[count]->lastName > array[count+1]->lastName) //If array[count] is greater than array[count + 1]
             {  temp = array[count];//Swap the contents of array[count] and array[count + 1]
                array[count]=array[count+1];
                array [count+1] = temp;
                madeAswap=true;//             Set madeAswap flag to true
             }//         End If

        }//     End For
     --lastIndex; //     Subtract 1 from lastIndex
    }// End While
}

// /*************************************
// *           SortByFirstName          *
// * This function uses Bubble Sort     *
// * to sort an array of pointers based *
// *            on LastName             *
// *         in ascending order         *
// **************************************/
void SortByFirstName(Student *array[], int size)
{ bool madeAswap = true;
  int lastIndex = size-1; // Set lastIndex to size of array - 1
  Student *temp; 
  while (madeAswap)
   {
      madeAswap=false;//Set madeAswap flag to false
      for (int count = 0; count < lastIndex; count ++)//     For count = 0 to lastIndex
        {
          if (array[count]->firstName > array[count+1]->firstName) //If array[count] is greater than array[count + 1]
             {  temp = array[count];//Swap the contents of array[count] and array[count + 1]
                array[count]=array[count+1];
                array [count+1] = temp;
                madeAswap=true;//             Set madeAswap flag to true
             }//         End If

        }//     End For
     --lastIndex; //     Subtract 1 from lastIndex
    }// End While
}

/*****************************************************************
 *                        BinarySearch                           *
 * This function performs a Binary search on an array of pointers*
 * The list array, based on SSNName which has size elements,     *
 * is searched for the number stored in value. If the number     *
 * is found, its array subscript is returned.                    *
 *                   Otherwise, -1 is returned.                  *
 *****************************************************************/
int BinarySearchSSN(Student *list[], int size, string value)
{
    int first =0,
        last = size-1,
        middle,
        position;  
    bool found=false; // Flag to indicate if the value was found

    while (!found && first <= last)
    {    
        middle=(first + last)/2;
	    if (list[middle]->ssn == value)  // If the value is found 		
        {
            found=true;
            position = middle; 
	     }
        else if (list[middle]->ssn > value)
            last = middle - 1;
        else
           first = middle + 1;
    }
    return position;         // Return position, or -1
}

/*****************************************************************
 *                        BinarySearch                           *
 * This function performs a Binary search on an array of pointers*
 * The list array, based on LastName which has size elements,    *
 * is searched for the number stored in value. If the number     *
 * is found, its array subscript is returned.                    *
 *                   Otherwise, -1 is returned.                  *
 *****************************************************************/
int BinarySearchLastName(Student *list[], int size, string value)
{
    int first =0,
        last = size-1,
        middle,
        position;  
    bool found=false; // Flag to indicate if the value was found

    while (!found && first <= last)
    {    
        middle=(first + last)/2;
	    if (list[middle]->lastName == value)  // If the value is found 		
        {
            found=true;
            position = middle; 
	     }
        else if (list[middle]->lastName > value)
            last = middle - 1;
        else
           first = middle + 1;
    }
    return position;         // Return position, or -1
}
