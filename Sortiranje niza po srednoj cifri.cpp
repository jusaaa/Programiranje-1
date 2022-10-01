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