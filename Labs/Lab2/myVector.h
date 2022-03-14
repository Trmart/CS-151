// test.cpp
// Description: Implement my own version of the vector that uses
//  dynamic memory allocation and pointers
// Name(s): Taylor Martin, Dan Blanchette, Stephen Haldi
// Date:1/23/2020
#ifndef myVector_H
#define myVector_H
#include <iostream> 
#include <cstdlib>
using namespace std; 

class Vector
{
public: 
    // Default constructor to initialize 
    // an initial capacity of 1 element and 
    // allocating storage using dynamic allocation 
    Vector();
  
    // Adds an element to the end
    void push_back(int data);

    // Updates element at any index that
    // works like the [] operator
    void set(int index, int data);
        // function to extract element at any index 
    int at(int index);

    // Removes the last element
    void pop_back();

    // Returns the number of elements
    int size() const;

    // Returns the number of elements that 
    // can be held in currently allocated storage
    int capacity() const;

private:
    // integer pointer that points 
    // to a dynamically allocated array
    // that holds the elements of the vector
    int* m_elements;

    // tracks the number of elements 
    // currently present in the vector 
    int m_size; 

    // capacity is the total storage 
    // capacity of the vector 
    int m_capacity; 
};
#endif