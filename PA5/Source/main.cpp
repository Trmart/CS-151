/*
Taylor Martin 
North Idaho College CS-151 
PA 5: Binary Search Tree and Morse Code Lookup
4/5/20
*/ 
#include "bst.h"
using namespace std; 

int main()
{
    

    MorseLookupBst BST; 
    ifstream inFile; 
    inFile.open("convert.txt"); 
    if(!inFile) //checks to see if the file can be opened
    {
        cout << "Error Opening The File 'convert.txt'\n"; //error message if cannot open file 
    }
    char tempCh; //temporary character variable to hold the character read in from the file 
    string tempStr; //temporary string to hold the converted morse code and add them together to display on screen
    cout << "\nThe Converted Text Is: \n"; 
    while(inFile.get(tempCh)) //reads file in until there are no more characters to read 
    {
        if(tempCh == ' ')
        {
            cout << "   "; 
        }
        else if(tempCh == '\n')
        {
            cout << "\n"; 
        }
        else 
        {
            tempStr = BST.search(tempCh); //seach function to search through BST and find corressponding morse sequence. 
            cout << tempStr << " ";  //displays morse code 
        }
    }
    inFile.close(); 
    cout << "\nThank You, Have A Great Day!\n"; 
    return 0; 
}
