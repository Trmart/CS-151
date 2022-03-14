// test.cpp
// Description: Implement my own version of the string that uses
//  dynamic memory allocation and C-string
// Name(s):Taylor Martin and Aaron Agostinelli
// Date:1/30/2020
#ifndef MYSTRING_H 
#define MYSTRING_H
#include <iostream> 
#include <iomanip> 
#include <cstring>
using namespace std; 




class String
{
public:
    String();
    String(const char* s);
    String(const String& str); // copy constructor
    ~String();                 // destructor
    String& str(const char* s); 
    String& str(const String& str); 
    String& operator=(const char* s);
    String& operator=(const String& str);

    // Searches the string for the first occurrence of the sequence 
    // specified by its arguments. Returns the starting index where
    // the string is found. If not found, return -1.
    int find(const char* s, int pos=0);

    // The substring is the portion of the object that starts at 

        // character position pos and spans len characters 
    // (or until the end of the String, whichever comes first).
    // len = -1 indicates all characters until the end of the String
    String substr(int pos=0, int len=-1);

    // Returns a pointer to an array that contains a null-terminated 
    // sequence of characters (i.e., a C-string) representing the 
    // current value of the string object.
    const char* c_str() const;

    // Get character in String
    char& at(int index);
    char& operator[](int index);

    // Return the length of String
    int size() const;

    // Return the length of String
    int length() const;

private:
    char* m_string;
    int m_size;
};
    #endif