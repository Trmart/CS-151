// test2.cpp
// Description: 
// Name(s): Taylor Martin, Steven Haldie, Aaron Agostinelli
// Date: 2/13/20
#include <iostream>
#include <fstream>
#include <locale>
using namespace std;

struct Data
{
    int id;
    int quantity;
    double price;
};

int main()
{
    int number1 = 17185;
    int number2 = 26409;

    // STEP 1: Using the file stream instance below, 
    // open the filename "integers.dat"
    // with a combined file modes of output and binary.
    fstream fp;
    fp.open("integers.dat", ios::out | ios::binary); 


    // STEP 2: Write both integers in STEP 1 into the file
    // using the write() member function of the file stream.
    // Ensure to close the file stream after writing all data.
   
    // To use the write() member function of the file stream,
    // it requires two arguments. 
    // - The first argument is the address
    // of the variable to store the data. However, if you 
    // check the C++ reference manual of this function, it requires
    // a char* as its first argument. However, we are writing
    // integers. This means we need to cast the address into
    // char*. This is a special situation where static_cast won't
    // work. In this case, you have to cast using
    // reinterpret_cast<char*>. This allows conversion between
    // different type of pointer data type.
    // - The second argument is how many bytes you are writing
    // to the file. In this case, an integer has 4 bytes. But
    // instead of memorizing how many bytes a data type has. 
    // You can simply use the sizeof() operator.
    fp.write(reinterpret_cast<char*>(&number1), sizeof(int));
    fp.write(reinterpret_cast<char*>(&number2), sizeof(int));
    fp.close();



    number1 = number2 = 0;
    // STEP 3: Reuse the same file stream instance declared in
    // STEP 1, open "integers.dat" with a combined file modes
    // of input and binary.
    fp.open("integers.dat", ios::in | ios::binary); 


    // STEP 4: Read both integers from the file stream using
    // the read() member function. Print both integers to the screen.
    // Ensure to close the file stream after reading all data. 
    fp.read(reinterpret_cast<char*>(&number1), sizeof(int));
    fp.read(reinterpret_cast<char*>(&number2), sizeof(int));
    fp.close();
    cout << number1 << "\n";
    cout << number2 << "\n";
    // The read() member function follows the same rules as
    // the write() function described in STEP 2 for


    uint8_t byte1 = 0xff; // 0xff = 255
    uint8_t byte2 = 0xee; // 0xee = 238
    // STEP 5: Reuse the same file stream instance declared in
    // STEP 1, open "uint8.dat" with a combined file modes
    // of output and binary.
    fp.open("uint8.dat", ios::out | ios::binary); 
    fp.write(reinterpret_cast<char*>(&byte1), sizeof(uint8_t));
    fp.write(reinterpret_cast<char*>(&byte2), sizeof(uint8_t));
    fp.close();


    // STEP 6: Write both uint8_t to the file and close the file.


    byte1 = byte2 = 0;
    // STEP 7: Open then read the data in "uint8.dat" and 
    // display the data on the screen formatted in both decimal 
    // and hexadecimal values. Also use the showbase I/O 
    // manipulator. Close the file once done.
    fp.open("uint8.dat", ios::in | ios::binary);
    fp.read(reinterpret_cast<char*>(&byte1), sizeof(uint8_t));
    fp.read(reinterpret_cast<char*>(&byte2), sizeof(uint8_t));
    fp.close(); 
    cout << showbase; 
    cout << dec << static_cast<int>(byte1) << endl;
    cout << dec << static_cast<int>(byte2) << endl;
    cout << hex << static_cast<int>(byte1) << endl;
    cout << hex << static_cast<int>(byte2) << endl;
     


    uint8_t array[5] = {12, 244, 34, 2, 6};
    // STEP 8: Open then write the data in the array variable
    // into "array.dat". Close the file once done.
    // Hint: You only need one call to the write() function.
    fp.open("array.dat", ios::in | ios::out | ios::binary);
    fp.write(reinterpret_cast<char*>(array), sizeof(uint8_t)*5); 
    

    array[0] = array[1] = array[2] = array[3] = array[4] = 0;
    // STEP 9: Open then read the data in "array.dat".
    // Display to the screen the values in the array formatted
    // in both hexadecimal and decimal. Close the file once done.
    // Hint: Similar to STEP 8, you only need one call to the
    // read() function.
    fp.seekg(0L); 
    fp.read(reinterpret_cast<char*>(array), sizeof(uint8_t));
    fp.close(); 
    
    for(int i = 0; i < 5; i++)
    {
        cout << showbase; 
        cout << dec << static_cast<int>(array[i]) << endl;
        cout << hex << static_cast<int>(array[i]) << endl;
    }






    Data sample;
    sample.id = 123;
    sample.price = 10.23;
    sample.quantity = 20;
    // STEP 10: Open then write the data in struct sample
    // in "struct.dat". Close the file once done.
    // Hint: You only need one call to the write() function.
    fp.open("struct.dat", ios::out | ios::binary);
    fp.write(reinterpret_cast<char*>(&sample), sizeof(sample));
    fp.close();


    sample.id = 0;
    sample.price = 0;
    sample.quantity = 0;

    // STEP 11: Open then read the data in "struct.dat". Load the data
    // back into the struct sample.
    // Hint: You only need one call to the read() function.

    fp.open("struct.dat", ios::in | ios::binary);
    fp.read(reinterpret_cast<char*>(&sample), sizeof(sample));
    fp.close();

    cout << dec;
    cout << "id: " << sample.id << '\n';
    cout << "quantity: " << sample.quantity << '\n';
    cout << "price: " << sample.price;
    fp.close();

    return 0;
}