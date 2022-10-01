/*Napisati program koji će učitati prirodni broj n s 10, a zatim n prirodnih trocifrenih brojeva koje treba pospremiti u odgovarajući niz. 
Taj niz brojeva treba sortirati uzlazno po srednjoj cifri.
Nakon sortiranja treba ispisati dobiveni niz.
Za sortiranje koristiti zasebnu funkciju kojoj se proslijeđuje nesortiran niz.*/

#include <iostream>
using namespace std;

void unos(int niz[], int vel) {
	int broj;
	for (size_t i = 0; i < vel; i++)
	{
		cout << "Unesite "<<i+1<<". broj: ";
		cin >> broj;
		if (broj > 99 && broj < 1000)
			niz[i] = broj;
		else
		{
			cout << "Pogresan unos!";
			i--;
		}
	}
}
void sortiranje(int niz[], int vel) {
	bool promjena = true;
	int temp = 0;
	int srednja1 = 0;
	int srednja2 = 0;
	while (promjena)
	{
		promjena = false;
		for (size_t i = 0; i < vel - 1; i++)
		{
			srednja1 = (niz[i] / 10) % 10;
			srednja2 = (niz[i + 1] / 10) % 10;

			if (srednja1 > srednja2) {
				temp = niz[i];
				niz[i] = niz[i + 1];
				niz[i + 1] = temp;
				promjena = true;
			}
		}
	}
}
int main() {
	const int vel = 10;
	int niz[vel];
	int n;
	do
	{
		cout << "Koliko brojeva zelite unijeti? ";
		cin >> n;
	} while (n<1||n>10);
	unos(niz, n);
	sortiranje(niz, n);

	for (size_t i = 0; i < n; i++)
	{
		cout << niz[i] << "|";
	}

	system("pause>0");
	return 0;
}
