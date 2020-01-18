#pragma once
class Lista
{
public:
	virtual void dodaj_na_pocetak(int x) = 0;
	virtual void dodaj_na_kraj(int x) = 0;
	virtual int ukloni_s_pocetka() = 0;
	virtual int ukloni_s_kraja() = 0;
	virtual bool jel_prazna() = 0;
	virtual bool jel_puna() = 0;
	virtual int get(int index) = 0;
	virtual int get_brojac() = 0;
	virtual void print() = 0;

};
