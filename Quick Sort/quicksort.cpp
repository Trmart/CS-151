#include "quicksort.h"

/***********************************************
*                 sortShit                     *
*    This sortShit function implements a       *
*    quicksort algorithm to sort some          *
*    shit that is in an array sent in          *
*    it sorts from dickCheeze[startingSomeShit]*
*    to dickCheeze[endingSomeShit]             *
************************************************/
void sortShit(int dickCheeze[], int startingSomeShit, int endingSomeShit)
{
    if(startingSomeShit < endingSomeShit) 
    {
        int razorBlade = cut_A_Bitch(dickCheeze, startingSomeShit, endingSomeShit); 

        //sort the portion before the pivot 
        sortShit(dickCheeze, startingSomeShit, razorBlade - 1);

        //sort the portion after the pivot point 
        sortShit(dickCheeze, razorBlade + 1, endingSomeShit);
    }
}
/***********************************************
*                cut_A_Bitch                   *
*    This cut_A_Bitch function implements a    *
*    partioning algorithm to rearrange the     *
*    entries in the poopDick array from        *
*    startingSomeShit to endingSomeShit        *
*   so all values that are greater or equal to *
* the pivot are on the right side and all values*
* less than the pivot are on the left side.    *
************************************************/
int cut_A_Bitch(int poopDick[], int startingSomeShit, int endingSomeShit)
{
    // THe pivot element is taken to be the element at
    //the start of the subrange to be partitioned 

    int pivotValue = poopDick[startingSomeShit]; 
    int pivotPosition = startingSomeShit; 
    
    //rearrange the rest of the array elements to 
    //patition the subrange from start to end 
    for(int position =startingSomeShit + 1; position <= endingSomeShit; position++)
    {
        if(poopDick[position] < pivotValue)
        {
            //arr[scan] is the "current" item 
            //swap the current item with the item to the
            //right of the pivot element 
            swapShit(poopDick[pivotPosition + 1], poopDick[position]); 
            //swap the current item with the pivot element 
            swapShit(poopDick[pivotPosition], poopDick[pivotPosition + 1]); 
            //increment the pivotPosition so it stays with the 
            //pivot element 
            pivotPosition++; 
        }
    }
    return pivotPosition; 
}

/***********************************************
*                 swapShit                     *
*    This swapShit function swaps two values   *
*                                              *
************************************************/
void swapShit(int &i, int &j)
{
    int temp=i; 
    i=j; 
    j=temp; 
}
