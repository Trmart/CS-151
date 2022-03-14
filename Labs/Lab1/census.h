#ifndef CENSUS_H
#define CENSUS_H
#include <string> 
using namespace std; 
struct CensusData
{
    int division;             // Census division code
    string state;             // State name
    int totalPopulation;      // Resident population estimate
    int adultPopulation;      // Resident population estimate >=18yrs old
    float pctAdultPopulation; // % of resident population >=18yrs old
};

void readCsvToArray(CensusData array[], int size, ifstream& file); 
void SortByTotalPop(CensusData array[], int size); 
void SortByAdultPop(CensusData array[], int size); 
void SortByDivision(CensusData array[], int size); 

#endif 
