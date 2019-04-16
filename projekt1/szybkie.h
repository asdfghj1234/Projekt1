#pragma once
#include <iostream>
#include <ctime>

using namespace std;

template <class T>
void zamien(T* tab, int l, int r)
{
	T temp = tab[l];
	tab[l] = tab[r];
	tab[r] = temp;
}

int wybierzPunktPodzialu(int l, int r)
{
	srand((unsigned)time(0));
	int i = l + (rand() % (r - l + 1));
	return i;
}

template <class T>
int podzielTablice(T * tab, int l, int r, int odwroc)
{
	int indeksPodzialu = wybierzPunktPodzialu(l, r); //wybor elementu podzialu
	T wartoscPodzialu = tab[indeksPodzialu]; //zapamietanie wartosci podzialu
	zamien(tab, indeksPodzialu, r); //przeniesienie elementu podzialu na ostatnie miejsce tablicy

	int aktualnaPozycja = l;
	for (int i = l; i < r; ++i)
	{
		if (!odwroc)
		{
			//elementy mniejsze niz wartosc podzialu sa ustawiane od lewej strony
			if (tab[i] < wartoscPodzialu)
			{
				zamien(tab, i, aktualnaPozycja);
				++aktualnaPozycja;
			}
		}
		else
		{
			if (tab[i] > wartoscPodzialu)
			{
				zamien(tab, i, aktualnaPozycja);
				++aktualnaPozycja;
			}
		}
	}
	zamien(tab, aktualnaPozycja, r); //wstawianie elementu podzialu na wlasciwe miejsce
	return aktualnaPozycja;
}

template <class T>
void sortowanieSzybkie(T * tab, int l, int r, int odwroc)
{
	if (l < r)
	{
		int i = podzielTablice(tab, l, r, odwroc);
		sortowanieSzybkie(tab, l, i - 1, odwroc);
		sortowanieSzybkie(tab, i + 1, r, odwroc);
	}
}