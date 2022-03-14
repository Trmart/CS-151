//grads.h
// Description: Program that will analyze population for
//each state
// Name(s): Taylor Martin
// Date:1/16/2020
#ifndef GRADS_H
#define GRADS_H
#include <string>
using namespace std;

struct GradEmploymentData
{
    int demographicsTotal;     // The estimated total of people awarded degrees in this major during 2005
    string educationMajor;     // The name of the major for these graduated students
    float meanSalary;          // The average (mean) recorded salary reported for employed people with this degree
    float medianSalary;        // The median recorded salary reported for employed people with this degree
    int demographicsAsian;     // The estimated number of people identifying as Asian that were awarded degrees in this major
    int demographicsMinority;  // The estimated number of people identifying as minority
                               // (e.g., Black, African American, Native American) that were awarded degrees in this major
    int demographicsWhite;     // The estimated number of people identifying as White that were awarded degrees in this major
    int demographicsFemales;   // The estimate number of women awarded degrees in this major
    int demographicsMales;     // The estimate number of men awarded degrees in this major
    int educationBachelor;     // The estimated number of bachelor degrees awarded in this for major
    int educationDoctorate;    // The estimated number of doctoral degrees awarded in this for major
    int educationMasters;      // The estimated number of Masters awarded in this for major
};

void readCsvToArray(GradEmploymentData array[], int size, ifstream& file);
void displayMenu();
int getChoice();
void SortByLowMean(GradEmploymentData array[], int size);
void SortByLowMedian(GradEmploymentData array[], int size);
void SortByNumAsians(GradEmploymentData array[], int size);
void SortByNumMinority(GradEmploymentData array[], int size);
void SortByNumWhite(GradEmploymentData array[], int size);
void SortByMajor(GradEmploymentData array[], int size );
bool BinarySearch(GradEmploymentData array[], int size, string);
void ShowLowMeanArray(GradEmploymentData array[]);
void ShowTopMeanArray(GradEmploymentData array[]);
void ShowLowMedianArray(GradEmploymentData array[]);
void ShowHighMedianArray(GradEmploymentData array[]);
void ShowLowNumAsians(GradEmploymentData array[]);
void ShowTopNumAsians(GradEmploymentData array[]);
void ShowLowNumMinority(GradEmploymentData array[]);
void ShowTopNumMinority(GradEmploymentData array[]);
void ShowLowNumWhite(GradEmploymentData array[]);
void ShowTopNumWhite(GradEmploymentData array[]);


#endif
