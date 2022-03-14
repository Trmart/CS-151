#include "genes.h"
 
int main() 
{
    string fileName; 
    string extension = ".fna"; 
    string nameGenome, genomeSequence = " ";
    string revGenomeSeq =" ", spinMeRightRound; 
    char C = 'C'; 
    char G = 'G'; 
    vector <int> startCodone; 
    vector <int> stopCodone;
   
    
    cout << "\nPlease enter the File Name of a Genome:  "; 
    getline(cin,fileName); 
    
    fstream fileHandler(fileName + extension, ios::in); 
    if (fileHandler.fail())
    {
        cout << "Error opening the file! \n"; 
        exit(1); 
    } 
    
    cout << "Reading " << fileName << " .... \n\n"; 
    fileHandler.seekg(1L);
    getline(fileHandler, nameGenome); 
    cout << nameGenome << '\n';
    
    while (!fileHandler.eof())
    {
        string temp;
        getline(fileHandler,temp);
        genomeSequence = genomeSequence + temp;
    }

    fileHandler.close(); 
  
    int Genome1_Size = genomeSequence.length(); 
    string Size1 = to_string(Genome1_Size); 
    string formatted1 = formatThis(Size1); 
    cout << "The Genome Sequence has a length of  "<< formatted1 <<  " and has a GC percent content of: " << count(genomeSequence, G, C) << "% \n\n";  
    
    
    findCodons(startCodone, genomeSequence, "ATG");
    findCodons(stopCodone, genomeSequence, "TGA");
    findCodons(stopCodone, genomeSequence, "TAA"); 
    findCodons(stopCodone, genomeSequence, "TAG"); 
    
    // for(int i = 0; i < stopCodone.size(); i++)
    // {
    //     cout << stopCodone[i] << "\n"; 
    // }
    selectGeneSort(stopCodone); 
    
    // for(int i = 0; i < stopCodone.size(); i++)
    // {
    //     cout << stopCodone[i] << "\n"; 
    // }
    int start = startCodone.size(); 
    int stop = stopCodone.size()+2; 
    fileHandler.open("NC_003988_genes2.fna", ios::out); 
    int numPotentialGenes = 0; 
    for(int i = 0; i < start; i++)
    {
        int startIndex = startCodone[i]; 
        
        for(int j = 0; j < stop; j++)
        {   
            int stopIndex = stopCodone[j] + 2; 
            if(startIndex < stopIndex)
            {
                int geneLength = stopIndex - (startIndex - 1); 
                
                if (geneLength > 6 && geneLength%3==0)
                {   
                    string potentialGenes = genomeSequence.substr(startIndex,geneLength); 
                    //write to file
                    fileHandler << ">Gene#" << i+1; 
                    fileHandler << " Start=" << startIndex << " Stop=" << stopIndex; 
                    fileHandler << " Length=" << geneLength << "\n";
                    fileHandler << potentialGenes << "\n"; 
                    numPotentialGenes++; 
                    break; 
                    // if (potentialGenes.size() >= 72)
                    // {
                    //     fileHandler << "\n"; 
                    // }
                    // numPotentialGenes++; 
                    // break; 
                }  
            }
        }
    }
    
    
    
    cout << "\n\nFinding potential genes.... \n"; 
    cout << "Found " << numPotentialGenes << " potential genes, gene sequences are writing into "<< "NC_003988_genes2.fna " << "\n";
    
    fileHandler.close(); 
    fileHandler.open("NC_003988_rev_genes2.fna", ios::out);
    startCodone.clear(); 
    stopCodone.clear(); 

    spinMeRightRound = revGene(genomeSequence, revGenomeSeq);
    findCodons(startCodone, spinMeRightRound, "ATG");
    findCodons(stopCodone, spinMeRightRound, "TGA");
    findCodons(stopCodone, spinMeRightRound, "TAA"); 
    findCodons(stopCodone, spinMeRightRound, "TAG"); 
    selectGeneSort(stopCodone); 
    int numRevGenes = 0; 
    for(int i = 0; i < start; i++)
    {
        int startIndex = startCodone[i]; 
        
        for(int j = 0; j < stop; j++)
        {   
            int stopIndex = stopCodone[j] + 2; 
            if(startIndex < stopIndex)
            {
                int geneLength = stopIndex - (startIndex - 1); 
                
                if (geneLength > 6 && geneLength%3==0)
                {   
                    string potentialGenes = spinMeRightRound.substr(startIndex,geneLength); 
                    //write to file
                    fileHandler << ">Gene#" << i+1; 
                    fileHandler << " Start=" << startIndex << " Stop=" << stopIndex; 
                    fileHandler << " Length=" << geneLength << "\n";
                    fileHandler << potentialGenes << "\n"; 
                    numRevGenes++; 
                    break; 
                    // if (potentialGenes.size() >= 72)
                    // {
                    //     fileHandler << "\n"; 
                    // }
                    // numPotentialGenes++; 
                    // break; 
                }  
            }
        }
    }
    cout << "\nReversing genome sequence \n"; 
    cout << "Finding potential genes \n"; 

    cout << "\nFound " << numRevGenes << " potential genes, gene sequences are writing into "<< "NC_003988_rev_genes2.fna " << "\n";
    
   

    return 0; 
}
