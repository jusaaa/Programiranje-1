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