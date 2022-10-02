#include <iostream>
using namespace std;

int main() {
	int cifra = 0;
	int sastavljen = 0;
	while (cout<<"Unesite neku cifru: ",cin>>cifra,cifra>=0)
	{
		if (cifra > 9)
			cout << "Cifra nije validna" << endl;
		else
			sastavljen = sastavljen * 10 + cifra;
	}
	cout << "Broj sastavljen od cifara je: " << sastavljen;
	system("pause>0");
	return 0;
}