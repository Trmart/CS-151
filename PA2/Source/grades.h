//grades.h
//Write a C++ program that will sort the table by
// the last name and by SSN using a dummy csv data. 
//The user interacts with the program 
// Name(s): Taylor Martin
// Date:1/31/20
#ifndef GRADES_H
#define GRADES_H
#include <string> 
using namespace std; 

struct Student
{
    int id;
    string lastName;  //holds lastName
    string firstName; //holds fistName
    string ssn;       //stores SSN
    float test[4];    //test score array to hold test scores
    float final;      //stores final grade data 
    string letterGrade;//stores letter grade 
};

void readCsvToArray(Student array[], int size, ifstream& file); 
void displayMenu(); 
int getChoice(); 
void SortBySSN(Student *array[], int size); 
void SortByLastName(Student *array[], int size); 
void SortByFirstName(Student *array[], int size); 
int BinarySearchSSN(Student *list[], int size, string value); 
int BinarySearchLastName(Student *list[], int size, string value); 
#endif