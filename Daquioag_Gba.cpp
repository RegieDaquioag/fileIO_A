// Name: Regie Daquioag
// Date: October 22, 2015
// Project: Files IO for GBA

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
	ifstream fin;
	ofstream foutResult;
	ofstream foutCapitalize;
	ofstream foutUpperCase;
	
	string strA, strB, strC, strD;
	
	double averageChar;
	double totalChar = 0;
	int totalWords = 0;
	int wordLen1 = 0;
	int wordLen2 = 0;
	int wordLen3 = 0;
	int wordLen4 = 0;
	int wordLen5 = 0;
	int wordLen6 = 0;
	int wordLen7 = 0;
	int wordLen8 = 0;
	int wordLen9 = 0;
	int wordLen10 = 0;
	int wordLen11More = 0;
	
	fin.open("gba.txt");
	foutResult.open("result.txt");
	foutCapitalize.open("capitalize.txt");
	foutUpperCase.open("uppercase.txt");

//---------------------------------------------------------------------------------------------------------	
// It checks if the files are valid or not

	if(fin.fail())
	{
		cout << "error opening input file" << endl;
		exit(1); // If invalid exits out of the program immediatley!!
	}
	
	if(foutResult.fail())
	{
		cout << "error opening output file" << endl;
		exit(1); // If invalid exits out of the program immediatley!!
	}
	
	if(foutCapitalize.fail())
	{
		cout << "error opening output file" << endl;
		exit(1); // If invalid exits out of the program immediatley!!
	}
	
	if(foutUpperCase.fail())
	{
		cout << "error opening output file" << endl;
		exit(1); // If invalid exits out of the program immediatley!!
	}
//---------------------------------------------------------------------------------------------------------
	
	while(fin >> strA) // I am putting the gba.txt into a string strA (file called gba.txt)
	{
	    totalWords++; // It counts the amount of words in the string strA (file called gba.txt)
		
		for(int ix = 0; ix < strA.length(); ix++)
		{
			if((strA[ix] >= 'A' && strA[ix] <= 'Z') || (strA[ix] >= 'a' && strA[ix] <= 'z') ||
				strA[ix] == '-')
			{
				totalChar++; // It counts the amount of characters in the string strA (file called gba.txt)
			}
		}
//---------------------------------------------------------------------------------------------------------
	    // I think this checks every word and it checks if they word has a length of 1-10 and more	    
		if(strA.length() == 1)
		{
			wordLen1++;
		}
		else if(strA.length() == 2)
		{
			wordLen2++;
		}
		else if(strA.length() == 3)
		{
			wordLen3++;
		}
		else if(strA.length() == 4)
		{
			wordLen4++;
		}
		else if(strA.length() == 5)
		{
			wordLen5++;
		}
		else if(strA.length() == 6)
		{
			wordLen6++;
		}
		else if(strA.length() == 7)
		{
			wordLen7++;
		}
		else if(strA.length() == 8)
		{
			wordLen8++;
		}
		else if(strA.length() == 9)
		{
			wordLen9++;
		}
		else if(strA.length() == 10)
		{
			wordLen10++;
		}
		else
		{
			wordLen11More++;
		}
//---------------------------------------------------------------------------------------------------------	
        strB += strA + " ";
		
		for (int ix = 0; ix < strB.length(); ix++)
		{
			if((strB[ix] >= 'A' && strB[ix] <= 'Z') || (strB[ix] >= 'a' && strB[ix] <= 'z'))
			{
				strB[ix] = toupper(strB[ix]);  // This will Capitalize each letter in the string (file called gba.txt)
			}
		}		
//---------------------------------------------------------------------------------------------------------
	    strC += strA + " ";
		
		for (int ix = 0; ix < strC.length(); ix++)
		{
			toupper(strC[0]);
			
			if (strC[ix - 1] == ' ') 
			{
				strC[ix] = toupper(strC[ix]); // This will check if there is a black space it will change the letter right after in into a capital letter
			}
		}
	}
//---------------------------------------------------------------------------------------------------------	
// The OUTPUT for each one put in their right result files        
    averageChar = totalChar / totalWords;
	foutResult << "\naverage characters per word: " << averageChar << endl;
	
	foutResult << wordLen1 << " words have the of length 1" << endl;
	foutResult << wordLen2 << " words have the of length 2" << endl;
	foutResult << wordLen3 << " words have the of length 3" << endl;
	foutResult << wordLen4 << " words have the of length 4" << endl;
	foutResult << wordLen5 << " words have the of length 5" << endl;
	foutResult << wordLen6 << " words have the of length 6" << endl;
	foutResult << wordLen7 << " words have the of length 7" << endl;
	foutResult << wordLen8 << " words have the of length 8" << endl;
	foutResult << wordLen9 << " words have the of length 9" << endl;
	foutResult << wordLen10 << " words have the of length 10" << endl;
	foutResult << wordLen11More << " words have the of length 11 or longer" << endl;
	foutResult << "The total number of words in this file is " << totalWords << "\n" << endl;
	
	foutCapitalize << "\n" << strB << "\n" << endl;	
	foutUpperCase << "\n" << strC << "\n" << endl;
//---------------------------------------------------------------------------------------------------------	    
        
    fin.close();
	foutResult.close();
	foutCapitalize.close();
	foutUpperCase.close();
	
    return 0;
}


