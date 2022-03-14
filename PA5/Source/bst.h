/*
Taylor Martin 
North Idaho College CS-151 
Gabe de la Cruz
PA 5: Binary Search Tree and Morse Code Lookup
4/5/20
*/ 
#ifndef BST_H
#define BST_H
#include <iostream>
#include <fstream> 
#include <string> 
using namespace std; 

struct Code
{
    char symbol; //will hold the corresponding english character 
    string code; //Will hold the corresponding Morse code characters for the English text character
}; 

struct BstNode
{
    Code data;  
    BstNode *left; //Binary Serch Tree left subtree pointer 
    BstNode *right; //Binary Search Tree right subtree pointer 
    BstNode() {}
    BstNode(Code data1, BstNode *left1=nullptr, BstNode *right1=nullptr) 
    {
        data = data1; 
        left = left1; 
        right = right1; 
    }
}; 

class MorseLookupBst
{
public:
    MorseLookupBst(); 
    ~MorseLookupBst(); 
    void insert(Code newData); //insert function to add to the BST 
    string search(char letter); //searches BST for characters being converting 
    void print(); //recursively prints the tree in order 
    void displayInOrder(BstNode*ptr); //helper function for print 
    void erase(); //deletes the BST nodes 
    void insert2(char letter, string code); 


private:
    BstNode *m_root; //Binary Search Tree root pointer 
}; 

#endif