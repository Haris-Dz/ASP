#pragma once
#include "Cvor.h"
class ListaPov 
{
	Cvor* prvi = nullptr;

public:
	void dodaj_na_pocetak(int x)
	{
		if (jel_prazna())
		{
			prvi = new Cvor(x);
		}
		else
		{
			Cvor* n = new Cvor(x, prvi);
			prvi = n;
		}
	}
	void dodaj_na_kraj(int x)
	{
		if (jel_prazna())
		{
			prvi = new Cvor(x);
			return;
		}
		Cvor* n = new Cvor(x);
		Cvor* temp = prvi;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = n;
		
		
	}
	int ukloni_s_pocetka()
	{
		if (jel_prazna())
		{
			throw exception("Lista je prazna");
		}
		Cvor* t = prvi;
		prvi = prvi->next;
		int x = t->info;
		delete t;
		return x;
	}
	int ukloni_s_kraja()
	{
		if (jel_prazna())
		{
			throw exception("Lista je prazna");
		}
		
		Cvor* prethodni = nullptr;
		Cvor* temp = prvi;
		if (temp->next == nullptr)
		{
			int f = temp->info;
			prvi == nullptr;
			return f;
		}
		while (temp->next != nullptr)
		{
			prethodni = temp;
			temp = temp->next;

		}
		prethodni->next = nullptr;	
		
		int x = temp->info;
		delete temp;
		temp = nullptr;
		return x;
	}
	bool jel_prazna()
	{
		return prvi == nullptr;
	}

	int get(int index)
	{
		int b = 0;
		Cvor* temp = prvi;
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
		Cvor* temp = prvi;
		while (temp != nullptr)
		{
			b++;
			temp = temp->next;
		}
		return b;
	}
	void print()
	{
		Cvor* temp = prvi;
		while (temp != nullptr)
		{
			cout << temp->info << " | ";
			temp = temp->next;
		}
		cout << endl;
	}

};