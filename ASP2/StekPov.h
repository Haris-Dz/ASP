#pragma once
#include "Cvor.h"
#include<iostream>
#include"Stek.h"
using namespace std;
class StekPov : public Stek
{
	Cvor* prvi = nullptr;

public:
	void dodaj(int x)
	{
		if (jel_prazan())
		{
			prvi = new Cvor(x);
		}
		else
		{
			Cvor* n = new Cvor(x, prvi);
			prvi = n;
		}
	}

	int ukloni()
	{
		if (jel_prazan())
		{
			//throw exception("Lista je prazna");
			return 0;
		}
		Cvor* t = prvi;
		prvi = prvi->next;
		int x = t->info;
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