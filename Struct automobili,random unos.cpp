#include <iostream>
using namespace std;

struct automobil
{
    char* Naziv;
    char* Marka;
    char* Tip;
    int* godinaProizvodnje;
    float* potrosnjaNaStoKm;
};
char* GenerisiIAlociraj(int vel) {
    char* niz = new char[vel + 1];
    for (size_t i = 0; i < vel; i++)
    {
        niz[i] = 'a' + rand() % 26;
    }
    niz[vel] = '\0';
    return niz;
}
void unos(automobil* a) {
    a->Naziv = GenerisiIAlociraj(3);
    a->Marka = GenerisiIAlociraj(3);
    a->Tip = GenerisiIAlociraj(3);
    a->godinaProizvodnje = new int(2005 + rand() % (2022 - 2005 + 1));
    a->potrosnjaNaStoKm = new float(5 + rand() % 20);
}
void ispis(automobil* a) {
    cout << "Naziv: " << a->Naziv << endl;
    cout << "Marka: " << a->Marka << endl;
    cout << "Tip: " << a->Tip << endl;
    cout << "Godina proizvodnje: " << *a->godinaProizvodnje << endl;
    cout << "Potrosnja na sto km: " << *a->potrosnjaNaStoKm << endl;
}
int firmaNajmanjaPotrosnja(automobil** a, int firme, int vozila) {
    float najmanjaPotrosnja = INT_MAX;
    int indeks = 0;
    for (size_t i = 0; i < firme; i++)
    {
        float temp = 0;
        for (size_t j = 0; j < vozila; j++)
        {
            temp += *(*(a + i) + j)->potrosnjaNaStoKm;
        }
        if (temp < najmanjaPotrosnja) {
            najmanjaPotrosnja = temp;
            indeks = i + 1;
        }
    }
    return indeks;
}

void main() {
    int firme, vozila;
    while (cout << "Unesite broj firmi: ", cin >> firme, firme <= 0);
    while (cout << "Unesite broj vozila: ", cin >> vozila, vozila <= 0);

    automobil** matrica = new automobil * [firme];

    for (size_t i = 0; i < firme; i++)
    {
        *(matrica + i) = new automobil[vozila];
    }
    for (size_t i = 0; i < firme; i++)
    {
        for (size_t j = 0; j < vozila; j++)
        {
            unos(*(matrica + i) + j);
        }
    }
    for (size_t i = 0; i < firme; i++)
    {
        for (size_t j = 0; j < vozila; j++)
        {
            ispis(*(matrica + i) + j);
        }
    }
    cout << "Firma najmanja potrosnja: " << firmaNajmanjaPotrosnja(matrica, firme, vozila) << endl;

}
