#include "reader.h"
#include<cmath>
#include <exception> 
#include <stdlib.h>
//constructor class
Reader::Reader() {

	//Nucleotides
	nucA = 0;
	nucT = 0;
	nucC = 0;
	nucG = 0;
	//A_ Bigrams
	bigramAA = 0;
	bigramAC = 0;
	bigramAT = 0;
	bigramAG = 0;
	//T_ Bigrams
	bigramTA = 0;
	bigramTC = 0;
	bigramTT = 0;
	bigramTG = 0;
	//C_ Bigrams
	bigramCA = 0;
	bigramCC = 0;
	bigramCT = 0;
	bigramCG = 0;
	//G_ Bigrams
	bigramGA = 0;
	bigramGC = 0;
	bigramGT = 0;
	bigramGG = 0;
	//File Reading Vars
	lengthDNA = 0;
	lineNum = 0;
	charCounter = 0;
	line = " ";
	c = ' ';
	prev = ' ';
	bigram = false;
	totalChar = 0;
	//Mathmatical Vars
	sum = 0;
	mean = 0;
	varience = 0;
	strLengthMinusMean = 0;
	stDeviation = 0;
	amountA = 0;
	amountT = 0;
	amountC = 0;
	amountG = 0;

	outputLineLength = 0;
	randInt = 0;
	charHolder = ' ';

	//Probabilities
	//Nucleotides
	probA = 0;
	probT = 0;
	probC = 0;
	probG = 0;
	//BigramsA_
	probAA = 0;
	probAT = 0;
	probAC = 0;
	probAG = 0;
	//BigramsT_
	probTA = 0;
	probTT = 0;
	probTC = 0;
	probTG = 0;
	//BigramsC_
	probCA = 0;
	probCT = 0;
	probCG = 0;
	probCC = 0;
	//BigramsG_
	probGA = 0;
	probGT = 0;
	probGC = 0;
	probGG = 0;

	first = true;
	
}
//destructor
Reader::~Reader() {

}
//reads in the desired file
void Reader::read(std::string& path) {
	try {
		//creates stream to read file
		std::ifstream fileStream(path);
		//error checking for if stream was opened
		if (!fileStream.is_open()) {
			std::cout << "Error opening file. Check the name of the file or check that it exists."<<std::endl;
			//obtained from https://mathbits.com/MathBits/CompSci/looping/end.htm
			//stopps program
			exit(1);
		}
	
		//obtained from: https://stackoverflow.com/questions/2390912/checking-for-an-empty-file-in-c
		//checking if file is empty
		if (fileStream.peek() == std::ifstream::traits_type::eof()) {
			std::cout << "The file is empty." << std::endl;
			fileStream.close();
			return;
		}
		if (fileStream.good()) {
			//going through each char and making sure it is a nucleotide
			while (getline(fileStream, line)) {
				++lineNum;
				for (char& c : line) {
					if (c == 'A' || c == 'a') {
						++sum;
						++totalChar;
						++nucA;
						//checks for bigrams with prev as comparison
						if (bigram) {
							if (prev == 'A' || prev == 'a') {
								++bigramAA;
							}
							else if (prev == 'T' || prev == 't') {
								++bigramTA;
							}
							else if (prev == 'C' || prev == 'c') {
								++bigramCA;
							}
							else if (prev == 'G' || prev == 'g') {
								++bigramGA;
							}
							//used to see if two chars have been iterated through or one, like a switch to tell
							bigram = false;
						}
						else {
							//sets up for the next loop
							prev = c;
							bigram = true;
						}

					}
					else if (c == 'T' || c == 't') {
						++sum;
						++totalChar;
						++nucT;
						//checks for bigrams with prev as comparison
						if (bigram) {
							if (prev == 'A' || prev == 'a') {
								++bigramAT;
							}
							else if (prev == 'T' || prev == 't') {
								++bigramTT;
							}
							else if (prev == 'C' || prev == 'c') {
								++bigramCT;
							}
							else if (prev == 'G' || prev == 'g') {
								++bigramGT;
							}
							//used to see if two chars have been iterated through or one, like a switch to tell
							bigram = false;
						}
						else {
							//sets up for next loop
							prev = c;
							bigram = true;
						}

					}
					else if (c == 'C' || c == 'c') {
						++sum;
						++totalChar;
						++nucC;
						//checks for bigram in file
						if (bigram) {
							if (prev == 'A' || prev == 'a') {
								++bigramAC;
							}
							else if (prev == 'T' || prev == 't') {
								++bigramTC;
							}
							else if (prev == 'C' || prev == 'c') {
								++bigramCC;
							}
							else if (prev == 'G' || prev == 'g') {
								++bigramGC;
							}
							//used to see if two chars have been iterated through or one, like a switch to tell
							bigram = false;
						}
						else {
							//sets up for next loop
							prev = c;
							bigram = true;
						}

					}
					else if (c == 'G' || c == 'g') {
						++sum;
						++totalChar;
						++nucG;
						//checks for G bigram
						if (bigram) {
							if (prev == 'A' || prev == 'a') {
								++bigramAG;
							}
							else if (prev == 'T' || prev == 't') {
								++bigramTG;
							}
							else if (prev == 'C' || prev == 'c') {
								++bigramCG;
							}
							else if (prev == 'G' || prev == 'g') {
								++bigramGG;
							}
							//used to see if two chars have been iterated through or one, like a switch to tell
							bigram = false;
						}
						else {
							//for next loop
							prev = c;
							bigram = true;
						}

					}
				}
			}
		}
		//error checking
		else {
		std::cout << "file stream is not good. Check that the path and/or name is correct" << std::endl;
		exit(1);
		}
		fileStream.close();
		return;
	}	
	//catch obtained from: https://en.cppreference.com/w/cpp/language/throw
	catch (const std::exception & e) {
		std::cout << e.what() << '\n';
		//reiterates error, need throw to end
		throw;
	}

}
//basic math calcs
bool Reader::calculations(std::string& path) {
	//creates stream
	std::ifstream fileStream(path);
	//error checking for file
	if (!fileStream.is_open()) {
		std::cout << "File Stream is not open. " << std::endl;
		//NEED A FILE STREAM CLOSE?
		return false;
	}

	
	//mean calculation
	mean = (sum / lineNum);


	//varience calculation
	//checks if the file is not empty and the risk flags
	if (fileStream.good()) {
		//gets each line in the file
		while (getline(fileStream, line)) {
			//goes through the chars in the line
			for (char& c : line) {
				//checks is the char is a nucleotide
				if (c == 'A' || c == 'a' || c == 'T' || c == 't' ||
					c == 'C' || c == 'c' || c == 'G' || c == 'g') {
					//increments the char in the line
					++charCounter;
					
				}
				//sum of line chars minus the mean
				strLengthMinusMean += (pow((charCounter - mean), 2));
				//resets the char counter for the next line
				charCounter = 0;
			}
		}
	}

	//varience equation cont.
	varience = strLengthMinusMean / (lineNum);
	//close file stream
	fileStream.close();
	//Standard Deviation Calculation
	stDeviation = pow(varience, .5);
	
	//probabilities
	probA = (int)((nucA / totalChar) * 100);
	probT = (int)((nucT / totalChar) * 100);
	probC = (int)((nucC / totalChar) * 100);
	probG = (int)((nucG / totalChar) * 100);
	//BigramsA_
	probAA = (int)((bigramAA / (totalChar/2))* 100);
	probAT = (int)((bigramAT / (totalChar/2)) * 100);
	probAC = (int)((bigramAC / (totalChar/2)) * 100);
	probAG = (int)((bigramAG / (totalChar/2)) * 100);
	//BigramsT_
	probTA = (int)((bigramTA / (totalChar/2)) * 100);
	probTT = (int)((bigramTT / (totalChar/2)) * 100);
	probTC = (int)((bigramTC / (totalChar/2)) * 100);
	probTG = (int)((bigramTG / (totalChar/2)) * 100);
	//BigramsC_
	probCA = (int)((bigramCA / (totalChar/2)) * 100);
	probCT = (int)((bigramCT / (totalChar/2)) * 100);
	probCC = (int)((bigramCC / (totalChar/2)) * 100);
	probCG = (int)((bigramCG / (totalChar/2)) * 100);
	//BigramsG_
	probGA = (int)((bigramGA / (totalChar / 2)) * 100);
	probGT = (int)((bigramGT / (totalChar / 2)) * 100);
	probGC = (int)((bigramGC / (totalChar / 2)) * 100);
	probGG = (int)((bigramGG / (totalChar / 2)) * 100);

	return true;
}
//calculates the distribution
int Reader::distribution() {
	//gausian distribution
	double a = (double)(rand() / (RAND_MAX + 1.0));
	double b = (double)(rand() / (RAND_MAX + 1.0));
	//used http://www.cplusplus.com/reference/cmath/log/ & https://stackoverflow.com/questions/1727881/how-to-use-the-pi-constant-in-c
	double c = sqrt(-2 * log(a)) * cos(2 * M_PI * b);
	int d = (int)(stDeviation * c + mean);
	return d;
}
//outputs to esired file
void Reader::output() {
	//Creates File
	std::ofstream output("JeevanAcharya.out");
	//Student Info
	output << "Jeevan Acharya" << "\r\n";
	output << "2313321" << "\r\n";
	output << "acharya@chapman.edu" << "\r\n";

	//Output
	output << "\r\n";
	output << "-----------Math Equations-----------" << "\r\n";
	output << "Sum: " << sum << "\r\n";
	output << "Mean: " << mean << "\r\n";
	output << "Varience: " << varience << "\r\n";
	output << "Standard Deviation: " << stDeviation << "\r\n";
	output << "\r\n";
	output << "-----------Probabilities------------" << "\r\n";
	output << "\r\n";
	output << "Probability of: " << "\r\n";
	output << "A: " << probA << "%" << "\r\n";
	output << "T: " << probT << "%" << "\r\n";
	output << "C: " << probC << "%" << "\r\n";
	output << "G: " << probG << "%" << "\r\n";
	
	output << "\r\n";
	output << "Breakdown of A_ Bigrams: " << "\r\n";
	output << "AA: " << probAA << "%" << "\r\n";
	output << "AT: " << probAT << "%" << "\r\n";
	output << "AC: " << probAC << "%" << "\r\n";
	output << "AG: " << probAG << "%" << "\r\n";

	output << "\r\n";
	output << "Breakdown of T_ Bigrams: " << "\r\n";
	output << "TA: " << probTA << "%" << "\r\n";
	output << "TT: " << probTT << "%" << "\r\n";
	output << "TC: " << probTC << "%" << "\r\n";
	output << "TG: " << probTG << "%" << "\r\n";

	output << "\r\n";
	output << "Breakdown of C_ Bigrams: " << "\r\n";
	output << "CA: " << probCA << "%" << "\r\n";
	output << "CT: " << probCT << "%" << "\r\n";
	output << "CC: " << probCC << "%" << "\r\n";
	output << "CG: " << probCG << "%" << "\r\n";

	output << "\r\n";
	output << "Breakdown of G_ Bigrams: " << "\r\n";
	output << "GA: " << probGA << "%" << "\r\n";
	output << "GT: " << probGT << "%" << "\r\n";
	output << "GC: " << probGC << "%" << "\r\n";
	output << "GG: " << probGG << "%" << "\r\n";

	outputLineLength = distribution();
	//finds amount for nucleotides
	amountA = (int)(outputLineLength * (nucA / totalChar));
	amountT = (int)(outputLineLength * (nucT / totalChar));
	amountG = (int)(outputLineLength * (nucG / totalChar));
	amountC = (int)(outputLineLength * (nucC / totalChar));
	std::cout << distribution() << std::endl;
	std::cout << outputLineLength << std::endl;
	//created to be outside of for loop
	
	//1000 elements in the created stand
	for (int i; i < 1000; ++i) {
		//while distribution created is 0, goes until we get one we should use
		while (outputLineLength <= 0) {
			outputLineLength = distribution();
		}
		//**used to print nucleotides in dna strand however it is for some reason not printng, I have been stuck here for a while and can't find a solution :(
		if(amountA > 0 || amountT > 0 || amountC > 0 || amountG > 0) {
			//randomly creates nums so that the dna strand is not just AAAAGGGTTTCCC ect.
			//obtained from https://stackoverflow.com/questions/12580820/random-number-between-1-to-10-using-c
			//random nums 0-3 used to print nucleotides
			randInt = rand() % 4;
			while (randInt = 0) {
				randInt = rand() % 4;
			}
			//outputs char
			switch (randInt) {
			case 0:
				output << "A";
				--amountA;
				break;
			case 1:
				output << "T";
				--amountT;
				break;
			case 2:
				output << "C";
				--amountC;
				break;
			case 3:
				output << "G";
				--amountG;
				break;
			default:
				std::cout << "ERROR Unkown randInt generated" << std::endl;
				output << "E";
			}
			--outputLineLength;
			if (outputLineLength == 0) {
				output << "\r\n";
			}
		}		

	}
	output.close();



}
void Reader::reset() {
	//resets values
	//Nucleotides
	nucA = 0;
	nucT = 0;
	nucC = 0;
	nucG = 0;
	//A_ Bigrams
	bigramAA = 0;
	bigramAC = 0;
	bigramAT = 0;
	bigramAG = 0;
	//T_ Bigrams
	bigramTA = 0;
	bigramTC = 0;
	bigramTT = 0;
	bigramTG = 0;
	//C_ Bigrams
	bigramCA = 0;
	bigramCC = 0;
	bigramCT = 0;
	bigramCG = 0;
	//G_ Bigrams
	bigramGA = 0;
	bigramGC = 0;
	bigramGT = 0;
	bigramGG = 0;
	//File Reading Vars
	lengthDNA = 0;
	lineNum = 0;
	line = " ";
	c = ' ';
	prev = ' ';
	bigram = false;
	charCounter = 0;
	totalChar = 0;
	//Mathmatical Vars
	sum = 0;
	mean = 0;
	varience = 0;
	strLengthMinusMean = 0;
	stDeviation = 0;
	//Output String Vars
	amountA = 0;
	amountT = 0;
	amountC = 0;
	amountG = 0;

	outputLineLength = 0;
	randInt = 0;
	charHolder = ' ';

	//Probabilities
	//Nucleotides
	probA = 0;
	probT = 0;
	probC = 0;
	probG = 0;
	//BigramsA_
	probAA = 0;
	probAT = 0;
	probAC = 0;
	probAG = 0;
	//BigramsT_
	probTA = 0;
	probTT = 0;
	probTC = 0;
	probTG = 0;
	//BigramsC_
	probCA = 0;
	probCT = 0;
	probCG = 0;
	probCC = 0;
	//BigramsG_
	probGA = 0;
	probGT = 0;
	probGC = 0;
	probGG = 0;

	first = true;
	
}