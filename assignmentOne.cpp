#include <iostream>
#include <cstring>
#include <locale>
#include <fstream>
#include <string>
#include <streambuf>
#include <math.h>
using namespace std;


void check(string inputFile)
{

  //section for cleaning up data
  //removing string that aren't valid DNA sequences

}

void Calculations(string inputFile)
{
    //finding out the number of lines of DNA and number of letters
    int sum = 0;
    string line = "";
    int numLines = 0;

    ifstream fileDNA(inputFile);

    //filtering through the data to get number of elements
    //and the number of lines/ number of DNA strings
    if(fileDNA.is_open())
    {
      while(!fileDNA.eof())
      {
        getline(fileDNA, line);
        numLines++;
        int sum_s =+ (line.size() * line.size());
        for (int i = 0; i < line.size(); ++i)
        {
          sum++;
        }
      }
      fileDNA.close();
    }


    //computing the mean
    int mean = sum/numLines;

    //computing the variance
    double num1 = pow(line.size() - mean, 2);

    double numerator;
    double denominator = numLines;

    double variance = numerator/denominator;

    //computing the standard deviation
    double sd = sqrt(variance);

    string str((istreambuf_iterator<char>(fileDNA)), istreambuf_iterator<char>());


    int AA = 0;
    int AC = 0;
    int AT = 0;
    int AG = 0;

    int CA = 0;
    int CC = 0;
    int CT = 0;
    int CG = 0;

    int TA = 0;
    int TC = 0;
    int TT = 0;
    int TG = 0;

    int GA = 0;
    int GC = 0;
    int GT = 0;
    int GG = 0;

    for (int i = 0; i < str.size(); ++i)
    {
      int j = i + 1;


      //calculating probailities for A
      if (str[i] == 'A')
      {
        if (str[j] == 'A')
        {
          AA++;
        }
        if (str[j] == 'C')
        {
          AC++;
        }
        if (str[j] == 'T')
        {
          AT++;
        }
        if (str[j] == 'G')
        {
          AG++;
        }
      }




      //calculating probabilities for C
      if (str[i] == 'C')
      {
        if (str[j] == 'A')
        {
          CA++;
        }
        if (str[j] == 'C')
        {
          CC++;
        }
        if (str[j] == 'T')
        {
          CT++;
        }
        if (str[j] == 'G')
        {
          CG++;
        }
      }



      //calculating probabilities for T
      if (str[i] == 'T')
      {
        if (str[j] == 'A')
        {
          TA++;
        }
        if (str[j] == 'C')
        {
          TC++;
        }
        if (str[j] == 'T')
        {
          TT++;
        }
        if (str[j] == 'G')
        {
          TG++;
        }
      }




      //calculating probabilities for G
      if (str[i] == 'G')
      {
        if (str[j] == 'A')
        {
          GA++;
        }
        if (str[j] == 'C')
        {
          GC++;
        }
        if (str[j] == 'T')
        {
          GT++;
        }
        if (str[j] == 'G')
        {
          GG++;
        }
      }
    }


    string thousandStr = "";
    for (int i = 0; i <= 1000; ++i)
    {
      double a = ((double) rand() / (RAND_MAX));
      double b = ((double) rand() / (RAND_MAX));
      int d = 0;

      double c = sqrt(-2*log(a))*cos(2*M_PI*b);


      thousandStr += "\n";

    }
    //outputting final answers
    cout << "The Sum of the length of the DNA strings is: " << sum << endl;
    cout << "The Mean of the length of the DNA strings is: " << mean << endl;
    cout << "The Variance of the length of the DNA strings is: " << variance << endl;
    cout << "The Standard Devisation of the length of the DNA string is: " << sd << endl;
    cout << "Here is the relative probability of each nucleotide: " << endl;
    cout << "Here is the relative probability of each nucleotide bigram: " << endl;;

}



int main(int argc, char** argv)
{
  //allowing the user to input DNA sequences
  //& making those entries lowercase
  cout << "Hello, please input the name of the text file:" << endl;
  string var = " ";
  cin >> var;
  Calculations(var);

}
