#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <random>

using namespace std;

int main(int argc, char** argv)
{

  // Prompt the user to enter the name of a file
  string fileName = "";
  cout << "Please Enter The Name Of A File: " << endl;
  cin >> fileName;

  //Open the text file
  ifstream inFile;
  inFile.open(fileName);

  // Check if the file does not open properly
  if(inFile.fail())
  {
    cerr << "Error Opening File" << endl;
    exit(1);
  }

  string dnaString;

  float sumOfDNA = 0.0;

  float count = 0.0;
  float meanLength = 0.0;

  float maxLength = 0.0;
  float tempMax = 0.0;
  float tempSum = 0.0;
  float variance = 0.0;
  float standardDeviation = 0.0;

  int numA = 0;
  int numC = 0;
  int numG = 0;
  int numT = 0;

  float probA = 0.0;
  float probC = 0.0;
  float probG = 0.0;
  float probT = 0.0;

  float probAA = 0.0;
  float probAC = 0.0;
  float probAT = 0.0;
  float probAG = 0.0;
  float probCA = 0.0;
  float probCC = 0.0;
  float probCT = 0.0;
  float probCG = 0.0;
  float probTA = 0.0;
  float probTC = 0.0;
  float probTT = 0.0;
  float probTG = 0.0;
  float probGA = 0.0;
  float probGC = 0.0;
  float probGT = 0.0;
  float probGG = 0.0;


  // Read in every value from the file until the end
  // eof --> end of file
  while(!inFile.eof())
  {
      inFile >> dnaString;

      tempMax = dnaString.length();

      if(tempMax > maxLength)
        maxLength = tempMax;

      sumOfDNA = sumOfDNA + dnaString.length();
      count++;

      meanLength = sumOfDNA / count;

      tempSum += pow((dnaString.length() - meanLength), 2);


      for(int i = 0; i < dnaString.length(); ++i)
      {

        if(dnaString[i] == 'A')
        {
          numA++;
        }

        else if(dnaString[i] == 'C')
        {
          numC++;
        }

        else if(dnaString[i] == 'G')
        {
          numG++;
        }

        else if(dnaString[i] == 'T')
        {
          numT++;
        }

      }

  }

  probA = numA / sumOfDNA;
  probC = numC / sumOfDNA;
  probG = numG / sumOfDNA;
  probT = numT / sumOfDNA;

  probAA = probA * probA;
  probAC = probA * probC;
  probAT = probA * probT;
  probAG = probA * probG;

  probCA = probC * probA;
  probCC = probC * probC;
  probCT = probC * probT;
  probCG = probC * probG;

  probTA = probT * probA;
  probTC = probT * probC;
  probTT = probT * probT;
  probTG = probT * probG;

  probGA = probG * probA;
  probGC = probG * probC;
  probGT = probG * probT;
  probGG = probG * probG;

  variance = tempSum / count - 1;
  variance = variance * -1;

  standardDeviation = sqrt(variance);

  ofstream outputFile;
  outputFile.open("jeremyanderson.txt");

  outputFile << "Jeremy Anderson" << endl;
  outputFile << "Student ID: 2314466" << endl;
  outputFile << "" << endl;
  outputFile << "" << endl;
  outputFile << "The Sum Of The Length Of The DNA Strings Is: " << sumOfDNA << endl;
  outputFile << "The Mean Length Of The DNA Strings Is: " << meanLength << endl;
  outputFile << "The Variance Of The Length Of The DNA Strings Is: " << variance << endl;
  outputFile << "The Standard Deviation Of The Length Of The DNA Strings Is: " << standardDeviation << endl;
  outputFile << "" << endl;
  outputFile << "Relative Probability of A: " << probA << endl;
  outputFile << "Relative Probability of C: " << probC << endl;
  outputFile << "Relative Probability of G: " << probG << endl;
  outputFile << "Relative Probability of T: " << probT << endl;
  outputFile << "" << endl;
  outputFile << "Relative Probability of AA: " << probAA << endl;
  outputFile << "Relative Probability of AC: " << probAC << endl;
  outputFile << "Relative Probability of AT: " << probAT << endl;
  outputFile << "Relative Probability of AG: " << probAG << endl;
  outputFile << "Relative Probability of CA: " << probCA << endl;
  outputFile << "Relative Probability of CC: " << probCC << endl;
  outputFile << "Relative Probability of CT: " << probCT << endl;
  outputFile << "Relative Probability of CG: " << probCG << endl;
  outputFile << "Relative Probability of TA: " << probTA << endl;
  outputFile << "Relative Probability of TC: " << probTC << endl;
  outputFile << "Relative Probability of TT: " << probTT << endl;
  outputFile << "Relative Probability of TG: " << probTG << endl;
  outputFile << "Relative Probability of GA: " << probGA << endl;
  outputFile << "Relative Probability of GC: " << probGC << endl;
  outputFile << "Relative Probability of GT: " << probGT << endl;
  outputFile << "Relative Probability of GG: " << probGG << endl;

  int nucA = 0;
  int nucC = 0;
  int nucG = 0;
  int nucT = 0;


  outputFile << "" << endl;
  outputFile << "1000 DNA Strings Based On Calculated Statistics: " << endl;
  outputFile << "" << endl;

  string generatedDNAString = "";

  for(int i = 0; i < 1000; ++i)
  {
      float a = (float) rand() / RAND_MAX;
      float b = (float) rand() / RAND_MAX;
      float c = sqrt(-2 * log(a)) * cos(2 * M_PI * b);
      int d = standardDeviation * c + meanLength;

      nucA = numA / sumOfDNA * d;
      nucC = numC / sumOfDNA * d;
      nucG = numG / sumOfDNA * d;
      nucT = numT / sumOfDNA * d;

      for(int j = 0; j < nucA; j++)
      {
        generatedDNAString += 'A';
      }

      for(int j = 0; j < nucC; j++)
      {
        generatedDNAString += 'C';
      }

      for(int j = 0; j < nucG; j++)
      {
        generatedDNAString += 'G';
      }

      for(int j = 0; j < nucT; j++)
      {
        generatedDNAString += 'T';
      }
      outputFile << generatedDNAString << endl;

      generatedDNAString = "";

  }

  outputFile << generatedDNAString << endl;

  // close the file
  inFile.close();
  outputFile.close();

  return 0;

}
