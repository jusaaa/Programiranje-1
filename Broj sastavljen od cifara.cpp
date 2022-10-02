/*Napisati program u kojem je potrebno unijeti odabrani broj cifara počevši od cifre najveće težinske vrijednosti, pa od njih sastaviti i ispisati prirodni broj.
Unos cifara se prekida kada se unese broj manji od 0, ukoliko korisnik unese cifru vecu od 9, ispisati poruku da cifra nije validna, ali se unos ne prekida. */

#include <iostream>
using namespace std;

int main() {
	int cifra = 0;
	int sastavljen = 0;
	while (cout<<"Unesite neku cifru: ",cin>>cifra,cifra>=0)
	{
		if (cifra > 9)
			cout << "Cifra nije validna" << endl;
		else
			sastavljen = sastavljen * 10 + cifra;
	}
	cout << "Broj sastavljen od cifara je: " << sastavljen;
	system("pause>0");
	return 0;
}
