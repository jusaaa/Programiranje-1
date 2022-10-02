#include <iostream>
using namespace std;


int main() {
	int broj;
	int faktorijel = 1;
	cout << "Unesite neki broj: ";
	cin >> broj;

	if (broj < 0)
	{
		cout << "Ne mozemo naci faktorijel negativnog broja!" << endl;
	}
	else if (broj <= 1)
		cout << broj << "!=" << faktorijel;
	else
	{
		for (size_t i = broj; i >= 2; i--)
		{
			faktorijel = faktorijel * i;
		}
		cout << broj << "!=" << faktorijel;
	}
}
