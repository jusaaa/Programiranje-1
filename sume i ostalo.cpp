#include <iostream>
using namespace std;
int SumaSvihCifara(int);
int SumaPrveiZadnjeCifre(int);
void main(){
int x, y,brojac=0;

	do
	{
		cout << "Unesite vrijednost x: " << endl;
		cin >> x;
		cout << "Unesite vrijednost y: " << endl;
		cin >> y;
	} while (x<10 || x>5000 || y<10 || y>5000);
     
	for (int i = x; i <= y; i++) {
		if (SumaSvihCifara(i) % SumaPrveiZadnjeCifre(i) == 0) {
			cout << i << endl;
			brojac++;
		}
	}
	cout << "Dati uslov ispunjava: " << brojac << " brojeva" << endl;
	system("pause");
}
int SumaSvihCifara(int br) {
	int suma = 0, temp = 0;
	while (br>0)
	{
		temp = br % 10;
		suma += temp;
		br /= 10;
	}
	return suma;
}
int SumaPrveiZadnjeCifre(int br) {
	int zadnja = br % 10;
	while (br>=10)
	{
		br /= 10;
	}
	return br + zadnja;
}