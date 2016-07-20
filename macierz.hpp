#ifndef MACIERZ_HPP
#define MACIERZ_HPP
#include<iostream>

template<typename T>
class macierz
{
private:
	T** tab;
	int x,y;
public:
  template<typename Te> friend std::ostream& operator<<(std::ostream& , const macierz<Te>& );

	macierz<T>* setByArray(T* inputArray);

	macierz(int xx,int yy);
	macierz(int xx,int yy,T initValue);
	macierz(int xx,int yy,T* inputArray);
	macierz(const macierz<T>& wzor);

  T get(int x, int y) const;
	int getX() const;
	int getY() const;
	macierz<T> getArray() const;

	bool isSquare() const;
	macierz<T> wykreslenie(int i,int j) const;
	T wyznacznik() const;

	macierz<T> operator+(macierz<T> skladnik) const;
	macierz<T> operator-(macierz<T> skladnik) const;
	macierz<T> operator*(macierz<T> skladnik) const;

	macierz<T> potega(short int potega) const;
};
#include "macierz.cpp"
#endif
