#include<iostream>
using namespace std;

struct Tacka2D
{
	float x;
	float y;
	Tacka2D(float x = 0, float y = 0)
	{
		this->x = x;
		this->y = y;
	}
	friend ostream& operator<<(ostream&, const Tacka2D&);
};
ostream& operator<<(ostream& COUT, const Tacka2D& t)
{
	cout << "("<<t.x << "," << t.y<<")";
	return COUT;
}
struct Cvor
{
	Tacka2D info;
	Cvor* next;
	Cvor(Tacka2D info, Cvor* next = nullptr)
	{
		this->info = info;
		this->next = next;
	}
};

class PRpov
{
	Cvor* pocetak = nullptr;
	float udaljenost( Tacka2D t)
	{
		return sqrt(pow(10 - t.x, 2) + pow(-5 - t.y, 2));
	}

public:
	void dodaj(Tacka2D t)
	{
		
		Cvor* temp = pocetak;
		Cvor* prethodni = nullptr;
	
		while (temp != nullptr && udaljenost(temp->info) < udaljenost(t))
		{
			prethodni = temp;
			temp = temp->next;
		}	
		Cvor* novi = new Cvor(t, temp);
		if (prethodni == nullptr)
		{
			pocetak = novi;
			
		}
		else
		{
			prethodni->next = novi;
		}
			
	
	
		

	}
	Tacka2D Ukloni()
	{
		if (jel_prazan())
		{
			Tacka2D t;
			return t;
		}
		Cvor* temp = pocetak;
		Tacka2D nt = pocetak->info;
		pocetak = pocetak->next;
		delete temp;
		cout << "Uklonjeno -> " << nt<<endl;

		return nt;
	}
	bool jel_prazan()
	{
		return pocetak == nullptr;
	}
	bool jel_pun()
	{
		return false;
	}
	void print()
	{
		Cvor* temp = pocetak;
		while (temp != nullptr)
		{
			cout <<"Udaljenost tacke: "<< temp->info<<" od tacke (10,-5) je: "<<udaljenost(temp->info)<<endl;
			temp = temp->next;
		}
	}
	


};

void main()
{
	PRpov* red = new PRpov;
	Tacka2D t1(13, 7);
	Tacka2D t2(12, 8);
	Tacka2D t3(1, 3);
	Tacka2D t4(-3, 12);
	red->dodaj(t1);
	red->dodaj(t2);
	red->dodaj(t3);
	red->dodaj(t4);
	cout << "========== Ispis ==========" << endl;
	red->print();

	cout << "Uklanjanje: " << endl;
	red->Ukloni();
	cout << "========== Ispis ==========" << endl;
	red->print();
	cout << "Uklanjanje: " << endl;
	red->Ukloni();
	cout << "========== Ispis ==========" << endl;
	red->print();
	system("pause>0");
}