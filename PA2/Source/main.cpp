//main.cpp
//Write a C++ program that will sort the table by
// the last name and by SSN using a dummy csv data. 
//The user interacts with the program 
// Name(s): Taylor Martin
// Date:1/31/20
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include "grades.h" 

using namespace std; 

const int NUM_PEOPLE = 20; //array size
int main()
{
    int choice;
    Student gradesArray[NUM_PEOPLE]; //array to read in and store csv file data
    ifstream readFile;
    Student *indexBySSN[NUM_PEOPLE]; //array of pointers to sort and index based on SSN
    Student *indexByLastName[NUM_PEOPLE]; //array of pointers to sort and index based on Last Name
    Student *indexByFirstName[NUM_PEOPLE]; //array of pointers to sort and index based on First Name
    string SSN; //used to obtain SSN by user input 
    string Last_Name; //used to obtain Last Name by user input 
    int pos, pos2; 
    



   readFile.open("grades.csv");

   if (!readFile)
    {
        cout << "Error opening the file!"; //if error in opening file, displays menu exts program
        exit(0);
    }
    readCsvToArray(gradesArray, NUM_PEOPLE, readFile); //reads csv file data to gradesArray
    
    for (int index = 0; index < NUM_PEOPLE; index++) //copies gradesArray data to indexByLastName, an array of pointers
    {
        indexByLastName[index] = &gradesArray[index]; 
    }
    
    for (int index = 0; index < NUM_PEOPLE; index++) //copies gradesArray data to indexByLastName, an array of pointers
    {
        indexByFirstName[index] = &gradesArray[index]; 
    }

    for (int index = 0; index < NUM_PEOPLE; index++) //copies gradesArray data to indexByLastName, an array of pointers
    {
        indexBySSN[index] = &gradesArray[index]; 
    }
    SortBySSN(indexBySSN, NUM_PEOPLE); 
    SortByLastName(indexByLastName, NUM_PEOPLE); 
    SortByFirstName(indexByFirstName, NUM_PEOPLE); 

    // for (int i = 0; i < NUM_PEOPLE; ++i)
    // {
    //     cout << i << ' ' << gradesArray[i].lastName << "  "  //used to make sure data read into the array correctly,then commented out to not use
    //          << gradesArray[i].firstName << '\n';
    // }

    do
    {   
        displayMenu(); //calls display menu fuction to output menu on screen
        choice = getChoice(); //gets menu choice from user 
        if (choice != 6)
        {
            switch(choice)
            {
                case 1: cout << left << setw(10)<< "ID" << setw(10) << "Last Name" << setw(13) << "First Name" << setw(10) << "SSN" << "Letter Grade\n\n"; 
                        for (int i = 0; i < NUM_PEOPLE; ++i) //outputs indexByLastName Data sorted in ascending order 
                        {
                            cout << left << setw(10) << indexByLastName[i]->id << setw(10) << indexByLastName[i]->lastName << setw(10)
                            << indexByLastName[i]->firstName << setw(20)<< indexByLastName[i]->ssn << setw(10)<< indexByLastName[i]->letterGrade<< '\n';
                        }
                    break;

                case 2: cout << left << setw(10)<< "ID" << setw(10) << "Last Name" << setw(13) << "First Name" << setw(10) << "SSN" << "Letter Grade\n\n"; 
                        for (int i = 0; i < NUM_PEOPLE; ++i) //outputs indexByFirstName Data sorted in ascending order 
                        {
                            cout << left << setw(10) << indexByFirstName[i]->id << setw(10) << indexByFirstName[i]->lastName << setw(10)
                            << indexByFirstName[i]->firstName << setw(20)<< indexByFirstName[i]->ssn << setw(10)<< indexByFirstName[i]->letterGrade<< '\n';
                        }
                    break;

                case 3: cout << left << setw(10)<< "ID" << setw(10) << "Last Name" << setw(13) << "First Name" << setw(10) << "SSN" << "Letter Grade\n\n"; 
                        for (int i = 0; i < NUM_PEOPLE; ++i) //outputs indexBySSN Data sorted in ascending order 
                        {
                            cout << left << setw(10) << indexBySSN[i]->id << setw(10) << indexBySSN[i]->lastName << setw(10)
                            << indexBySSN[i]->firstName << setw(20)<< indexBySSN[i]->ssn << setw(10)<< indexBySSN[i]->letterGrade<< '\n';
                        }
                    break;
                case 4: cout << "Please enter a last name you would like to search for starting with a capital letter, for example Doe. Enter A Last Name:     ";
                        cin >> Last_Name; 
                        pos = BinarySearchLastName(indexByLastName, NUM_PEOPLE, Last_Name); //calls Binary search function to search by last name
                        if (pos == -1) 
                        {
                            cout << "Name not found! \n"; //if not found, displays message
                        }
                        else
                        {   cout << left << setw(10)<< "ID" << setw(10) << "Last Name" << setw(13) << "First Name" << setw(10) << "SSN" << "Letter Grade\n\n";  
                            for (int index=pos; index <= pos; index++) //displays searched for and returned data
                            {
                                cout << "\n"; 
                                cout << left << setw(10) << indexByLastName[index]->id << setw(10) << indexByLastName[index]->lastName << setw(10)
                                << indexByLastName[index]->firstName << setw(20)<< indexByLastName[index]->ssn << setw(10)<< indexByLastName[index]->letterGrade<< '\n';
                            }
                        }
                        
                    break;
                case 5: cout << "Please enter a SSN you would like to search seperated by dashes - ; For example: 123-45-6789. Enter A SSN:     ";
                        cin >> SSN;  
                        pos2 = BinarySearchSSN(indexBySSN, NUM_PEOPLE, SSN); //calls binary search function to search for SSN
                        if (pos2 < 0) 
                        {
                            cout << "SSN not found! \n"; //if not found displays message
                        }
                     else
                        {   cout << left << setw(10)<< "ID" << setw(10) << "Last Name" << setw(13) << "First Name" << setw(10) << "SSN" << "Letter Grade\n\n"; 
                            for (int index=pos2; index <= pos2; index++) //displays searched for and returned data
                            {
                                cout << "\n"; 
                                cout << left << setw(10) << indexBySSN[index]->id << setw(10) << indexBySSN[index]->lastName << setw(10)
                                << indexBySSN[index]->firstName << setw(20)<< indexBySSN[index]->ssn << setw(10)<< indexBySSN[index]->letterGrade<< '\n';
                            }
                        }
                    break;
            }
        }
    } while (choice !=6);
    return 0;
}

