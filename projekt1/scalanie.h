#pragma once

template <class T>
void scalanie(T* tab, int p, int q, int r, int odwroc)
{
	int i = p, j = q + 1, k = 0;
	T* tab_pom = new T[r - p + 1];

	for (int l = 0; l < r - p + 1; ++l)
	{
		//jeœli A wyczerpany
		if (i > q && j <= r)
		{
			tab_pom[k] = tab[j];
			++j; ++k;
		}
		//jeœli ci¹g B wyczerpany
		if (j > r && i <= q)
		{
			tab_pom[k] = tab[i];
			++i; ++k;
		}
		//je¿eli nie s¹ wyczerpane
		if (i <= q && j <= r)
		{
			if (tab[i] <= tab[j])
			{
				if (!odwroc)
				{
					tab_pom[k] = tab[i];
					++i; ++k;
				}
				else
				{
					tab_pom[k] = tab[j];
					++j; ++k;
				}

			}
			else
			{
				if (!odwroc)
				{
					tab_pom[k] = tab[j];
					++j; ++k;
				}
				else
				{
					tab_pom[k] = tab[i];
					++i; ++k;
				}

			}
		}
	}
	//Przyrównaj tab do tab_pom
	k = 0;
	for (int l = p; l < r + 1; ++l)
	{
		tab[l] = tab_pom[k];
		++k;
	}

	delete[] tab_pom;
}

template <class T>
void sortowaniePrzezScalanie(T* tab, int p, int r, int odwroc)
{
	if (p < r)
	{
		int q = (p + r) / 2;
		sortowaniePrzezScalanie(tab, p, q, odwroc);
		sortowaniePrzezScalanie(tab, q + 1, r, odwroc);
		scalanie(tab, p, q, r, odwroc);
	}
}