#include <iostream>
#include <cstring>
#include <locale>
using namespace std;

int main(int argc, char** argv)
{
  //allowing the user to input DNA sequences
  //& making those entries lowercase
  string var = "";
  cout << "Hello, please input the name of the text file:" << endl;
  cin >> var;

  //giving a value to the length of the string and lowercasing it
  int length = var.size();
  for (int i = 0; i <= length; ++i)
  var[i] = tolower(var[i]);

  //computing the sum
  int sum = 0;
  for(int i = 0; i <= length - 1; ++i)
  {
    sum++;
  }

  //computing the mean



  //computing the variance


  //print statements with answers
  cout << "The Sum of the length of the DNA strings is: " << sum << endl;
  cout << "The Mean of the length of the DNA strings is: \n";
  cout << "The Variance of the length of the DNA strings is: \n";
  cout << "The Standard Devisation of the length of the DNA string is: \n";
  cout << "Here is the relative probability of each nucleotide: \n";
  cout << "Here is the relative probability of each nucleotide bigram: \n";

}
