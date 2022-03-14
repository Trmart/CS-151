#include "census.h"
#include <string>
#include <iostream>
#include <fstream>

void readCsvToArray(CensusData array[], int size, ifstream& file)
{
    string dummyString;
    getline(file, dummyString);

    int index = 0;
    char delim = ',';
    while (!file.eof() && index < size)
    {
        //read value for division
        file >> array [index].division>>delim;
        //read value for state
        getline(file, array[index].state,delim);

        file >> array[index].totalPopulation >> delim;
        file >> array[index].adultPopulation >> delim;
        file >> array[index].pctAdultPopulation;

        //cout << array[index].state << ',';
        //cout << array[index].adultPopulation << ',';
        //cout << array[index].pctAdultPopulation <<','<< "\n";
        index++;
   }

}

void SortByTotalPop(CensusData array[], int size )
{ bool madeAswap = true;
  int lastIndex = size-1; // Set lastIndex to size of array - 1

  while (madeAswap)
   {
      madeAswap=false;//Set madeAswap flag to false
      for (int count = 0; count < lastIndex; count ++)//     For count = 0 to lastIndex
        {
          if (array[count].totalPopulation < array[count+1].totalPopulation) //If array[count] is greater than array[count + 1]
             {  CensusData temp = array[count];//Swap the contents of array[count] and array[count + 1]
                array[count]=array[count+1];
                array [count+1] = temp;
                madeAswap=true;//             Set madeAswap flag to true
             }//         End If

        }//     End For
     --lastIndex; //     Subtract 1 from lastIndex
    }// End While

}

void SortByAdultPop(CensusData array[], int size)
{
    int startScan, minIndex;
    CensusData minValue;

    for (startScan=0; startScan < (size-1); startScan++)
    {
        minIndex = startScan;
        minValue = array[startScan];
        for (int index = startScan + 1 ; index < size; index++)
        {
            if (array[index].adultPopulation > minValue.adultPopulation)
            {
                minValue = array[index];
                minIndex = index;
            }
        }
        array[minIndex] = array[startScan];
        array[startScan] = minValue;
    }
}

void SortByDivision(CensusData array[], int size)
{  int startScan, index;
   CensusData key; 
    for (startScan = 1; startScan < size; startScan++)
    {
        key = array[startScan];
        index = startScan - 1;

        while (index >= 0 && array[index].division > key.division)
        {
            array[index + 1] = array[index];
            index = index - 1;
        }
        array[index + 1] = key;
    }
}
