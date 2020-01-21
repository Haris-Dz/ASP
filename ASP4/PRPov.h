#pragma once
#include "Cvor.h"
#include<iostream>
#include"PrioritetniRed.h"
using namespace std;
template <class T>
class PRPov : public PrioritetniRed<T>
{
	Cvor<T>* pocetak = nullptr;

public:
	void dodaj(T x)
	{
		
		Cvor<T>* temp = pocetak;
		Cvor<T>* prethodni = nullptr;
		while (temp != nullptr && temp->info > x)
		{
			prethodni = temp;
			temp = temp->next;
		}
		Cvor<T>* novi = new Cvor<T>(x, temp);
		if (prethodni != nullptr)
		{
			
			prethodni->next = novi;
		}
		else
		{
			pocetak = novi;

		}
		
	}

	int ukloni()
	{
		if (jel_prazan())
		{
			throw exception("Lista je prazna");

		}
		Cvor<T>* t = pocetak;
		pocetak = pocetak->next;
		T x = t->info;
		delete t;
		return x;
	}

	bool jel_prazan()
	{
		return pocetak == nullptr;
	}

	bool jel_pun()
	{
		return false;
	}

	int get_brojac()
	{
		int b = 0;
		Cvor<T>* temp = pocetak;
		while (temp != nullptr)
		{
			b++;
			temp = temp->next;
		}
		return b;
	}
	void print()
	{
		Cvor<T>* temp = pocetak;
		while (temp != nullptr)
		{
			cout << temp->info << " | ";
			temp = temp->next;
		}
		cout << endl;
	}

};