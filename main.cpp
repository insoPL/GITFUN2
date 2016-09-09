#include<iostream>
#include <math.h>
#include <cstdlib>
#include "macierz.hpp"

using namespace std;


int main()
{
  ///macierzkw<long> xyz(3);
  int tab1[]={1,2,3,4,
              1,2,3,4,
              1,2,3,4,
              1,2,3,4};


  int tab2[]={7,2,3,4,
              1,2,3,4,
              1,2,3,4,
              1,2,3,4};

  macierz<int> abc(4,4,1);
  macierz<int> bac(4,4,tab2);

 cout  <<  bac;
//cout << abc.potega(2);
//cout<< bac.toString();
abc.fromString(bac.toString());
cout << bac;

  char c;
  cin>>c;
  return 0;
}
