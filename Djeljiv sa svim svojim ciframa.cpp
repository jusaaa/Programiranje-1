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