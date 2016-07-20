#include<iostream>
#include <math.h>
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

  const macierz<int> abc(4,4,1);
  const macierz<int> bac(4,4,tab2);

 cout  <<  abc*abc;
//cout << abc.potega(2);

  char c;
  cin>>c;
  return 0;
}
