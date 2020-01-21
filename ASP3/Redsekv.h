#pragma once
#include<iostream>
#include "Red.h"
using namespace std;
template<class T>
class RedSekv : public Red<T>
{
	int max_size = 2;
	T* niz = new T[max_size];
	int brojac = 0;
	int pocetak = 0;
	int kraj = 0;
public:

	void dodaj(T x)
	{
		if (jel_pun())
		{
			prosiri_niz();
		}
		niz[kraj] = x;
		kraj++;
		if (kraj == max_size)
		{
			kraj = 0;
		}
		brojac++;
	}

	T ukloni()
	{
		if (jel_prazan())
		{
			throw exception("niz je prazan");
		}
		brojac--;
		
		
		
		T novi = niz[pocetak];
		pocetak++;
		if (pocetak == max_size)
		{
			pocetak = 0;
		}
		return novi;
	}
	bool jel_prazan()
	{
		return brojac == 0;
	}
	bool jel_pun()
	{
		return brojac == max_size;
	}

	int get_brojac()
	{
		return brojac;
	}
	void print()
	{
		int temp = pocetak;
		for (int i = 0; i < brojac; i++)
		{

			cout << niz[temp] << " | ";
			temp++;
			if (temp == max_size)
			{
				temp = 0;
			}
		}
		cout << endl;
	}
	void prosiri_niz()
	{
		T* novi_niz = new T[max_size * 2];
		int j = pocetak;
		for (int i = 0; i < brojac; i++)
		{
			novi_niz[i] = niz[j++];
			if (j == max_size)
			{
				j = 0;
			}
		}
		pocetak = 0;
		kraj = brojac;
		max_size *= 2;
		delete[] niz;
		niz = novi_niz;
	}
};