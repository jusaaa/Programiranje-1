/*Napisati program koji će omogućiti korisniku da unese veličinu n jednodimenzionalnog dinamičkog niza integer vrijednosti (n > 2). 
Napisati rekurzivnu funkciju koja će taj niz puniti serijom brojeva 1, 3, 3, 9, 27, ..., tako da je svaki slijedeći broj jednak umnosku dva prethodna broja 
(Prva dva elementa su 1 i 3.) Rekurzija se prekida kad se popuni cijeli niz ili kad se desi overflow na integer varijabli. Zatim napraviti drugu rekurzivnu
funkciju koja će izračunati zbir svih elemenata tog niza (Voditi računa o tipu podataka zbog veličine broja). U ovom zadatku je zabranjeno indexirati elemente
niza uglastim zagradama. Obavezno koristiti aritmetiku pokazivača.*/

#include <iostream>
using namespace std;

void unos(long long int* niz, int vel, int i = 0) {
	if (i == vel|| *(niz + i - 1) * (*(niz + i - 2))<0)
		return;
	*(niz + i) = *(niz + i - 1) * *(niz + i - 2);

	unos(niz, vel, i + 1);
}
int sumaElemenata(long long int* niz, int vel, int i = 0, long long int suma = 4) {
	if (i == vel)
		return suma;
	suma += *(niz + i);

   sumaElemenata(niz, vel, i + 1, suma);
}
int main() {
	int vel;
	do
	{
		cout << "Unesite velicinu niza: ";
		cin >> vel;

	} while (vel<=2);


	long long int* niz = new long long int[vel];
	*(niz) = 1;
	*(niz + 1) = 3;
	unos(niz, vel, 2);
	for (size_t i = 0; i < vel; i++)
	{
		cout << *(niz + i) << " | ";
	}
	cout << endl;
	cout << sumaElemenata(niz, vel, 2);

	system("pause>0");
	return 0;
}
