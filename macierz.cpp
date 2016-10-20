#include<iostream>
#include<sStream>
#include<math.h>

#ifdef MACIERZ_HPP

template<typename T>
class macierz;


template<typename T>
T** create2D(int xx,int yy)
{
  T** Array= new T*[yy];
  for(int foo=0;foo<yy;foo++)  Array[foo]=new T[xx];
  return Array;
}


template<typename T>
macierz<T>* macierz<T>::setByArray(T* inputArray)
{
  int it=0;
  for(int foo=0;foo<y;foo++)
  {
    for(int bar=0;bar<x;bar++)
    {
      tab[foo][bar]=inputArray[it++];
    }
  }
  return this;
}

template<typename T>
macierz<T>::macierz(int xx,int yy):x(xx),y(yy)
{
	tab = create2D<T>(x,y);

	for(int foo=0;foo<y;foo++)
	{
		std::cout<<"linia: "<<foo+1<<std::endl;
		for(int bar=0;bar<x;bar++)
		{
			std::cin>>tab[foo][bar];
		}
		std::cout<<std::endl;
	}
}

template<typename T>
macierz<T>::macierz(int xx,int yy,T* inputArray):x(xx),y(yy)
{
	tab= create2D<T>(getX(),getY());
	setByArray(inputArray);
}

template<typename T>
macierz<T>::macierz(int xx,int yy,T initValue):x(xx),y(yy)
{
	tab= create2D<T>(getX(),getY());

	for(int foo=0;foo<y;foo++)
	{
		for(int bar=0;bar<x;bar++)
		{
			tab[foo][bar]=initValue;
		}
	}
}

template<typename T>
macierz<T>::macierz(const macierz<T>& wzor):x(wzor.getX()),y(wzor.getY())
{
	tab=create2D<T>(x,y);

	for(int foo=0;foo<y;foo++)
	{
		for(int bar=0;bar<x;bar++)
		{
			tab[foo][bar]=wzor.get(foo,bar);
		}
	}
}
template<typename T>
macierz<T>::~macierz(){
  for(int foo=0;foo<y;foo++)
  {
      delete tab[foo];
  }
  delete tab;
std::cout << "I become death destroyer of the world" << std::endl;
}

template<typename T>
T macierz<T>::get(int x, int y) const {  return tab[y][x]; }

template<typename T>
int macierz<T>::getX() const { return x; }

template<typename T>
int macierz<T>::getY() const { return y; }

template<typename T>
macierz<T> macierz<T>::getArray() const
{
  T* ArrayW;

  int it=0;
  for(int foo=0;foo<y;foo++)
  {
    for(int bar=0;bar<x;bar++)
    {
      ArrayW[it++]=tab[foo][bar];
    }
  }
  return ArrayW;
}

template<typename T>
bool macierz<T>::isSquare() const
{
  if(getX()==getY()) return getX();
  else return 0;
}

template<typename T>
macierz<T> macierz<T>::operator+(macierz<T> skladnik) const
{
  if(getX() !=  skladnik.getX()  ||  getY()  !=  skladnik.getY())
  {
    std::cerr << "B³¹d dodawania macierzy - Macierze nie s¹ tej samej wielkoœci" << std::endl;
  }

  T* tabW=new T[getX()*getY()];

  int it=0;
  for(int foo=0;foo<y;foo++)
  {
    for(int bar=0;bar<x;bar++)
    {
      tabW[it++]=tab[foo][bar]+skladnik.get(bar,foo);
    }
  }
  macierz<T> w(getX(),getY(),tabW);
  return w;
}

template<typename T>
macierz<T> macierz<T>::operator-(macierz<T> skladnik) const
{
  if(getX() !=  skladnik.getX()  ||  getY()  !=  skladnik.getY())
  {
    std::cerr << "B³¹d odejmowania macierzy - Macierze nie s¹ tej samej wielkoœci" << std::endl;
  }

  T* tabW=new T[getX()*getY()];

  int it=0;
  for(int foo=0;foo<getY();foo++)
  {
    for(int bar=0;bar<getX();bar++)
    {
      tabW[it++]=tab[foo][bar]-skladnik.get(bar,foo);
    }
  }
  macierz<T> w(getX(),getY(),tabW);
  return w;
}

template<typename T>
macierz<T> macierz<T>::operator*(macierz<T> skladnik) const
{

  if(getX() !=  skladnik.getY())
  {
    std::cerr << "Blad mnozenia macierzy - Bledny rozmiar" << std::endl;
  }

  T* tabW=new T[getX()*skladnik.getY()];
  int it=0;
  for(int foo=0;foo<y;foo++)
  {
    for(int bar=0;bar<x;bar++)
    {
      T suma=0;

      for(int loop=0;loop<getX();loop++)
      {
        suma+=get(loop,foo)*skladnik.get(bar,loop);
      }

      tabW[it++]=suma;
    }
  }

  macierz<T> w(getX(),skladnik.getY(),tabW);
  return w;
}

template<typename T>
macierz<T> macierz<T>::potega(short int potega)  const
{
  if(potega>0){
    macierz<T> w(operator*(*this));
    return w;
  }
}

template<typename T>
macierz<T> macierz<T>::wykreslenie(int i,int j) const
{
  T* initArray=new T[(this->getX()-1)*(this->getY()-1)];
  int it=0;

    for(int foo=0;foo<this->getY();foo++)
    {
      for(int bar=0;bar<this->getX();bar++)
      {
        if(foo!=j &&  bar!=i) initArray[it++]=this->tab[foo][bar];
      }
    }

  macierz<T> w(this->getX()-1,this->getY()-1,initArray);

    return w;
}

template<typename T>
T macierz<T>::wyznacznik() const
{
  if(!isSquare())std::cerr << "/* Proba liczenia wyznacznika macierzy nie kwadratowej */" << std::endl;

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
  else
  {// Rozwiniêcie Laplaca
    for(int rzad=0;rzad<this->getX();rzad++)
    {
      w+=this->get(rzad,0)*pow(-1,rzad)*(this->wykreslenie(rzad,0)).wyznacznik();
    }
  return w;
  }
}

template<typename T>
std::ostream& operator<<(std::ostream& stream, const macierz<T>& maci)
{
  std::cout<<std::endl;
  for(int foo=0;foo<maci.getY();foo++)
  {
    std::cout<<"|";
    for(int bar=0;bar<maci.getX();bar++)
    {
      std::cout<<maci.get(bar,foo);
      if(bar+1<maci.getX())std::cout<<" ";
    }
    std::cout<<"|"<<std::endl;
  }
  std::cout<<std::endl;
}

template<typename T>
std::istream& operator>>(std::istream& stream, const macierz<T>& maci)
{
  for(int foo=0;foo<maci.getY;foo++)
  {
    std::cout<<"linia: "<<foo+1<<std::endl;
    for(int bar=0;bar<maci.getX();bar++)
    {
      std::cin>>maci.get(bar,foo);
    }
    std::cout<<std::endl;
  }
}


template<typename T>
std::string macierz<T>::toString() const
{
  std::stringstream str;
  str<<"| ";
  for(int foo=0;foo<getY();foo++)
  {
    for(int bar=0;bar<getX();bar++)
    {
      str<<get(bar,foo);
      if(bar+1<getX())str<<" ";
    }
    str<<" | ";
  }
  return str.str();
}

template<>
void macierz<int>::fromString(std::string input)
{
  std::stringstream str(input);
  std::string tym;
  str>>tym;
  if(!tym.compare("|")==0) return;

  unsigned int foo=0,bar=0;
  while(true)
  {
    bar=0;
    while(true)
    {
      str>>tym;
      if(str.eof())return;
      if(tym.compare("|")==0) break;
      else {
        tab[foo][bar]=atoi(tym.c_str());
      }
      bar++;
    }
    foo++;
    std::cout<<std::endl;
  }
}
#endif
