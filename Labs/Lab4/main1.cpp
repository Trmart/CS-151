// main1.cpp
// Description: 
// Name(s): Taylor Martin, Yanxia Wu
// Date:02062020
#include <iostream>
#include <fstream>

#include "caesar.h"
using namespace std;


int main()
{
    string filename;
    cout << "Enter a filename: ";
    cin >> filename;

    fstream fileHandler("short.txt", ios::in);
    if (fileHandler.fail())
    {
        cout << "Error opening file!\n";
        exit(1);
    }

    string message;
    // STEP 1: Write the code to load the entire data
    //  in the file into the string message.
    //fileHandler >> message; 
    getline(fileHandler, message); 
    // STEP 2: Convert all the characters of message into UPPERCASE
    //  and display the message to the screen.
    string fullMessage = toUpperString(message); 
    cout << fullMessage << '\n'; 

    // STEP 3: Prompt user for the shift value for the Caesar Cipher
    int shift;
    cout << "Please enter a shift value:  "; 
    cin >> shift; 
    // STEP 4: Implement the caesarCipher() function. Then uncomment
    //  the next line.
    string encryptedMsg = caesarCipher(fullMessage, shift);
    cout << encryptedMsg << '\n'; 

    // STEP 5: Reuse the file stream object fileHandler to open a
    //  new file for writing. This file will be use to output
    //  the result of caesarCipher stored in the string variable
    //  encryptedMsg.
    fileHandler.close();
    fileHandler.open("outCipher", ios::out);
    fileHandler << encryptedMsg; 
    fileHandler.close(); 

    // STEP 6: Implement the decodeCaesar() function. Then uncomment
    //  the next line.
    string originalMsg = decodeCaesar(encryptedMsg, 3);
    cout << originalMsg; 
    // STEP 7: Reuse the file stream object fileHandler to open a
    //  new file for writing. This file will be use to output
    //  the result of decodeCaesar stored in the string variable
    //  originalMsg.
    fileHandler.open("outDecode", ios::out);
    fileHandler << originalMsg; 
    fileHandler.close(); 
    // STEP 8: Implement countFrequencies() function, then uncomment 
    //  the next two lines
    // char ch;
    // cout << "shift = " << countFrequencies(encryptedMsg) - 'E' << '\n';

    // STEP 9: Rerun the code and try the other two larger files. 
    // Observed the output values in STEP 8. What do you observe? And why?

    return 0;
}

