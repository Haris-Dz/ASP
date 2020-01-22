#include<iostream>
using namespace std;
struct Datum 
{
	int D;
	int M;
	int G;
	Datum(int D = 0, int M = 0, int G = 0)
	{
		this->D = D;
		this->M = M;
		this->G = G;
	}
	friend ostream& operator<<(ostream&, const Datum&);

};
ostream& operator<<(ostream& COUT, const Datum& d)
{
	cout << d.D << "." << d.M << "." << d.G;
	return COUT;
}
class RedSekv
{
	int max_vel = 2;
	int poc = 0;
	int kraj = 0;
	int brojac = 0;
	Datum* niz = new Datum[max_vel];
	
public:
	void Dodaj(Datum x)
	{
		if (jel_pun())
		{
			prosiri_niz();
		}
		niz[kraj++] = x;
		if (kraj == max_vel)
		{
			kraj = 0;
		}
		brojac++;
	}
	Datum Ukloni()
	{
		if (jel_prazan())
		{
			Datum t;
			return t;
		}
		Datum n;
		brojac--;
		n = niz[poc++];
		if (poc == max_vel)
		{
			poc = 0;
		}
		return n;
	}
	void prosiri_niz()
	{
		Datum* novi_niz = new Datum[max_vel * 2];
		int i = poc;
		for (int j = 0; j < brojac; j++)
		{
			if (poc == max_vel)
			{
				poc = 0;
				novi_niz[j] = niz[i];
				i++;
			}
			else
			{
				novi_niz[j] = niz[i];
				i++;
			}
		}
		niz = novi_niz;
		max_vel *= 2;
		poc = 0;
		kraj = brojac;
	}
	bool jel_prazan()
	{
		return brojac == 0;
	}
	bool jel_pun()
	{
		return brojac == max_vel;
	}
	void print()
	{
		int j = poc;
		for (int i = 0; i < brojac; i++)
		{
			if (j == max_vel)
			{
				poc = 0;
				cout << niz[j];
				j++;
			}
			else
			{
				cout << niz[j]<<endl;
				j++;
			}
		}
	}

};

void main()
{
	RedSekv* red = new RedSekv;
	Datum d1(18, 2, 2001);
	Datum d2(12, 5, 1998);
	Datum d3(5, 1, 1993);
	Datum d4(8, 8, 100);
	red->Dodaj(d1);
	red->Dodaj(d2);
	red->Dodaj(d3);
	red->Dodaj(d4);
	cout << "Dodani elementi u red: " << endl;
	red->print();
	cout << endl;

	cout << "Uklonjeno iz reda" << red->Ukloni();
	cout << endl;
	cout << "Uklonjeno iz reda" << red->Ukloni();
	

	system("pause>0");
}