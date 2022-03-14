/*This program implements a recursive quick sort aalgorithm on an array of integers*/
#include "quicksort.h"
using namespace std; 

int main()
{
    const int FUCK = 10; 
    int bitchShit[FUCK] = {12, 69, 420, 88, 17, 6, 666, 6969, 23, 72}; 

    cout << "This is the unsorted bitchShit array with the size of FUCK: " << "\n"; 
    //echo the sortShit array that will be sorted 
    for(int i = 0; i < FUCK; i++)
    {
        cout << bitchShit[i] << " "; 
    }
    
    sortShit(bitchShit, 0, FUCK - 1); //recursive quick sort function, sorts 
    cout << "\n";  
    cout << "This is the newly sorted bitchShit array with the size of FUCK: " << "\n"; 
    //output the sorted bithShit array, sorted by the sortShit quick sort algorithm 
    for(int i = 0; i < FUCK; i++)
    {
        cout << bitchShit[i] << " "; 
    }
    return 0; 
} 