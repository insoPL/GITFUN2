#include<iostream>

using namespace std;



class macierz
{
private:
  int** tab;
  int x,y;

public:
  macierz(int xx,int yy):x(xx),y(yy)
  {
    tab= new int*[y];
    for(int foo=0;foo<y;foo++)  tab[foo]=new int[x];
    cout<<"Podaj dane:\n";
    for(int foo=0;foo<y;foo++)
    {
      cout<<"linia: "<<foo+1<<endl;
      for(int bar=0;bar<x;bar++)
      {
        cin>>tab[foo][bar];
      }
      cout<<endl;
    }
  }

  int get(int x, int y) const {  return tab[y][x]; }
  int getX() const { return x; }
  int getY() const { return y; }

friend ostream& operator<<(std::ostream& stream, const macierz& maci);
};

ostream& operator<<(std::ostream& stream, const macierz& maci) {
  for(int foo=0;foo<maci.getY();foo++)
  {
    cout<<endl;
    for(int bar=0;bar<maci.getX();bar++)cout<<maci.get(bar,foo)<<" ";
  }
}

int main()
{
  macierz maci(3,2);
  cout<<maci;

  char c;
  cin>>c;
  return 0;
}
