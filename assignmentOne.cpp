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
    double sum = 0;
    string line = "";
    double numLines = 0;

    ifstream fileDNA(inputFile);
    double sum_s;

    //filtering through the data to get number of elements
    //and the number of lines/ number of DNA strings
    if(fileDNA.is_open())
    {
      while(!fileDNA.eof())
      {
        getline(fileDNA, line);
        numLines++;
        sum_s =+ (line.size() * line.size());
        for (int i = 0; i < line.size(); ++i)
        {
          sum++;
        }
      }
      fileDNA.close();
    }


    //computing the mean
    double mean = sum/numLines;

    //computing the variance
    double num1 = pow(line.size() - mean, 2);

    double numerator = sum_s - (2 * mean) + sum + (numLines * (mean * mean));
    double denominator = numLines;

    double variance = numerator/denominator;

    //computing the standard deviation
    double sd = sqrt(variance);

    string str((istreambuf_iterator<char>(fileDNA)), istreambuf_iterator<char>());


    double AA = 0;
    double AC = 0;
    double AT = 0;
    double AG = 0;

    double CA = 0;
    double CC = 0;
    double CT = 0;
    double CG = 0;

    double TA = 0;
    double TC = 0;
    double TT = 0;
    double TG = 0;

    double GA = 0;
    double GC = 0;
    double GT = 0;
    double GG = 0;

    double A = 0;
    double C = 0;
    double T = 0;
    double G = 0;

    for (int i = 0; i < str.size(); ++i)
    {
      int j = i + 1;


      //calculating probailities for A
      if (str[i] == 'A')
      {
        A++;
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
        C++;
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
        T++;
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
        G++;
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

      double c = sqrt(-2*log(a))*cos(2*M_PI*b);
      double d = (sd*c) + mean;


      thousandStr += "\n";

    }
    //outputting final answers
    cout << "The Sum of the length of the DNA strings is: " << sum << endl;
    cout << "The Mean of the length of the DNA strings is: " << mean << endl;
    cout << "The Variance of the length of the DNA strings is: " << variance << endl;
    cout << "The Standard Devisation of the length of the DNA string is: " << sd << endl;
    cout << "Here is the relative probability of each nucleotide:" << endl;
    cout << "" << endl;
    cout << "A:    " << A/sum << endl;

    cout << "C:    " << C/sum << endl;
    cout << "T:    " << T/sum << endl;
    cout << "G:    " << G/sum << endl;
    cout << " "      << endl;
    cout << "Here is the relative probability of each nucleotide bigram: " << endl;
    cout << "AA:   " << AA/sum << endl;
    cout << "AC:   " << AC/sum << endl;
    cout << "AT:   " << AT/sum << endl;
    cout << "AG:   " << AG/sum << endl;

    cout << "CA:   " << CA/sum << endl;
    cout << "CC:   " << CC/sum << endl;
    cout << "CT:   " << CT/sum << endl;
    cout << "CG:   " << CG/sum << endl;

    cout << "TA:   " << TA << endl;
    cout << "TC:   " << TC << endl;
    cout << "TT:   " << TT << endl;
    cout << "TG:   " << TG << endl;

    cout << "GA:   " << GA << endl;
    cout << "GC:   " << GC << endl;
    cout << "GT:   " << GT << endl;
    cout << "GG:   " << GG << endl;
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
