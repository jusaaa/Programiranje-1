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