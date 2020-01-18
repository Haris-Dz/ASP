#pragma once
#include<iostream>
#include "Lista.h"
using namespace std;
class ListaSekv : public Lista
{
	int max_size = 2;
	int *niz = new int[max_size];
	int brojac = 0;
public:
	void dodaj_na_pocetak(int x)
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
	void dodaj_na_kraj(int x)
	{
		if (jel_puna())
		{
			prosiri_niz();
		}
		niz[brojac] = x;
		brojac++;
	}
	int ukloni_s_pocetka()
	{
		int poc = niz[0];
		for (int i = 1; i < brojac ; i++)
		{
			niz[i - 1] = niz[i];
		}
		brojac--;
		return poc;
	}
	int ukloni_s_kraja()
	{
		brojac--;
		int novi = niz[brojac];
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
	int get(int index)
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
		int* novi_niz = new int[max_size * 2];
		for (int i = 0; i < brojac; i++)
		{
			novi_niz[i] = niz[i];
		}
		delete[]niz;
		niz = novi_niz;
		max_size *= 2;
	}
};