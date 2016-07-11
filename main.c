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
    for(int foo=0;foo<y;foo++)  tab[foo]=new T[x];//creating 2D array

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

  macierz(int xx,int yy,T* inputArray):x(xx),y(yy){
    tab= new T*[y];
    for(int foo=0;foo<y;foo++)  tab[foo]=new T[x];//creating 2D array

    int it=0;
    for(int foo=0;foo<y;foo++)
    {
      for(int bar=0;bar<x;bar++)
      {
        tab[foo][bar]=inputArray[it++];
      }
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

template<typename T>
class macierzkw
  : public macierz<T>
{
public:
  macierzkw(int x):macierz<T>(x,x){}
  macierzkw(int x,T* tabl):macierz<T>(x,x,tabl){}

  T wyznacznik() const
  {
    T w=0;
    if(this->getX()==2)
    {
      w=this->get(0,0)*this->get(1,1);
      w-=this->get(0,1)*this->get(1,0);
      return w;
    }
    else if(this->getX()==3)//  Metoda Sarrusa
    {
      w=this->get(0,0)*this->get(1,1)*this->get(2,2);
      w+=this->get(1,0)*this->get(2,1)*this->get(0,2);
      w+=this->get(0,1)*this->get(1,2)*this->get(2,0);

      w-=this->get(0,2)*this->get(1,1)*this->get(2,0);
      w-=this->get(0,1)*this->get(1,0)*this->get(2,2);
      w-=this->get(2,1)*this->get(1,2)*this->get(0,0);

      return w;
    }
    //else if()
  }
};

int main()
{
  //macierzkw<long> xyz(3);
  int tab[]={1,2,1,2};
  macierzkw<int> abc(2,tab);


  cout<<abc.wyznacznik();

  char c;
  cin>>c;
  return 0;
}
