/*Napisati program koji omogućava korisniku unos integer vrijednosti veće od 100. Napisati funckiju koja će provjeriti da li je uneseni broj u isto vrijeme i
prost i "palindrom", odnosno da li je isti broj i kada se obrnnu sve cifre. Po potrebi koristiti dodatne funkcije. Npr. brojevi 383, 727, 757, 787, 797, 919, 929 su
u isto vrijeme i prosti brojevi i "palindromi".*/

#include <iostream>
using namespace std;

bool prost(int br) {
	for (size_t i =2; i < br; i++)
	{
		if (br%i==0)
			return false;
	}
	return true;
}
int obrniCifre(int br) {
	int temp = 0;
	int novi = 0;
	while (br>0)
	{
		temp = br % 10;
		novi = novi * 10 + temp;
		br /= 10;
	}
	return novi;
}
bool palindrom(int br) {
	if (br == obrniCifre(br)) {
		return true;
	}
	return false;
}
void main() {
	int broj;
	do
	{
		cout << "Unesite broj veci od 100: ";
		cin >> broj;
	} while (broj<100);

	if (prost(broj)&&palindrom(broj))
	{
		cout << "Uneseni broj je u isto vrijeme prost i palindrom!";
	}
	else
	{
		cout << "Uneseni broj nije u isto vrijeme prost i palindrom!";
	}

}
