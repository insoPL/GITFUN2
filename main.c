#include<iostream>

using namespace std;

class macierz{
private:
  int ** tab;
public:
  macierz(int x,int y){

    tab= new int*[y];
    for(int foo=0;foo<y;foo++)tab[y]=new int[x];

    cout<<"Podaj dane:\n";
    for(int foo=0;foo<y;foo++){
      cout<<"linia: "<<foo+1<<endl;
      for(int bar=0;bar<x;bar++)cin>>tab[y][x];
      cout<<endl;
    }

  }

};

int main(){

  cout<<"Hello world"<<endl;

  macierz maci(3,2);

  char c;
  cin>>c;
  return 0;
}
