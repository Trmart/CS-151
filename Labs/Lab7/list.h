/*Taylor Martin
   Dan Blanchette
   Lab 07 
   CS-151L 
   2/27/20*/
#ifndef LIST_H
#define LIST_H

#include <string>
#include <vector>
#include <sstream>
#include <cstdlib> 
#include <iostream> 

using namespace std;

struct ListNode
{
    string value;
    ListNode* next;
    ListNode* prev;
    ListNode(string value1, ListNode* next1=nullptr, ListNode* prev1=nullptr)
    {
        value = value1;
        next = next1;
        prev = prev1;
    }
};

class List
{
public: 
    // Default constructor to initialize 
    List();
    List(const string arr[], int size);
    List(const vector<string>& vec);
    List(const List& srcList);
    ~List();
  
    // Adds an element to the beginning of the list
    void addFront(string data);

    // Adds an element to the end of the list
    void addEnd(string data);

    // Removes the first element of the list
    void removeFront();

    // Removes the last element of the list
    void removeEnd();

    // Returns the number of elements
    int size() const;

    // Returns true if list is empty, otherwise false
    bool empty() const;

    // Returns string of the values in the list separated by spaces
    string str() const;

    // Returns string of the values in the list in reverse 
    // separated by spaces
    string strReverse() const;

    // Returns a reference to the value of the first element in the list
    string& front();

    // Returns a reference to the value of the last element in the list
    string& end();

    // Returns a reference to the value of nth index in the list
    string& getNth(int index) const;


    // Returns the vector version of the list
    vector<string> toVector() const;

private:
    ListNode* m_head;  // points to the head of the list
    ListNode* m_tail;  // points to the end of the list

    // tracks the number of elements 
    // currently present in the vector 
    int m_size; 
};

#endif 