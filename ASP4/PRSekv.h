#pragma once
#include<iostream>
#include "PrioritetniRed.h"
using namespace std;
template<class T>
class PRSekv : public PrioritetniRed<T>
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
		if (jel_prazan())
		{
			throw exception("PR je prazan");
		}

		T maxV = niz[0];
		int maxI = 0;
		for (int i = 0; i < brojac; i++)
		{
			if (niz[i]>maxV)
			{
				maxV = niz[i];
				maxI = i;
			}
		}

		brojac--;
		niz[maxI] = niz[brojac];
		
		return maxV;
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