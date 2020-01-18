#include <iostream>
#include "ListaSekv.h"
#include "ListaPov.h"
#include "Lista.h"
using namespace std;
void NewFunction(Lista& x) 
{
	
	
	int u;
	do
	{
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
void main()
{
	//ListaSekv x;
	ListaPov x;
	NewFunction(x);


	system("pause>0");
}