#include <iostream>;
using namespace std;
bool prost(int);
void Goldbach(int, int);
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