#include <iostream>
#include "ListaSekv.h"
#include "ListaPov.h"
#include "Lista.h"
#include"Stek.h"
#include"Red.h"
#include"StekSekv.h"
#include"StekPov.h"
#include "Redsekv.h"
#include "RedPov.h"
#include "PrioritetniRed.h"
#include "PRSekv.h"
#include "PRPov.h"
using namespace std;
void ListaOperacije(Lista<int>& x) 
{
	
	
	int u;
	do
	{
		cout << "========== LISTA =========="<<endl;
		cout << "1. Dodaj na pocetak" << endl;
		cout << "2. Dodaj na kraj" << endl;
		cout << "3. Ukloni s pocetka" << endl;
		cout << "4. Ukloni s kraja" << endl;
		cout << "5. Print" << endl;
		cout << "6. Sve ukloni" << endl;
		cout << "7. Izlaz" << endl;
		cin >> u;
		int b;
		switch (u)
		{
		case 1:
			cout << "Unesite broj: ";
			
			cin >> b;
			x.dodaj_na_pocetak(b);
			break;
		case 2:
			cout << "Unesite broj: ";
			
			cin >> b;
			x.dodaj_na_kraj(b);
			break;
		case 3:
			b = x.ukloni_s_pocetka();
			cout << "Uklonjeno sa pocetka " << b << endl;
			break;
		case 4:
			b = x.ukloni_s_kraja();
			cout << "Uklonjeno s kraja " << b << endl;
			break;
		case 5:
			x.print();
			break;
		case 6:
			/*int brojac = x.get_brojac();
			for (int i = 0; i < brojac; i++)
			{
				x.ukloni_s_pocetka();
			}*/
			while (!x.jel_prazna())
			{
				x.ukloni_s_kraja();
			}
			break;
		default:
			break;
		}
	} while (u != 7);

}
void StekOperacije(Stek<int>& x)
{

	int u;
	do
	{
		cout << "========== STEK ============"<<endl;
		cout << "1. Dodaj na vrh" << endl;
		cout << "2. Ukloni s vrha" << endl;
		cout << "3. Print" << endl;
		cout << "4. Sve ukloni" << endl;
		cout << "0. Izlaz" << endl;

		cin >> u;
		int b;
		switch (u)
		{
		case 1:
			cout << "Unesite broj: ";

			cin >> b;
			x.dodaj(b);
			break;
		case 2:
			b = x.ukloni();
			cout << "Uklonjeno s vrha steka " << b << endl;
			break;
		case 3:
			x.print();
			break;
		case 4:
			/*int brojac = x.get_brojac();
			for (int i = 0; i < brojac; i++)
			{
				x.ukloni_s_pocetka();
			}*/
			while (!x.jel_prazan())
			{
				x.ukloni();
			}
			break;
		default:
			break;
		}
	} while (u != 0);
}
void RedOperacije(Red<int>& x)
{

	int u;
	do
	{
		cout << "========== RED ============" << endl;
		cout << "1. Dodaj u red" << endl;
		cout << "2. Ukloni iz reda" << endl;
		cout << "3. Print" << endl;
		cout << "4. Sve ukloni" << endl;
		cout << "0. Izlaz" << endl;

		cin >> u;
		int b;
		switch (u)
		{
		case 1:
			cout << "Unesite broj: ";

			cin >> b;
			x.dodaj(b);
			break;
		case 2:
			b = x.ukloni();
			cout << "Uklonjeno iz reda " << b << endl;
			break;
		case 3:
			x.print();
			break;
		case 4:
			/*int brojac = x.get_brojac();
			for (int i = 0; i < brojac; i++)
			{
				x.ukloni_s_pocetka();
			}*/
			while (!x.jel_prazan())
			{
				x.ukloni();
			}
			break;
		default:
			break;
		}
	} while (u != 0);
}
void PROperacije(PrioritetniRed<int>& x)
{

	int u;
	do
	{
		cout << "========== Prioritetni red ============" << endl;
		cout << "1. Dodaj u PR" << endl;
		cout << "2. Ukloni iz PR" << endl;
		cout << "3. Print" << endl;
		cout << "4. Sve ukloni" << endl;
		cout << "0. Izlaz" << endl;

		cin >> u;
		int b;
		switch (u)
		{
		case 1:
			cout << "Unesite broj: ";

			cin >> b;
			x.dodaj(b);
			break;
		case 2:
			b = x.ukloni();
			cout << "Uklonjeno iz PR " << b << endl;
			break;
		case 3:
			x.print();
			break;
		case 4:
			/*int brojac = x.get_brojac();
			for (int i = 0; i < brojac; i++)
			{
				x.ukloni_s_pocetka();
			}*/
			while (!x.jel_prazan())
			{
				x.ukloni();
			}
			break;
		default:
			break;
		}
	} while (u != 0);
}
struct Osoba {
	string ime;
	Osoba(string x = " ")
	{
		ime = x;
	}
};
ostream& operator << (ostream& out, const Osoba& c)
{
	out << c.ime;
	return out;
}
void main()
{
	/*ListaSekv<int> b;
	ListaPov<int> c;
	StekSekv<int> d;
	StekPov<int> e;
	ListaPov <Osoba> A;
	
	ListaOperacije(b);
	ListaOperacije(c);
	StekOperacije(d);
	StekOperacije(e);
	A.dodaj_na_kraj(Osoba("Hd"));*/
	
	PRPov<int> r1;
	PROperacije(r1);


	system("pause>0");
}