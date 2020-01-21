#pragma once
#include "Cvor.h"
#include<iostream>
#include"Red.h"
using namespace std;
template <class T>
class RedPov : public Red<T>
{
	Cvor<T>* pocetak = nullptr;
	Cvor<T>* kraj = nullptr;

public:
	void dodaj(T x)
	{
		Cvor<T>* temp = new Cvor<T>(x);
		if (jel_prazan())
		{
			pocetak = temp;
			kraj = temp;
		}
		else
		{
			kraj->next = temp;
			kraj = temp;
		}
		
	}

	int ukloni()
	{
		if (jel_prazan())
		{
			throw exception("Red je prazan");
		}

		Cvor<T>* temp = pocetak;
		T x = temp->info;
		pocetak = pocetak->next;
		delete temp;

		if (pocetak == nullptr)
		{
			kraj = nullptr;
		}
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