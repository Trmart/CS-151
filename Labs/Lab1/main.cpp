// main.cpp
// Description: Program that will analyze population for
//each state
// Name(s): Taylor Martin
// Date:1/16/2020

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include "census.h"
using namespace std;

const int NUM_STATES = 52;

int main()
{
  CensusData censusArray[NUM_STATES];
  ifstream readFile;

  readFile.open ("SCPRC-EST2019-18+POP-RES.csv");

  if (!readFile)
    { cout << "Error opening the file!";
     exit(0);
    }
    readCsvToArray(censusArray, NUM_STATES, readFile);
    SortByTotalPop(censusArray,NUM_STATES);
    
    
    

    ofstream writeFile;
    writeFile.open("top20statesbytotalpop.csv");
    for (int count = 0; count < 20; count++)
     {
      writeFile << censusArray [count].division << ',';
      writeFile << censusArray [count].state << ',';
      writeFile << censusArray [count].totalPopulation << ',';
      writeFile << censusArray [count].pctAdultPopulation << '\n';
     }
     writeFile.close();
     
    //  SortByAdultPop(censusArray,NUM_STATES);
    //  writeFile.open("top20statesbyadultpop.csv");
     
    // for (int count = 0; count < 20; count++)
    //   {
    //   writeFile << censusArray [count].division << ',';
    //   writeFile << censusArray [count].state << ',';
    //   writeFile << censusArray [count].totalPopulation << ',';
    //   writeFile << censusArray [count].pctAdultPopulation << "\n";
    //  }
    //  writeFile.close();
    SortByDivision(censusArray,NUM_STATES);
    writeFile.open("alldatabydivision.csv");
    for (int count = 0; count < 20; count++)
     {
      writeFile << censusArray [count].division << ',';
      writeFile << censusArray [count].state << ',';
      writeFile << censusArray [count].totalPopulation << ',';
      writeFile << censusArray [count].pctAdultPopulation << "\n";
     }
     writeFile.close();
    
    cout << censusArray[0].state << " has the lowest population" << censusArray[0].totalPopulation; 
    cout << censusArray[51].state << " has the highest population" << censusArray[0].totalPopulation;
    
    return 0;

}
