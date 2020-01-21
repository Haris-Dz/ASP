#pragma once
#include<iostream>
#include "Lista.h"
using namespace std;
template<class T >
class ListaSekv : public Lista<T>
{
	int max_size = 2;
	T *niz = new T[max_size];
	int brojac = 0;
public:
	void dodaj_na_pocetak(T x)
	{
		if (jel_puna())
		{
			prosiri_niz();
		}
		for (int i = brojac; i > 0 ; i--)
		{
			niz[i] = niz[i - 1];
		}
		niz[0] = x;
		brojac++;
		
	}
	void dodaj_na_kraj(T x)
	{
		if (jel_puna())
		{
			prosiri_niz();
		}
		niz[brojac] = x;
		brojac++;
	}
	T ukloni_s_pocetka()
	{
		T poc = niz[0];
		for (int i = 1; i < brojac ; i++)
		{
			niz[i - 1] = niz[i];
		}
		brojac--;
		return poc;
	}
	T ukloni_s_kraja()
	{
		brojac--;
		T novi = niz[brojac];
		return novi;
	}
	bool jel_prazna()
	{
		return brojac == 0;
	}
	bool jel_puna()
	{
		return brojac == max_size;
	}
	T get(int index)
	{
		return niz[index];
	}
	int get_brojac()
	{
		return brojac;
	}
	void print()
	{
		for (int i = 0; i < get_brojac(); i++)
		{
		
			cout << niz[i] << " | ";
		}
		cout << endl;
	}
	void prosiri_niz()
	{
		T* novi_niz = new T[max_size * 2];
		for (int i = 0; i < brojac; i++)
		{
			novi_niz[i] = niz[i];
		}
		delete[]niz;
		niz = novi_niz;
		max_size *= 2;
	}
};