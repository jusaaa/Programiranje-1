/*Napišite program u kojem ćete kreirati niz od 5 studenata.
Kreirajte funkcije:
· za unos obilježja studenta – neka funkcija prima pokazivač na student;· za ispis obilježja studenta – neka funkcija prima pokazivač na student;
· za validacija unesenog datuma rođenja – funkcija prima pokazivač na datum a vraća true ako
je datum validan (npr. 2.2.2002.) ili vraća false ako datum nije validan (npr. 17.23.100000.);
· za prebrojavanje studenata čiji datum rođenja nije validan – funkcija prima pokazivač na
student;
· pronalaženje prvog studenta (u nizu) čiji datum rođenja nije validan; funkcija prima i vraća
pokazivač na student;
· pozvati sve prethodne funkcije preko pokazivača*/

#include<iostream>
#include<string.h>
using namespace std;

struct datum
{
	int dan;
	int mjesec;
	int godina;



	void unos()
	{
		cout << "Dan: "; cin >> dan;
		cout << "Mjesec: "; cin >> mjesec;
		cout << "Godina: "; cin >> godina;
	}



	void ispis()
	{
		cout << "Dan: " << dan;
		cout << "Mjesec: " << mjesec;
		cout << "Godina: " << godina;
	}
};



struct student
{
	int IB;
	char ImeiPrezime[30];
	datum rodjenja;
};
// (*(s)).nesto i s->nesto je isto
void unosStudenta(student *s)
{



	cout << "Unesite broj indeksa: ";
	cin >> (*(s)).IB;
	cout << "Ime i prezime: ";
	cin.ignore();
	cin.getline((*(s)).ImeiPrezime, 30);
	cin.ignore();
	(*(s)).rodjenja.unos();
}



void ispisStudenta(student* s)
{
	cout << "Broj indeksa: " << s->IB << endl;
	cout << "Ime i prezime: " << s->ImeiPrezime << endl;
	cout << "Datum rodjenja: "; s->rodjenja.ispis();

}



bool validacija(datum* d)
{
	if (d->godina > 2022 || d->godina < 1950)
		return false;
	if (d->mjesec < 1 || d->mjesec>12)
		return false;
	switch (d->mjesec)
	{
	case 4:
	case 8:
	case 10:
	case 11: {if (d->dan > 30) return false; }
	case 2: { if (!((d->godina % 4 == 0 && d->godina % 100 != 0) || d->godina % 400 == 0))
	{
		if (d->dan > 28)
			return false;
	}
	}
	default: if (d->dan > 31) return false;
	}
	return true;
}
int prebrojavanje(student* s, int vel)
{
	int brojac = 0;
	for (int i = 0; i < vel; i++)
	{
		if (!validacija(&s[i].rodjenja))
			brojac++;
	}
	return brojac;
}



student* prviUNizu(student* s, int vel)
{
	for (int i = 0; i < vel; i++)
	{
		if (!validacija(&s[i].rodjenja))
			return (s + i);
	}
	return nullptr;
}
int main()
{
	int vel = 5;
	student* nizStudenata=new student[vel];
	for (size_t i = 0; i < vel; i++)
	{
		unosStudenta(nizStudenata + i);
	}
	cout << endl;
	cout<<"Pogresan unos datuma imaju: "<<prebrojavanje(nizStudenata, vel)<<" studenta."<<endl;
	return 0;
}
