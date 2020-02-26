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
    int singleA = 0;
    int singleC = 0;
    int singleT = 0;
    int singleG = 0;
    int aa = 0;
    int ac = 0;
    int at = 0;
    int ag = 0;

    int ca = 0;
    int cc = 0;
    int ct = 0;
    int cg = 0;

    int ta = 0;
    int tc = 0;
    int tt = 0;
    int tg = 0;

    int ga = 0;
    int gc = 0;
    int gt = 0;
    int gg = 0;

    //filtering through the data to get number of elements
    //and the number of lines/ number of DNA strings
    if(fileDNA.is_open())
    {
      while(!fileDNA.eof())
      {
        getline(fileDNA, line);
        numLines++;
        sum_s += (line.size() * line.size());
            for (int i = 0; i < line.size(); ++i)
            {
              int j = i + 1;
              sum++;


              //calculating probailities for A
              if (line[i] == 'A')
              {
                singleA++;
                if (line[j] == 'A')
                {
                  aa++;
                }
                if (line[j] == 'C')
                {
                  ac++;
                }
                if (line[j] == 'T')
                {
                  at++;
                }
                if (line[j] == 'G')
                {
                  ag++;
                }
              }




              //calculating probabilities for C
              if (line[i] == 'C')
              {
                singleC++;
                if (line[j] == 'A')
                {
                  ca++;
                }
                if (line[j] == 'C')
                {
                  cc++;
                }
                if (line[j] == 'T')
                {
                  ct++;
                }
                if (line[j] == 'G')
                {
                  cg++;
                }
              }



              //calculating probabilities for T
              if (line[i] == 'T')
              {
                singleT++;
                if (line[j] == 'A')
                {
                  ta++;
                }
                if (line[j] == 'C')
                {
                  tc++;
                }
                if (line[j] == 'T')
                {
                  tt++;
                }
                if (line[j] == 'G')
                {
                  tg++;
                }
              }




              //calculating probabilities for G
              if (line[i] == 'G')
              {
                singleG++;
                if (line[j] == 'A')
                {
                  ga++;
                }
                if (line[j] == 'C')
                {
                  gc++;
                }
                if (line[j] == 'T')
                {
                  gt++;
                }
                if (line[j] == 'G')
                {
                  gg++;
                }
              }
            }
          }

          sum++;
        }

      fileDNA.close();



    //computing the mean
    double mean = sum/numLines;

    //computing the variance
    double num1 = pow(line.size() - mean, 2);

    double numerator = sum_s - (2 * mean) + sum + (numLines * (mean * mean));
    double denominator = numLines;

    double variance = numerator/denominator;

    //computing the standard deviation
    double sd = sqrt(variance);





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
    cout << "A:    " << singleA/sum << endl;

    cout << "C:    " << singleC/sum << endl;
    cout << "T:    " << singleT/sum << endl;
    cout << "G:    " << singleG/sum << endl;
    cout << " "      << endl;
    cout << "Here is the relative probability of each nucleotide bigram: " << endl;
    cout << "AA:   " << aa/(sum/2) << endl;
    cout << "AC:   " << ac/(sum/2) << endl;
    cout << "AT:   " << at/(sum/2) << endl;
    cout << "AG:   " << ag/(sum/2) << endl;

    cout << "CA:   " << ca/(sum/2) << endl;
    cout << "CC:   " << cc/(sum/2) << endl;
    cout << "CT:   " << ct/(sum/2) << endl;
    cout << "CG:   " << cg/(sum/2) << endl;

    cout << "TA:   " << ta/(sum/2) << endl;
    cout << "TC:   " << tc/(sum/2) << endl;
    cout << "TT:   " << tt/(sum/2) << endl;
    cout << "TG:   " << tg/(sum/2) << endl;

    cout << "GA:   " << ga/(sum/2) << endl;
    cout << "GC:   " << gc/(sum/2) << endl;
    cout << "GT:   " << gt/(sum/2) << endl;
    cout << "GG:   " << gg/(sum/2) << endl;


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
