// recover.cpp
// Description: 
// Name(s): Taylor Martin, Steven Haldie, Aaron Agostinelli
// Date: 2/13/20
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdint>
using namespace std;

// Block size
const unsigned short BLOCK_SIZE = 512;

// JPEG Signatures
const uint8_t JPEG_SIG[2][4] = {{0xff, 0xd8, 0xff, 0xe0},
                                {0xff, 0xd8, 0xff, 0xe1}};

bool isJpegSignature(uint8_t* memblock);

int main()
{
    // STEP 1: Create an fstream instance called inFile and
    // use the fstream constructor toopen card.raw file 
    // with the combine mode of input(read) and binary mode.
    fstream inFile("card.raw", ios::in | ios::binary);
    
    // STEP 2: If file is not opened successfully
    // prompt user of the failure and exit the program.
    if(!inFile)
    {
        cout << "File not opened successfully, exiting program";
        exit(0);
    }

    // STEP 3: Create an array called memoryBlock 
    // that can hold exactly 512 bytes.

    uint8_t memoryBlock[BLOCK_SIZE];
    
    // STEP 4: Read from the file a memory block of only 512 bytes of data 
    // and load it to the array you created in STEP 3.
    inFile.read(reinterpret_cast<char*>(memoryBlock),BLOCK_SIZE);

    fstream img;            // Image file stream use to save images found
    ostringstream ostr;     // String stream to generate file names for the image
    int imgNum = 0;         // Keep track of image number
    bool imgFound = false;  // Set true if at least a JPEG image is found

    cout << showbase;
    while (!inFile.eof())
    {
        // STEP 5: Get the current position in the file and save it
        // into an integer variable
        int curPos = inFile.tellg();
        // STEP 6: Repeat code in STEP 4

        inFile.read(reinterpret_cast<char*>(memoryBlock),BLOCK_SIZE);

        // STEP 7: Implement isJpegSignature function. This function is
        // used to determine if the first four bytes of the memory block
        // read from the file has the JPEG signature. The return value 
        // of the isJpegSignature function is used as the condition of 
        // the if statement below.
        if (isJpegSignature(memoryBlock))
        {
            //     STEP 8: Close image file stream
            img.close();
            //     STEP 9: Display current file position in decimal

            cout << dec << "The current file position is: " << inFile.tellp() <<"\n"; 
            //     Example:
            //     Current file position: 188928
            //for (int i= 0)
            //     STEP 10: Display the first four bytes
            //     in the memory in hexadecimal
            
            //     Example:
            //     JPEG signature: 0xff 0xd8 0xff 0xe1

            //     STEP 11: Increment image number
            imgNum++; 
            //     STEP 12: Create filename of the image file using
            //     the method you learned in test1.cpp
            ostr << setw(3) << setfill('0') << (imgNum) << ".jpg";
            //     STEP 13: Display the name of the image file
            cout << "Creating file " << ostr.str() << "\n"; 
            //     Example:
            //     Creating file 001.jpg
            //ostr.str(""); 

            //     STEP 14: Open the file using the image file stream
            //     using the combined mode of output and binary
            img.open(ostr.str(), ios::out | ios::binary); 
            //     STEP 15: Clear string stream to empty string
            
            ostr.str(""); 

            //     STEP 16: Set imgFound to true
            imgFound = true; 
        }

        if (imgFound)
        {
            // STEP 17: Write to the image file stream the memory block
            // stored in the array into the image file.
            img.write(reinterpret_cast<char*>(memoryBlock), BLOCK_SIZE); 
        }
    }

    // STEP 18: Close both image file stream and card file stream
    img.close();
    inFile.close(); 

    return 0;
}

/**Checks if the first four bytes of a 512 bytes memory block
 * contains the JPEG signatures. Use the const JPEG_SIG variable
 * to test it.
 * 
 * @param memblock array of bytes with a size defined in BLOCK_SIZE
 * 
 * @return a bool value of true if it contains the JPEG signature,
 * otherwise false.
 */
bool isJpegSignature(uint8_t* memblock)
{
    if (memblock[0]==JPEG_SIG[0][0] && memblock[1] == JPEG_SIG[0][1] && memblock[2] == JPEG_SIG [0][2] && memblock[3] == JPEG_SIG [0][3])
        return true; 
    if (memblock[0]==JPEG_SIG[1][0] && memblock[1] == JPEG_SIG[1][1] && memblock[2] == JPEG_SIG [1][2] && memblock[3] == JPEG_SIG [1][3])
        return true; 
    return false;  // temporary until fully impelemented
}
