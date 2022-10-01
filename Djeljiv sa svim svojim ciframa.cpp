/*Kreirati program koji će pronaći i ispisati sve brojeve od X do Y (uključujući granične vrijednosti)
koji su deljivi svim svojim ciframa. Na primjer, broj 36 je djeljiv sa brojevima 3 i 6. (36/6-6 i 36/3-12).
Brojeve X i Y unosi korisnik i moraju biti u opsegu od 10 do 6000. Obavezno koristiti bar jednu funkciju.
Primier:
5
Unesite granice intervala: 32 37
6
Brojevi u navedenom opsegu koji zadovoljavaju uslov su: 33, 36.*/

#include <iostream>
using namespace std;

bool djeljivSaSvimSvojimCiframa(int br) {
	int temp = br;
	int zadnja;
	while (br>0)
	{
		zadnja = broj % 10;
		if (zadnja!=0)
		{
			if (temp%zadnja!=0)
				return false;
		}
		br /= 10;
	}
	return true;
}

void main() {
	int x;
	int y;
	int brojac = 0;
	do
	{
		cout << "Unesite x: " << endl;
		cin >> x;
		cout << "Unesite y: " << endl;
		cin >> y;
	} while (x<10||y>6000||y<10||x>6000);

	for (size_t i = x; i <= y; i++)
	{
		if (djeljivSaSvimSvojimCiframa(i))
		{
			cout << i << endl;
		}
	}

	system("pause");
}
