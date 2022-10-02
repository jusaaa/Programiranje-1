/*Napisati program koji omogućava unos pozitivnog broja n te pronalazi njegove parne cifre i formira novi broj u kojem su parne cifre zamijenjene brojem 5.
Dodatno program treba ispisati razliku unesenog broja i broja koji se dobije nakon zamjene cifara*/


#include <iostream>
using namespace std;

int zamjena(int br)
{
	int temp = 0;
	int novi = 0;
	int potencija = 0;
	while (br>0)
	{
		temp = br % 10;
		if (temp % 2 == 0)
		{
			novi += 5 * pow(10, potencija);
		}
		else
		{
			novi += temp * pow(10, potencija);
		}
		br /= 10;
		potencija++;
	}
	return novi;
}
void main()
{
	int n;
	int zamjenjenBroj;
	do
	{
		cout << "Unesite neki prirodan broj n: " << endl;
		cin >> n;

	} while (n<1);
	zamjenjenBroj = zamjena(n);
	cout << "Razlika unesenog broja i nakon zamjene parnih sa brojem 5 je: " << zamjenjenBroj - n << endl;

	system("pause");
}
