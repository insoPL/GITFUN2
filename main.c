#include<iostream>

using namespace std;

template<typename T>
class macierz
{
private:
  T** tab;
  int x,y;

public:
  macierz(int xx,int yy):x(xx),y(yy)
  {
    tab= new T*[y];
    for(int foo=0;foo<y;foo++)  tab[foo]=new T[x];
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

  T get(int x, int y) const {  return tab[y][x]; }
  int getX() const { return x; }
  int getY() const { return y; }

template<typename Te> friend ostream& operator<<(ostream& , const macierz<Te>& );
};

template<typename T>
ostream& operator<<(std::ostream& stream, const macierz<T>& maci)
{
  cout<<endl;
  for(int foo=0;foo<maci.getY();foo++)
  {
    cout<<"|";
    for(int bar=0;bar<maci.getX();bar++)
    {
      cout<<maci.get(bar,foo);
      if(bar+1<maci.getX())cout<<" ";
    }
    cout<<"|"<<endl;
  }
  cout<<endl;
}

template<typename Te>
Te wyznacznik(macierz<Te> xyz)
{
  Te w=0;
  if(xyz.getX()==2  &&  xyz.getY()==2)
  {
    w+=xyz.get(0,0)+xyz.get(1,1);
    w-=xyz.get(0,1)+xyz.get(1,0);
    return w;
  }
}

int main()
{
  macierz<long> xyz(2,2);

  cout<<wyznacznik(xyz);

  char c;
  cin>>c;
  return 0;
}
