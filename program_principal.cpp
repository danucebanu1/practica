#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <stdlib.h>

using namespace std;

#define reset   "\x1B[0m"
#define red     "\x1B[31m"
#define green   "\x1B[32m"
#define yellow  "\x1B[33m"
#define blue    "\x1B[34m"
#define magenta "\x1B[35m"
#define cyan    "\x1B[36m"
#define white   "\x1B[37m"

void afiseazaathlete();
void afiseaza_sport();
void inregistreaza_sportiv();
void inregistreaza_sport();
void delete_sportiv();
void delete_sport();
void actualizeaza_sportiv();
void actualizeaza_sport();
void total_sport();
void afiseaza_alfabetic();
void minimax();
void average_age();

void average_age()
{

}

void minimax()
{

}

void afiseaza_alfabetic()
{

}

void total_sport()
{

}

void actualizeaza_sport()
{

}

void actualizeaza_sportiv()
{

}

void delete_sport()
{

}

void delete_sportiv()
{

}

void inregistreaza_sport()
{

}

void inregistreaza_sportiv()
{

}

void afiseaza_sport()
{

}

void afiseazaathlete()
{

}

int main()
{
    system("clear");
    int n;
    cout<<"Sarcina 13 : Sport"<<endl;
    cout<<"[1] Afiseaza la ecran informatia din fisierul Athlete.txt"<<endl;
    cout<<"[2] Afiseaza la ecran informatia din fisierul Sport.txt"<<endl;
    cout<<"[3] Inregistreaza un sportiv nou"<<endl;
    cout<<"[4] Inregistreaza un sport nou"<<endl;
    cout<<"[5] Exclude informatia despre un sportiv"<<endl;
    cout<<"[6] Exclude informatia despre un sport"<<endl;
    cout<<"[7] Actualizeaza datele despre un sport"<<endl;
    cout<<"[8] Actualizeaza datele despre un sportiv"<<endl;
    cout<<"[9] Informatia totala despre sporturi"<<endl;
    cout<<"[10] Afiseaza alfabetic sportivii inaltimea carora nu depaseste"<<endl;
    cout<<"[11] Afiseaza datele sportivului cu greutatea minima si maxima"<<endl;
    cout<<"[12] Afiseaza varsta medie tuturor sportivilor ce practica categoria de sport introdusa de la tastatura"<<endl;
    cout<<endl<<"[99] Iesirea din program"<<endl;
    cout<<endl<<"Introdu optiunea -> ";
    cin>>n;
    switch(n)
    {
        case 1 : afiseazaathlete(); break;
        case 2 : afiseaza_sport(); break;
        case 3 : inregistreaza_sportiv(); break;
        case 4 : inregistreaza_sport(); break;
        case 5 : delete_sportiv(); break;
        case 6 : delete_sport(); break;
        case 7 : actualizeaza_sportiv(); break;
        case 8 : actualizeaza_sport(); break;
        case 9 : total_sport(); break;
        case 10 : afiseaza_alfabetic(); break;
        case 11 : minimax(); break;
        case 12 : average_age(); break;
        case 99 : system("clear"); return 0;
        default : cout<<red<<"Re-introdu optiune deoarece "<<n<<" nu este o optiune valida."<<white; cin.get(); cin.ignore(); main();
    }
}

