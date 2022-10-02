#include <iostream>
using namespace std;

void unos(int i, int j, int red, int kolona, int matrica[][3]) {
	if (j == kolona) {
		j = 0;
		i++;
	}
	if (i == red)
		return;
	cin >> matrica[i][j];
	unos(i, j + 1, red, kolona, matrica);
}
void ispis(int i, int j, int red, int kolona, int matrica[][3]) {
	if (j == kolona) {
		j = 0;
		i++;
		cout << endl;
	}
	if (i == red)
		return;
	cout << matrica[i][j] << "   ";
	ispis(i, j + 1, red, kolona, matrica);
}
int sumasvih(int i, int j, int red, int kolona, int matrica[][3],int suma=0) {
	if (j == kolona) {
		j = 0;
		i++;
	}
	if (i == red)
		return suma;
	suma += matrica[i][j];
 sumasvih(i, j + 1, red, kolona, matrica, suma);
}
int sumapozitivnih(int i, int j, int red, int kolona, int matrica[][3], int suma = 0) {
	if (j == kolona) {
		j = 0;
		i++;
	}
	if (i == red)
		return suma;
	if(matrica[i][j]>0)
	suma += matrica[i][j];
	sumapozitivnih(i, j + 1, red, kolona, matrica, suma);
}
int sumaparniindeks(int i, int j, int red, int kolona, int matrica[][3], int suma = 0) {
	if (j == kolona) {
		j = 0;
		i++;
	}
	if (i == red)
		return suma;
	if (i%2==0 && j%2==0)
		suma += matrica[i][j];
	sumaparniindeks(i, j + 1, red, kolona, matrica, suma);
}

int main()
{
	int matrica[3][3];
	unos(0, 0, 3, 3, matrica);
	ispis(0, 0, 3, 3, matrica);
	cout<<sumasvih(0, 0, 3, 3, matrica)<<endl;
	cout << sumapozitivnih(0, 0, 3, 3, matrica)<<endl;
	cout << sumaparniindeks(0, 0, 3, 3, matrica);
	return 0;
}