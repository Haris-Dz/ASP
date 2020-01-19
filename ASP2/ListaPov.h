#pragma once
#include "Cvor.h"
#include<iostream>
#include"Lista.h"
using namespace std;
template<class T>
class ListaPov : public Lista<T>
{
	Cvor<T>* prvi = nullptr;

public:
	void dodaj_na_pocetak(T x)
	{
		if (jel_prazna())
		{
			prvi = new Cvor<T>(x);
		}
		else
		{
			Cvor<T>* n = new Cvor<T>(x, prvi);
			prvi = n;
		}
	}
	void dodaj_na_kraj(T x)
	{
		if (jel_prazna())
		{
			prvi = new Cvor<T>(x);
			return;
		}
		Cvor<T>* n = new Cvor<T>(x);
		Cvor<T>* temp = prvi;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = n;
		
		
	}
	T ukloni_s_pocetka()
	{
		if (jel_prazna())
		{
			throw exception("Lista je prazna");
			
		}
		Cvor<T>* t = prvi;
		prvi = prvi->next;
		T x = t->info;
		delete t;
		return x;
	}
	T ukloni_s_kraja()
	{
		if (jel_prazna())
		{
			throw exception("Lista je prazna");
			
		}
		
		Cvor<T>* prethodni = nullptr;
		Cvor<T>* temp = prvi;
		if (temp->next == nullptr)
		{
			T f = temp->info;
			prvi = nullptr;
			return f;
		}
		while (temp->next != nullptr)
		{
			prethodni = temp;
			temp = temp->next;

		}
		prethodni->next = nullptr;	
		
		T x = temp->info;
		delete temp;
		temp = nullptr;
		return x;
	}
	bool jel_prazna()
	{
		return prvi == nullptr;
	}

	bool jel_puna()
	{
		return false;
	}
	T get(int index)
	{
		int b = 0;
		Cvor<T>* temp = prvi;
		while (temp != nullptr)
		{
			if (b == index)
			{
				return temp->info;
			}
			b++;
			temp = temp->next;
		}
		throw exception("Neispravan unos");
	}
	int get_brojac()
	{
		int b = 0;
		Cvor<T>* temp = prvi;
		while (temp != nullptr)
		{
			b++;
			temp = temp->next;
		}
		return b;
	}
	void print()
	{
		Cvor<T>* temp = prvi;
		while (temp != nullptr)
		{
			cout << temp->info << " | ";
			temp = temp->next;
		}
		cout << endl;
	}

};