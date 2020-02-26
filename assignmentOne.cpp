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
  //but we are assuming we are given clean data

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


    double aa = 0;
    double ac = 0;
    double at = 0;
    double ag = 0;

    double ca = 0;
    double cc = 0;
    double ct = 0;
    double cg = 0;

    double ta = 0;
    double tc = 0;
    double tt = 0;
    double tg = 0;

    double ga = 0;
    double gc = 0;
    double gt = 0;
    double gg = 0;

    double singleA = 0;
    double singleC = 0;
    double singleT = 0;
    double singleG = 0;
    double single = 4;

    for (int i = 0; i < str.size(); ++i)
    {
      int j = i + 1;


      //calculating probailities for A
      if (str[i] == 'A')
      {
        singleA++;
        if (str[j] == 'A')
        {
          aa++;
        }
        if (str[j] == 'C')
        {
          ac++;
        }
        if (str[j] == 'T')
        {
          at++;
        }
        if (str[j] == 'G')
        {
          ag++;
        }
      }




      //calculating probabilities for C
      if (str[i] == 'C')
      {
        singleC++;
        if (str[j] == 'A')
        {
          ca++;
        }
        if (str[j] == 'C')
        {
          cc++;
        }
        if (str[j] == 'T')
        {
          ct++;
        }
        if (str[j] == 'G')
        {
          cg++;
        }
      }



      //calculating probabilities for T
      if (str[i] == 'T')
      {
        singleT++;
        if (str[j] == 'A')
        {
          ta++;
        }
        if (str[j] == 'C')
        {
          tc++;
        }
        if (str[j] == 'T')
        {
          tt++;
        }
        if (str[j] == 'G')
        {
          tg++;
        }
      }




      //calculating probabilities for G
      if (str[i] == 'G')
      {
        singleG++;
        if (str[j] == 'A')
        {
          ga++;
        }
        if (str[j] == 'C')
        {
          gc++;
        }
        if (str[j] == 'T')
        {
          gt++;
        }
        if (str[j] == 'G')
        {
          gg++;
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
    cout << "A:    " << singleA/single << endl;

    cout << "C:    " << singleC/sum << endl;
    cout << "T:    " << singleT/sum << endl;
    cout << "G:    " << singleG/sum << endl;
    cout << " "      << endl;
    cout << "Here is the relative probability of each nucleotide bigram: " << endl;
    cout << "AA:   " << aa/sum << endl;
    cout << "AC:   " << ac/sum << endl;
    cout << "AT:   " << at/sum << endl;
    cout << "AG:   " << ag/sum << endl;

    cout << "CA:   " << ca/sum << endl;
    cout << "CC:   " << cc/sum << endl;
    cout << "CT:   " << ct/sum << endl;
    cout << "CG:   " << cg/sum << endl;

    cout << "TA:   " << ta/sum << endl;
    cout << "TC:   " << tc/sum << endl;
    cout << "TT:   " << tt/sum << endl;
    cout << "TG:   " << tg/sum << endl;

    cout << "GA:   " << ga/sum << endl;
    cout << "GC:   " << gc/sum << endl;
    cout << "GT:   " << gt/sum << endl;
    cout << "GG:   " << gg/sum << endl;

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
