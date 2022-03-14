// test.cpp
// Description: Implement my own version of the vector that uses
//  dynamic memory allocation and pointers
// Name(s): Taylor Martin, Dan Blanchette, Stephen Haldi
// Date:1/23/2020
#include "myVector.h"
#include <iostream>
#include <iomanip> 
using namespace std; 


int main ()
{
    Vector vect;

    vect.push_back(10); 
    vect.push_back(20); 
    vect.push_back(30); 
    vect.push_back(40); 
    vect.push_back(50); 

    cout << "The Vector size is "<< vect.size() << endl; 
    cout << "Vector Capacity is "<< vect.capacity() << endl; 
    for (int index=0; index < vect.size(); index++) 
    {
        cout << "Vector Element "<< index << " "<< vect.at(index) << endl; 
    }

    cout << "After updating 1st Index "<< endl; 
    vect.set(1,200); 
    cout << "Vector Capacity is "<< vect.capacity() << endl; 
    for (int index=0; index < vect.size(); index++) 
    {
        cout << "Vector Element "<< index << " "<< vect.at(index) << endl; 
    }

    vect.pop_back(); 
    cout << "The Vector size is "<< vect.size() << endl; 
    cout << "Vector Capacity is "<< vect.capacity() << endl; 
    for (int index=0; index < vect.size(); index++) 
    {
        cout << "Vector Element "<< index << " "<< vect.at(index) << endl; 
    }

    return 0; 
}