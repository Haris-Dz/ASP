#pragma once
#include "Cvor.h"
#include<iostream>
#include"Stek.h"
using namespace std;
template <class T>
class StekPov : public Stek<T>
{
	Cvor<T>* prvi = nullptr;

public:
	void dodaj(T x)
	{
		if (jel_prazan())
		{
			prvi = new Cvor<T>(x);
		}
		else
		{
			Cvor<T>* n = new Cvor<T>(x, prvi);
			prvi = n;
		}
	}

	int ukloni()
	{
		if (jel_prazan())
		{
			throw exception("Lista je prazna");
			
		}
		Cvor<T>* t = prvi;
		prvi = prvi->next;
		T x = t->info;
		delete t;
		return x;
	}

	bool jel_prazan()
	{
		return prvi == nullptr;
	}

	bool jel_pun()
	{
		return false;
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