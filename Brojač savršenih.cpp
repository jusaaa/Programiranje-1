
/* Napisati program koji izračunava aritmetičku sredinu svih savršenih brojeva iz zadatog intervala.
   Za neki broj se kaže da je savršen ukoliko je jednak sumi svih svojih djelilaca (ne uključujući njega samog).
   Na primjer, 28 je savršen broj: njegovi djelioci su: 1, 2, 4, 7 i 14, a 1+2+4+7+14=28. Jedini savršeni brojevi u opsegu od 1 do 100
   su brojevi 6 i 28. U rješenju koristiti funkciju sljedećeg prototipa: bool IsSavrsen(int).
   Primjer:
   Unesite granice intervala: 1 -> 500
   Aritmetička sredina savršenih brojeva iz zadatog intervala je: 176.667
*/
#include <iostream>
using namespace std;


bool IsSavrsen(int br) {
	int suma = 0;
	for (size_t i = 1; i < br; i++)
	{
		if (br % i == 0) {
			suma += i;
		}
	}
	if (suma == br) {
		return true;
	}
	return false;
}

int main() {
	int OD, DO;
	int brojacSavrsenih = 0;
	double suma = 0;
	cout << "Unesite vrijednost OD: " << endl;
	cin >> OD;
	cout << "Unesite vrijednost DO: " << endl;
	cin >> DO;

	for (size_t i = OD; i <= DO; i++)
	{
		if (IsSavrsen(i)) {
			suma += i;
			brojacSavrsenih++;
		}
	}
	cout << "Aritmeticka sredina savrsenih je: " << suma / brojacSavrsenih;



	system("pause>0");
	return 0;
}
