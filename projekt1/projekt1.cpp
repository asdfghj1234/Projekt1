// projekt1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "tablica.h"
#include "scalanie.h"
#define ROZMIAR 42343

using namespace std;

int main()
{
	int* tab = losujTablice<int>(ROZMIAR);
	//wyswietlTablice(tab, ROZMIAR);
	czyPosortowana(tab, ROZMIAR);
	cout << endl;
	sortowaniePrzezScalanie(tab, 0, ROZMIAR - 1, 0);
	//wyswietlTablice(tab, ROZMIAR);
	czyPosortowana(tab, ROZMIAR);
}
