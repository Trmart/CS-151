// test1.cpp
// Description: 
// Name(s): Taylor Martin, Steven Haldie, Aaron Agostinelli
// Date: 2/13/20
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

int main()
{
    // Step 1: Print 1 to 1000 with zeroes for alignment
    // and append .txt at the end of each number. However,
    // you are not going to directly print it to the screen
    // but use ostringstream then print it from ostringstream
    // to the screen.
    //
    // Program should display
    //   0001.txt
    //   0002.txt
    //   ...
    //   0123.txt
    //   ...
    //   1000.txt
    //
    // Hint: Use setfill(), setw(), ostringstream

    // a) Create an instance or object of an output string stream 
    ostringstream out; 
    for (int i = 0; i < 1000; ++i)
    {   
        out << setw(4) << setfill('0') << (i + 1) << ".txt"; 
        cout << out.str() << "\n"; 
        // b) Send formatted data into output string stream object
        // c) Display data in the output string stream object to the screen
        // d) Clear data in output string stream object
        out.str(""); 
    }

    return 0;
}