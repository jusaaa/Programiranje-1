/*Kreirati dinamički dvodimenzionalni niz čiji su elementi objekti tipa student (student je struktura čija su obilježja data u nastavku).
Omogućiti korisniku da unese dimenzije niza.Kompletan 2D niz predstavlja univerzitet. Redovi dvodimenzionalnog niza predstavljaju različite fakultete 
(radi jednostavnosti rješenja podrazumijevati da svaki fakultet ima isti broj studenata). 
Obavezno automatizirati unos tako da se u sva obilježja upisuju random vrijednosti.
Omogućiti korisniku unos svih podataka za sve studente, te napraviti funkciju koja će pronaći fakultet sa najvećim prosjekom te ispisati koji je to redni 
broj fakulteta (index reda sa najvećim prosjekom). Zatim pronaći i ispisati ID studenta koji ima najveći prosjek na cijelom univerzitetu. 
U ovom zadatku je zabranjeno indexirati elemente niza uglastim zagradama. Obavezno koristiti aritmetiku pokazivača.*/

#include <iostream>
using namespace std;


struct student
{
    char* ID;
    char* imePrezime;
    float* prosjek;
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
void unos(student* s) {
    s->ID = GenerisiIAlociraj(5);
    s->imePrezime = GenerisiIAlociraj(5);
    s->prosjek = new float(5 + rand() % 6);
}
void ispis(student* s) {
    cout << "ID: " << s->ID << endl;
    cout << "Ime i prezime: " << s->imePrezime << endl;
    cout << "Prosjek: " << *s->prosjek << endl;
}
int fakultetNajveciProsjek(student** s, int fakulteta, int studenata) {
    int brojFakulteta = 0;
    float najveciProsjek = INT_MIN;
    for (size_t i = 0; i < fakulteta; i++)
    {
        float temp = 0;
        for (size_t j = 0; j < studenata; j++)
        {
            temp += *(*(s + i) + j)->prosjek;
        }
        if (temp > najveciProsjek) {
            najveciProsjek = temp;
            brojFakulteta = i + 1;
        }
    }
    return brojFakulteta;
}
void najboljiStudent(student** s, int fakulteta, int studenata) {
    char* najboljiID = nullptr;
    float najboljiProsjek = 0;
    for (size_t i = 0; i < fakulteta; i++)
    {
        for (size_t j = 0; j < studenata; j++)
        {
            if (najboljiProsjek<*(*(s+i)+j)->prosjek)
            {
                najboljiProsjek = *(*(s + i) + j)->prosjek;
                najboljiID = (*(s + i) + j)->ID;
            }
        }
    }
    if (najboljiID != nullptr)
        cout << najboljiID;
    else
        cout << "Nema studenata!";
}
void main() {
    int fakulteta, studenata;
    while (cout << "Unesite broj fakulteta: ", cin >> fakulteta, fakulteta <= 0);
    while (cout << "Unesite broj studenata: ", cin >> studenata, studenata <= 0);

    student** matrica = new student * [fakulteta];
    for (size_t i = 0; i < fakulteta; i++)
    {
        *(matrica + i) = new student[studenata];
    }
    for (size_t i = 0; i < fakulteta; i++)
    {
        for (size_t j = 0; j < studenata; j++)
        {
            unos(*(matrica + i) + j);
        }
    }
    for (size_t i = 0; i < fakulteta; i++)
    {
        for (size_t j = 0; j < studenata; j++)
        {
            ispis(*(matrica + i) + j);
        }
    }
    cout << "Fakultet sa najvecim prosjekom: " << fakultetNajveciProsjek(matrica, fakulteta, studenata)<<endl;
    cout << "ID studenta najbolji prosjek: "; najboljiStudent(matrica, fakulteta, studenata);
}
