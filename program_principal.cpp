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

int main();
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
    string categorie,denumire;
    string categorie_copy,denumire_copy;
    int id_sport,id_sport_copy;
    ofstream fout("Sport.txt",ios::app);
    cout<<"Introdu categoria sportului:";
    cin>>categorie;
    cout<<"Introdu denumirea sportului:";
    cin>>denumire;
    cout<<"Introdu ID-ul sportului:";
    cin>>id_sport;
    ifstream fin("Sport.txt");
    while(fin>>categorie_copy>>denumire_copy>>id_sport_copy)
    {
        if(id_sport_copy==id_sport)
        {
            cout<<yellow<<"Acest ID exista deja!"<<white;
            cin.get();
            cin.ignore();
            system("clear");
            main();
        }
    }
    fout << categorie << " " << denumire << " " << id_sport << endl;
    cout<<green<<"Ai inregistrat un sport cu succes!"<<white;
    cin.get();
    cin.ignore();
    system("clear");
    main();
}

void inregistreaza_sportiv()
{
    string nume,prenume;
    char gen;
    float greutate,inaltime;
    int varsta,id_sport,s,id_sport1;
    string nume1,prenume1;
    char gen1;
    float greutate1 , inaltime1;
    int varsta1;
    ofstream fout("Athlete.txt",ios::app);
    cout<<"Introdu numele sportivului:";
    cin>>nume;
    cout<<"Introdu prenumele sportivului:";
    cin>>prenume;
    cout<<"Introdu genul (M/F):";
    cin>>gen;
    if(gen != 'M' )
    {
        if(gen != 'm')
        {
            if(gen != 'F')
            {
                if(gen != 'f')
                {
                    cout<<yellow<<"Introdu un gen valid!"<<white<<endl;
                    cin.get();
                    cin.ignore();
                    system("clear");
                    main();
                }
            }
        }
    }
    cout<<"Introdu greutate (Kg):";
    cin>>greutate;
    cout<<"Introdu inaltime (Cm):";
    cin>>inaltime;
    cout<<"Introdu varsta:";
    cin>>varsta;
    cout<<"Introdu ID-ul sportului practicat de "<<nume<<" "<<prenume<<":";
    cin>>id_sport;
    ifstream fin1("Sport.txt");
    string categorie,denumire;
    while(fin1 >> categorie >> denumire >> s)
    {
        if(s=id_sport)
        {
            break;
        }
        else
        {
            cout<<red<<"Sport inexistent,creeaza un sport nou din meniul cu numarul 3"<<endl;
            cin.get();
            cin.ignore();
            system("clear");
            main();
        }
    }
    ifstream fiin("Athlete.txt");
    while(fiin >> nume1 >> prenume1 >> gen1 >> greutate1 >> inaltime1 >> varsta1 >> id_sport1 )
    {
        if(nume == nume1 and prenume == prenume1 and gen == gen1 and greutate == greutate1 and inaltime == inaltime1 and varsta == varsta1  and id_sport == id_sport1)
        {
            cout<<yellow<<"Acest sportiv este deja inregistrat in baza de date."<<white;
            cin.get();
            cin.ignore();
            system("clear");
            main();
        }
    }
    fout<<nume<<" "<<prenume<<" "<<gen<<" "<<greutate<<" "<<inaltime<<" "<<varsta<<" "<<id_sport<<" "<<categorie<<" "<<denumire<<endl;
    fout.close();
    cout<<green<<"Atletul "<<nume<<" "<<prenume<<" a fost adaugat in baza de date cu succes!"<<white;
    cin.get();
    cin.ignore();
    system("clear");
    main();
}

void afiseaza_sport()
{
    string categorie,denumire,id_sport;
    ifstream fin("Sport.txt");
    if(!fin.is_open())
    {
        ofstream fout("Sport.txt");
    }
    cout<<"Categorie       "<<"Denumire        "<<"Id Sport     "<<endl;
    while(fin >> categorie >> denumire >> id_sport)
    {
        cout << categorie << "       " << denumire << "        " << id_sport << endl;
    }
    cin.get();
    cin.ignore();
    system("clear");
    main();
}

void afiseaza_athlete()
{
    string nume,prenume,id_sport;
    char gen;
    float greutate,inaltime;
    int varsta;
    ifstream fin("Athlete.txt");
    if(!fin.is_open())
    {
        ofstream fout("Athlete.txt");
    }
    cout<<"Nume        "<<"Prenume        "<<"Gen (M/F)     "<<"Greutate (Kg)           "<<"Inaltime (Cm)         "<<"Varsta        "<<"Sport Practicat         "<<endl;
    while(fin >> nume >> prenume >> gen >> greutate >> inaltime >> varsta >> id_sport)
    {
        cout << nume << "       " << prenume<< "        " << gen << "        " << greutate << "        " << inaltime << "         " << varsta << "          " << id_sport << endl;
    }
    cin.get();
    cin.ignore();
    system("clear");
    main();
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
        case 1 : afiseaza_athlete(); break;
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

