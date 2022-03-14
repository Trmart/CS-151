// MyString.cpp
// Description: Implement my own version of the string that uses
//  dynamic memory allocation and C-string
// Name(s):Taylor Martin and Aaron Agostinelli
// Date:1/30/2020
#include "myString.h"
using namespace std; 

String::String() 
{
    //cout << "Default constructor got called!\n";
    m_string = new char[1]; 
    m_string[0] = '\0'; 
    m_size = 0; 
}

String::String(const char* s)
{
    //cout << "String(const char*s) got called!\n";
    m_size = strlen(s); 
    m_string = new char[m_size+1]; 
    strcpy(m_string, s); 
}

String::String(const String& str) // copy constructor
{
    //cout << "String(const String& str) got called!\n";
    m_size = str.m_size; 
    m_string = new char[m_size+1];
    strcpy(m_string,str.m_string); 
}

String::~String()               // destructor
{
     //cout << "Destructor got called!\n";
     delete[] m_string; 
}

const char* String::c_str() const 
{
    return m_string; 
}
 
int String::size() const
{
    return m_size; 
}

    
int String::length() const
{
    return m_size; 
}

String& String::str(const char* s) 
{
    if(m_size>0); 
    {
        delete[] m_string; 
    }
    m_size = strlen(s); 
    m_string = new char[m_size+1];
    strcpy(m_string,s); 
    return *this; 
}

String& String:: str(const String& str)
{
    if(m_size>0); 
    {
        delete[] m_string; 
    }
    m_size = str.m_size; 
    m_string = new char[m_size+1];
    strcpy(m_string,str.m_string); 
    return *this; 
}

String& String :: operator=(const char* s)
{
    if(m_size>0); 
    {
        delete[] m_string; 
    }
    m_size = strlen(s); 
    m_string = new char[m_size+1];
    strcpy(m_string,s); 
    return *this; 
}
String& String:: operator=(const String& str)
{
      if(m_size>0); 
    {
        delete[] m_string; 
    }
    m_size = str.m_size; 
    m_string = new char[m_size+1];
    strcpy(m_string,str.m_string); 
    return *this; 
}
char& String:: at(int index)
{
    return m_string[index]; 
}

char& String::operator[](int index)
{
    return m_string[index];
}

// int String::find(const char* s)
// {   int position = 0; 
//     int index = 0; 
//     bool found = false; 

//     while (index < m_size && !found)
//     {
//         if (m_string[index] == value)
//     }
// }