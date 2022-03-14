/*
Taylor Martin 
North Idaho College CS-151 
Gabe de la Cruz
PA 5: Binary Search Tree and Morse Code Lookup
4/5/20
*/ 
#include "bst.h"

/*****************************
 *       MorseLookupBst      *
 *  Constructor that opens a *
 *   file to be read in that *
 * holds characters and their*
 * corresponding morse code. *
 * Inserts the data to a BST *
 ****************************/
MorseLookupBst::MorseLookupBst()
{
    m_root = nullptr; 
    Code morseCode; 
    ifstream inFile; 
    inFile.open("MorseTable.txt"); 
    if(!inFile) //checks to make sure file can be opened 
    {
        cout << "Error Opening The File 'MorseTable.txt'\n"; //error message 
    }
    for(int i= 1; i < 42; i++) //for loop to loop throught the 42 total characters 
    {
        inFile>>morseCode.symbol; //reads in the character and assigns it to symbol 
        inFile>>morseCode.code; //reads in the morse code and assigns it to code 
        insert(morseCode); //calls insert function to insert nodes into a BST 
    }
    cout << "\nHere Is The Binary Search Tree Printed Recursively In Order: \n"; 
    displayInOrder(m_root); //recursive display function to shows the nodes in order 
    inFile.close(); 
}


/*****************************
 *          erase            *
 * destructor that calls an  *
 * erase function to delete  *
 *   the nodes in  a BST.    *
 ****************************/
MorseLookupBst::~MorseLookupBst()
{
    erase(); 
} 


/*****************************
 *          insert           *
 *  inserts nodes into a BST.*
 *                           *
 ****************************/
void MorseLookupBst::insert(Code newData)
{
    
    if(m_root==nullptr) //if tree is empty 
    {
        m_root = new BstNode(newData); 
    }
    else 
    {
        BstNode*treePtr = m_root; 
        BstNode*prevPtr = nullptr; 
        while(treePtr != nullptr) //while pointer is not pointing to null
        {
            prevPtr = treePtr; 
            if(treePtr->data.symbol == newData.symbol) //if duplicate, return and do nothing 
            {
                return; 
            }
            else if( newData.symbol > treePtr->data.symbol) //if greater than 
            {
                treePtr = treePtr->right; //traverse right 
            }
            else
            {
                treePtr = treePtr->left; //traverse left 
            }
        }
        if(newData.symbol > prevPtr->data.symbol)
        {
            prevPtr->right = new BstNode(newData); //inserts node on right subtree 
        }
        else
        {
            prevPtr->left = new BstNode(newData); //inserts on left subtree 
        }
    }
}


/*****************************
 *          print            *
 *  calls a helper function  *
 * displayInOrder to display *
 *   the  nodes of a BST     *
 *    Using Recursion        *
 ****************************/
void MorseLookupBst::print()
{
    displayInOrder(m_root); 
    cout << "\n"; 
}


/*****************************
 *       displayInOrder      *
 * a helper function that    *
 * uses recursion to display *
 *   the  nodes of a BST     *
 *  then returning to print  *
 ****************************/
void MorseLookupBst::displayInOrder(BstNode*ptr)
{
    if(ptr != nullptr)
    {
        displayInOrder(ptr->left); 
        cout << ptr->data.symbol << "\n";
        cout << ptr->data.code << "\n"; 
        displayInOrder(ptr->right); 
    }
}

/*****************************
 *           search          *
 *     a function that       *
 * searches the nodes of a   *
 *  BST for the character    *
 * sent to the function and  *
 * returns the corressponding*
 * morse code string to main *
 ****************************/
string MorseLookupBst::search(char letter)
{
    BstNode*treePtr = m_root; 
    bool found = false; 
    if(islower(letter)) //if the character read in is lowercase 
    {
        letter = toupper(letter); //converts it to an uppercase character 
    }
    while(!found) //while the letter sent in is not found 
    {
        if(treePtr->data.symbol == letter) //if character is found 
        {
            found = true; 
            return treePtr->data.code; 
        }
        else if(letter < treePtr->data.symbol)
        {
            treePtr = treePtr->left; //traverse left 
        }
        else if(letter > treePtr->data.symbol)
        {
            treePtr = treePtr->right; //traverse right 
        }
    }
}


/*****************************
 *           erase           *
 * a function that destroys  *
 *   the  nodes of a BST     *
 ****************************/
void MorseLookupBst::erase()
{
    BstNode*treePtr = m_root; //temp pointer 
    while((treePtr->right != nullptr) || (treePtr->left != nullptr)) //while neither of the subtree nodes are null
    {
        if(treePtr->left != nullptr)
        {
            treePtr = treePtr->left; //traverse left 
        }
        else if (treePtr->right != nullptr)
        {
            treePtr = treePtr->right; //traverse right 
        }
        else 
        {
            delete treePtr; //delete pointer 
            treePtr = m_root; 
        } 
    }
    delete treePtr; //delete 
}