//main.cpp
// Description: Program that will analyze population for
//each state
// Name(s): Taylor Martin
// Date:1/16/2020
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include <windows.h>
#include "grads.h"

using namespace std;

const int NUM_MAJORS = 45;

int main ()
{   HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(screen, 10);
    int choice;
    GradEmploymentData graduatesArray[NUM_MAJORS];
    ifstream readFile;

   readFile.open ("graduates2015.csv");

   if (!readFile)
      {
          cout << "Error opening the file!";
          exit(0);
      }
    readCsvToArray(graduatesArray, NUM_MAJORS, readFile);

    do
        {
            displayMenu();
            choice = getChoice();
            if (choice != 99)
                {
                    switch(choice)
                        {
                            case 1:SortByLowMean(graduatesArray, NUM_MAJORS);
                                   ShowTopMeanArray(graduatesArray);
                                break;

                            case 2:SortByLowMean(graduatesArray, NUM_MAJORS);
                                   ShowLowMeanArray(graduatesArray);
                                break;

                            case 3: SortByLowMedian(graduatesArray, NUM_MAJORS);
                                    ShowHighMedianArray(graduatesArray);
                                break;
                            case 4: SortByLowMedian(graduatesArray, NUM_MAJORS);
                                    ShowLowMedianArray(graduatesArray);
                                break;
                            case 5: SortByNumAsians(graduatesArray, NUM_MAJORS);
                                    ShowTopNumAsians(graduatesArray);
                                break;

                            case 6: SortByNumAsians(graduatesArray, NUM_MAJORS);
                                    ShowLowNumAsians(graduatesArray);
                                break;

                            case 7: SortByNumMinority(graduatesArray, NUM_MAJORS);
                                    ShowTopNumMinority(graduatesArray);
                                break;
                            case 8: SortByNumMinority(graduatesArray, NUM_MAJORS);
                                    ShowLowNumMinority(graduatesArray);
                                break;
                            case 9: SortByNumWhite(graduatesArray, NUM_MAJORS);
                                    ShowTopNumWhite(graduatesArray);
                                break;
                            case 10: SortByNumWhite(graduatesArray, NUM_MAJORS);
                                     ShowLowNumWhite(graduatesArray);
                                break;
                            case 11: SortByMajor(graduatesArray, NUM_MAJORS);
                                break;

                        }
                }

        }
    while (choice !=99);
    return 0;
}
