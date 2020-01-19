#pragma once
#include<iostream>
#include "Stek.h"
using namespace std;
template<class T>
class StekSekv : public Stek<T>
{
	int max_size = 2;
	T* niz = new T[max_size];
	int brojac = 0;
public:

	void dodaj(T x)
	{
		if (jel_pun())
		{
			prosiri_niz();
		}
		niz[brojac] = x;
		brojac++;
	}

	T ukloni()
	{
		brojac--;
		T novi = niz[brojac];
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