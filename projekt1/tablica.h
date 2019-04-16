#pragma once

#include <iostream>
#include <ctime>

using namespace std;

template <class T>
T* losujTablice(int rozmiar)
{
	T* tab = new T[rozmiar];
	srand((unsigned)time(0));
	for (int i = 0; i < rozmiar; ++i)
	{
		tab[i] = rand() % 100;
	}
	return tab;
}

template <class T>
void wyswietlTablice(T* tab, int rozmiar)
{
	for (int i = 0; i < rozmiar; ++i)
	{
		cout << tab[i] << " ";
	}
}

template <class T>
void czyPosortowana(T* tab, int rozmiar)
{
	int n = 1, k = 1;
	for (int i = 0; i < rozmiar - 1; ++i)
	{
		if (tab[i] <= tab[i + 1]) ++n;
		if (tab[i] >= tab[i + 1]) ++k;
	}
	if (n == rozmiar) cout << endl << "Tablica posortowana rosnaco." << endl;
	if (k == rozmiar) cout << endl << "Tablica posortowana malejaco." << endl;
	if (n != rozmiar && k != rozmiar) cout << endl << "Tablica nieposortowana." << endl;
}