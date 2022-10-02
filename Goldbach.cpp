/*Svaki paran broj se može prikazati kao suma dva prosta broja (tkz. Goldbachovo pravilo). Napisati program koji će najprije učitati dva prirodna broja n1 i n2. 
Ako je n1 > n2 zamijeniti n1 sa n2. Zatim prikazati sve parne brojeve u intervalu od n1 do n2 kao sumu dva prosta broja. 
U glavnom programu samo unijeti navedena dva prirodna broja i pozvati funkciju koja obavlja zadani posao.*/

#include <iostream>
using namespace std;

bool prost(int br) {
	for ( int i = 2; i < br; i++)
	{
		if (br%i==0)
		{
			return false;
		}
	}
	return true;
}
void Goldbach(int n1, int n2) {
	if (n1%2!=0)
	n1++;

		for (int i = 1; i < n2; i++)
		{
			for (int j = 1; j < n2; j++)
			{
				if (prost(i)&&prost(j))
				{
					if (i+j==n1)
					{
						cout << n1 << "=" << i << "+" << j << endl;
						n1 += 2;
					}
			if (n1>n2)
				return;
				}
			}
		}
	
}

int main() {
	int n1, n2,temp;
	cout << "Unesite vrijednosti n1 i n2: " << endl;
	cin >> n1 >> n2;
	if (n1>n2)
	{
		
		temp=n1;
		n1 = n2;
	    n2=temp;
	}
	Goldbach(n1, n2);


	system("pause>0");
}
