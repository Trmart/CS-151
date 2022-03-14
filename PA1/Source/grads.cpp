//grads.cpp
// Description: Program that will analyze population for
//each state
// Name(s): Taylor Martin
// Date:1/16/2020
#include "grads.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>


/*************************************
*           displayMenu              *
*     This function displays a menu  *
*                                    *
**************************************/
void displayMenu()
{
    system ("cls");
    cout <<  "**************************************\n"
             "*             Taylor Martin          *\n"
             "*    CS-151 PA1: Data Analytics Menu *\n"
             "*                                    *\n"
             "**************************************\n";
    cout << "1.) Top 10 Majors with the Highest Mean Salary\n"; //
    cout << "2.) Top 10 Majors with the Lowest Mean Salary \n"; //
    cout << "3.) Top 10 Majors with the Highest Median Salary\n"; //
    cout << "4.) Top 10 Majors with the Lowest Median Salary\n" ;//
    cout << "5.) What are the Top 5 Majors with the Highest Number of Asians\n" ;//
    cout << "6.) What are the Top 5 Majors with the Lowest Number of Asians\n"; //
    cout << "7.) What are the Top 5 Majors with the Highest Number of Minorities\n"; //
    cout << "8.) What are the Top 5 Majors with the Lowest Number of Minorities\n"; //
    cout << "9.) What are the Top 5 Majors with the Highest Number of Caucasions\n";
    cout << "10.) What are the Top 5 Majors with the Lowest Number of Caucasions \n";
    cout << "11.) Display Information for a Specific Major \n";
    cout << "99.) Quit\n";

}

/*************************************
*           Getchoice                *
* This function gets user input      *
*                                    *
**************************************/
int getChoice()
{
    int choice;
    cin >> choice;
    while ((choice < 1 || choice > 11) && (choice !=99))
    {
        cout << "The only valid choices are 1-11, or select 99 to exit the program."<<endl;
        cin >> choice;
    }

    return choice;
}

/*************************************
*           readCsvToArray           *
*    This function copies csv data   *
*             to an array            *
**************************************/
void readCsvToArray(GradEmploymentData array[], int size, ifstream& file)
{
   string dummyString;
   getline(file, dummyString);

   int index = 0;
   char delim = ',';
   while (!file.eof() && index < size)
    {
        file >> array [index].demographicsTotal >> delim;
        getline(file, array[index].educationMajor,delim);
        file >> array[index].meanSalary >> delim;
        file >> array[index].medianSalary >> delim;
        file >> array[index].demographicsAsian >> delim;
        file >> array[index].demographicsMinority >> delim;
        file >> array[index].demographicsWhite >> delim;
        file >> array[index].demographicsFemales >> delim;
        file >> array[index].demographicsMales >> delim;
        file >> array[index].educationBachelor >> delim;
        file >> array[index].educationDoctorate >> delim;
        file >> array[index].educationMasters >> delim;

        index++;

    }

}

/*************************************
*           SortByLowMedian          *
*  This function uses a Bubble Sort  *
* to sort an array  based on  median *
**************************************/
void SortByLowMedian(GradEmploymentData array[], int size )
{ bool madeAswap = true;
  int lastIndex = size-1; // Set lastIndex to size of array - 1

  while (madeAswap)
   {
      madeAswap=false;//Set madeAswap flag to false
      for (int count = 0; count < lastIndex; count ++)//     For count = 0 to lastIndex
        {
          if (array[count].medianSalary < array[count+1].medianSalary) //If array[count] is greater than array[count + 1]
             {  GradEmploymentData temp = array[count];//Swap the contents of array[count] and array[count + 1]
                array[count]=array[count+1];
                array [count+1] = temp;
                madeAswap=true;//             Set madeAswap flag to true
             }//         End If

        }//     End For
     --lastIndex; //     Subtract 1 from lastIndex
    }// End While

}

/*************************************
*           SortByLowMean            *
*  This function uses a Bubble Sort  *
* to sort an array  based on  mean   *
**************************************/

void SortByLowMean(GradEmploymentData array[], int size )
{ bool madeAswap = true;
  int lastIndex = size-1; // Set lastIndex to size of array - 1

  while (madeAswap)
   {
      madeAswap=false;//Set madeAswap flag to false
      for (int count = 0; count < lastIndex; count ++)//     For count = 0 to lastIndex
        {
          if (array[count].meanSalary < array[count+1].meanSalary) //If array[count] is greater than array[count + 1]
             {  GradEmploymentData temp = array[count];//Swap the contents of array[count] and array[count + 1]
                array[count]=array[count+1];
                array [count+1] = temp;
                madeAswap=true;//             Set madeAswap flag to true
             }//         End If

        }//     End For
     --lastIndex; //     Subtract 1 from lastIndex
    }// End While
}

/*************************************
*           SortByNumAsians          *
*  This function uses a Bubble Sort  *
*to sort an array  based on Asian Demo*
**************************************/

void SortByNumAsians(GradEmploymentData array[], int size )
{ bool madeAswap = true;
  int lastIndex = size-1; // Set lastIndex to size of array - 1

  while (madeAswap)
   {
      madeAswap=false;//Set madeAswap flag to false
      for (int count = 0; count < lastIndex; count ++)//     For count = 0 to lastIndex
        {
          if (array[count].demographicsAsian < array[count+1].demographicsAsian) //If array[count] is greater than array[count + 1]
             {  GradEmploymentData temp = array[count];//Swap the contents of array[count] and array[count + 1]
                array[count]=array[count+1];
                array [count+1] = temp;
                madeAswap=true;//             Set madeAswap flag to true
             }//         End If

        }//     End For
     --lastIndex; //     Subtract 1 from lastIndex
    }// End While
}

/*************************************
*           SortByNumMinority        *
*  This function uses a Bubble Sort  *
* to sort an array based on minority *
**************************************/

void SortByNumMinority(GradEmploymentData array[], int size )
{ bool madeAswap = true;
  int lastIndex = size-1; // Set lastIndex to size of array - 1

  while (madeAswap)
   {
      madeAswap=false;//Set madeAswap flag to false
      for (int count = 0; count < lastIndex; count ++)//     For count = 0 to lastIndex
        {
          if (array[count].demographicsMinority < array[count+1].demographicsMinority) //If array[count] is greater than array[count + 1]
             {  GradEmploymentData temp = array[count];//Swap the contents of array[count] and array[count + 1]
                array[count]=array[count+1];
                array [count+1] = temp;
                madeAswap=true;//             Set madeAswap flag to true
             }//         End If

        }//     End For
     --lastIndex; //     Subtract 1 from lastIndex
    }// End While
}

/*************************************
*           SortByNumWhite           *
*  This function uses a Bubble Sort  *
*to sort an array based on white Demo*
**************************************/

void SortByNumWhite(GradEmploymentData array[], int size )
{ bool madeAswap = true;
  int lastIndex = size-1; // Set lastIndex to size of array - 1

  while (madeAswap)
   {
      madeAswap=false;//Set madeAswap flag to false
      for (int count = 0; count < lastIndex; count ++)//     For count = 0 to lastIndex
        {
          if (array[count].demographicsWhite < array[count+1].demographicsWhite) //If array[count] is greater than array[count + 1]
             {  GradEmploymentData temp = array[count];//Swap the contents of array[count] and array[count + 1]
                array[count]=array[count+1];
                array [count+1] = temp;
                madeAswap=true;//             Set madeAswap flag to true
             }//         End If

        }//     End For
     --lastIndex; //     Subtract 1 from lastIndex
    }// End While
}
/*************************************
*           SortByMajor              *
* This function uses Insertion Sort  *
* to sort an array based on major    *
**************************************/
void SortByMajor(GradEmploymentData array[], int size )
{
   int startScan, index;
   GradEmploymentData key;
    for (startScan = 1; startScan < size; startScan++)
    {
       key = array[startScan];
       index = startScan - 1;

       while(index >= 0 && array[index].educationMajor > key.educationMajor)
         {
            array[index+1] = array[index];
            index = index -1;
         }
      array[index + 1] = key;
    }
}


/*************************************
*         ShowLowMeanArray           *
*     This function displays the     *
*       contents of an array         *
**************************************/
void ShowLowMeanArray(GradEmploymentData array[])
{
    cout << "Education Major           Mean Salary " <<endl;
    cout << fixed << showpoint << setprecision(2);
    cout << array[0].educationMajor << setw(7) << "$ "<< array[0].meanSalary<<"\n";
    cout << array[1].educationMajor << setw(7) << "$ "<< array[1].meanSalary<<"\n";
    cout << array[2].educationMajor << setw(7) << "$ "<< array[2].meanSalary<<"\n";
    cout << array[3].educationMajor << setw(7) << "$ "<< array[3].meanSalary<<"\n";
    cout << array[4].educationMajor << setw(7) << "$ "<< array[4].meanSalary<<"\n";
    cout << array[5].educationMajor << setw(7) << "$ "<< array[5].meanSalary<<"\n";
    cout << array[6].educationMajor << setw(7) << "$ "<< array[6].meanSalary<<"\n";
    cout << array[7].educationMajor << setw(7) << "$ "<< array[7].meanSalary<<"\n";
    cout << array[8].educationMajor << setw(7) << "$ "<< array[8].meanSalary<<"\n";
    cout << array[9].educationMajor << setw(7) << "$ "<< array[9].meanSalary<<"\n";
     cin.ignore();
}
/*************************************
*         ShowTopMeanArray           *
*     This function displays the     *
*       contents of an array         *
**************************************/
void ShowTopMeanArray(GradEmploymentData array[])
{   cout << "Education Major           Mean Salary " <<endl;
    cout << fixed << showpoint << setprecision(2);
     cin.ignore();
    cout << array[45].educationMajor << setw(7) << "$ "<< array[45].meanSalary<<"\n";
    cout << array[44].educationMajor << setw(7) << "$ "<< array[44].meanSalary<<"\n";
    cout << array[43].educationMajor << setw(7) << "$ "<< array[43].meanSalary<<"\n";
    cout << array[42].educationMajor << setw(7) << "$ "<< array[42].meanSalary<<"\n";
     cin.ignore();
    cout << array[41].educationMajor << setw(7) << "$ "<< array[41].meanSalary<<"\n";
    cout << array[40].educationMajor << setw(7) << "$ "<< array[40].meanSalary<<"\n";
    cout << array[39].educationMajor << setw(7) << "$ "<< array[39].meanSalary<<"\n";
    cout << array[38].educationMajor << setw(7) << "$ "<< array[38].meanSalary<<"\n";
    cout << array[37].educationMajor << setw(7) << "$ "<< array[37].meanSalary<<"\n";
    cout << array[36].educationMajor << setw(7) << "$ "<< array[36].meanSalary<<"\n";
    cin.ignore();
}
/*************************************
*         ShowLowMedianArray         *
*     This function displays the     *
*       contents of an array         *
**************************************/
void ShowLowMedianArray(GradEmploymentData array[])
{   cout << "Education Major           Median Salary " <<endl;
    cout << fixed << showpoint << setprecision(2);
    cout << array[0].educationMajor << setw(7) << "$ "<< array[0].medianSalary;
    cout << array[1].educationMajor << setw(7) << "$ "<< array[1].medianSalary;
    cout << array[2].educationMajor << setw(7) << "$ "<< array[2].medianSalary;
    cout << array[3].educationMajor << setw(7) << "$ "<< array[3].medianSalary;
    cout << array[4].educationMajor << setw(7) << "$ "<< array[4].medianSalary;
    cout << array[5].educationMajor << setw(7) << "$ "<< array[5].medianSalary;
    cout << array[6].educationMajor << setw(7) << "$ "<< array[6].medianSalary;
    cout << array[7].educationMajor << setw(7) << "$ "<< array[7].medianSalary;
    cout << array[8].educationMajor << setw(7) << "$ "<< array[8].medianSalary;
    cout << array[9].educationMajor << setw(7) << "$ "<< array[9].medianSalary;
        cin.ignore();

}
/*************************************
*         ShowTopMedianArray         *
*     This function displays the     *
*       contents of an array         *
**************************************/
void ShowHighMedianArray(GradEmploymentData array[])
{   cout << "Education Major           Median Salary " <<endl;
    cout << fixed << showpoint << setprecision(2);
    cout << array[45].educationMajor << setw(7) << "$ "<< array[45].medianSalary;
    cout << array[44].educationMajor << setw(7) << "$ "<< array[44].medianSalary;
    cout << array[43].educationMajor << setw(7) << "$ "<< array[43].medianSalary;
    cout << array[42].educationMajor << setw(7) << "$ "<< array[42].medianSalary;
    cout << array[41].educationMajor << setw(7) << "$ "<< array[41].medianSalary;
    cout << array[40].educationMajor << setw(7) << "$ "<< array[40].medianSalary;
    cout << array[39].educationMajor << setw(7) << "$ "<< array[39].medianSalary;
    cout << array[38].educationMajor << setw(7) << "$ "<< array[38].medianSalary;
    cout << array[37].educationMajor << setw(7) << "$ "<< array[37].medianSalary;
    cout << array[36].educationMajor << setw(7) << "$ "<< array[36].medianSalary;
        cin.ignore();

}
/*************************************
*         ShowTopNumAsians           *
*     This function displays the     *
*       contents of an array         *
**************************************/
void ShowTopNumAsians(GradEmploymentData array[])
{   cout << "Education Major           Number of Asian Population " <<endl;
    cout << fixed << showpoint << setprecision(2);
    cout << array[45].educationMajor << setw(7) << array[45].demographicsAsian;
    cout << array[44].educationMajor << setw(7) << array[44].demographicsAsian;
    cout << array[43].educationMajor << setw(7) << array[43].demographicsAsian;
    cout << array[42].educationMajor << setw(7) << array[42].demographicsAsian;
    cout << array[41].educationMajor << setw(7) << array[41].demographicsAsian;
        cin.ignore();

}
/*************************************
*         ShowLowNumAsians           *
*     This function displays the     *
*       contents of an array         *
**************************************/
void ShowLowNumAsians(GradEmploymentData array[])
{   cout << "Education Major           Number of Asian Population " <<endl;
    cout << fixed << showpoint << setprecision(2);
    cout << array[0].educationMajor << setw(7) << array[0].demographicsAsian;
    cout << array[1].educationMajor << setw(7) << array[1].demographicsAsian;
    cout << array[2].educationMajor << setw(7) << array[2].demographicsAsian;
    cout << array[3].educationMajor << setw(7) << array[3].demographicsAsian;
    cout << array[4].educationMajor << setw(7) << array[4].demographicsAsian;
}
/*************************************
*         ShowTopNumMinority         *
*     This function displays the     *
*       contents of an array         *
**************************************/
void ShowTopNumMinority(GradEmploymentData array[])
{   cout << "Education Major           Number of Minority Population " <<endl;
    cout << fixed << showpoint << setprecision(2);
    cout << array[45].educationMajor << setw(7) << array[45].demographicsMinority;
    cout << array[44].educationMajor << setw(7) << array[44].demographicsMinority;
    cout << array[43].educationMajor << setw(7) << array[43].demographicsMinority;
    cout << array[42].educationMajor << setw(7) << array[42].demographicsMinority;
    cout << array[41].educationMajor << setw(7) << array[41].demographicsMinority;
}
/*************************************
*         ShowLowNumMinority         *
*     This function displays the     *
*       contents of an array         *
**************************************/
void ShowLowNumMinority(GradEmploymentData array[])
{   cout << "Education Major           Number of Minority Population " <<endl;
    cout << fixed << showpoint << setprecision(2);
    cout << array[0].educationMajor << setw(7) << array[0].demographicsMinority;
    cout << array[1].educationMajor << setw(7) << array[1].demographicsMinority;
    cout << array[2].educationMajor << setw(7) << array[2].demographicsMinority;
    cout << array[3].educationMajor << setw(7) << array[3].demographicsMinority;
    cout << array[4].educationMajor << setw(7) << array[4].demographicsMinority;
}
/*************************************
*         ShowTopNumWhite            *
*     This function displays the     *
*       contents of an array         *
**************************************/
void ShowTopNumWhite(GradEmploymentData array[])
{   cout << "Education Major           Number of Caucasion Population " <<endl;
    cout << fixed << showpoint << setprecision(2);
    cout << array[45].educationMajor << setw(7) << array[45].demographicsWhite;
    cout << array[44].educationMajor << setw(7) << array[44].demographicsWhite;
    cout << array[43].educationMajor << setw(7) << array[43].demographicsWhite;
    cout << array[42].educationMajor << setw(7) << array[42].demographicsWhite;
    cout << array[41].educationMajor << setw(7) << array[41].demographicsWhite;
}
/*************************************
*         ShowLowNumWhite        *
*     This function displays the     *
*       contents of an array         *
**************************************/
void ShowLowNumWhite(GradEmploymentData array[])
{   cout << "Education Major           Number of Caucasion Population " <<endl;
    cout << fixed << showpoint << setprecision(2);
    cout << array[0].educationMajor << setw(7) << array[0].demographicsWhite;
    cout << array[1].educationMajor << setw(7) << array[1].demographicsWhite;
    cout << array[2].educationMajor << setw(7) << array[2].demographicsWhite;
    cout << array[3].educationMajor << setw(7) << array[3].demographicsWhite;
    cout << array[4].educationMajor << setw(7) << array[4].demographicsWhite;
}
/*****************************************************************
 *                        BinarySearch                           *
 * This function performs a Binary search on an integer array.   *
 * The list array, which has size elements, is searched for      *
 * the number stored in value. If the number is found, its array *
 * subscript is returned. Otherwise, -1 is returned.             *
 *****************************************************************/
 /*bool BinarySearch (GradEmploymentData list[], int size, int value)


{
    int first =0,
        last = size-1,
        middle;


    bool found=false; // Flag to indicate if the value was found

	while (	!found && first <= last)
    {    middle=(first + last)/2;
		if (list[middle] == value) // If the value is found
		{
            found=true;

		}
        else if (list[middle]>value)
            last=middle-1;
         else
            first=middle+1;

	}
      return found;         // Return found, or -1
} */
/*************************************
*           ShowMajorInfo            *
*     This function displays the     *
*       contents of an array         *
**************************************/
