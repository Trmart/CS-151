#ifndef GENES_H
#define GENES_H
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip> 
#include <algorithm> 
#include <vector>
using namespace std;


string formatThis(string original); 
double count(string , char, char); 
string revGene( string originalGenome, string revGenome);
int findCodons(vector<int>& codons, string geneSeq, string codonString);
void selectGeneSort( vector<int>& stopCodones);


#endif