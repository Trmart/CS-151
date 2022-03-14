// Taylor Martin 
// Dan Blanchette
// Aaron Agostinelli 
// 3/12/20
// CS-151 Lab 09 
// Binary Search Trees
#include "bst.h"
#include <fstream>
#include <vector>
using namespace std; 
int main()
{   
    vector <string> BTS; 
    ifstream file; 
    BST tree; 
    file.open("names.txt"); 
    if(file.fail())
    {
        cout << "Could not open the file \n"; 
    }
    while(!file.eof())
    {   
        string temp; 
        getline(file,temp); 
        BTS.push_back(temp); 
    }
    for(int i=0; i<BTS.size();i++)
    {
        cout << BTS[i] << "\n"; 
    }
    for(int i=0; i<BTS.size();i++)
    {
        tree.addNode(BTS[i]); 
    }
    BTS.clear(); 
    for(int i= 0; i < tree.size();i++)
    {
        BTS.push_back(tree.storeInOrder()); 
    }

    file.close(); 
    return 0; 
}