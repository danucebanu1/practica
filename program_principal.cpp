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
    string categoria_introdusa;
    cout << "Introdu categoria sportului: ";
    cin >> categoria_introdusa;
    ifstream fin("Athlete.txt");
    int count = 0;
    int sum_varsta = 0;
    string nume, prenume;
    char gen;
    float greutate, inaltime;
    int varsta, id_sport;
    while (fin >> nume >> prenume >> gen >> greutate >> inaltime >> varsta >> id_sport) {
        ifstream fin1("Sport.txt");
        string categorie, denumire;
        int s;

        bool found = false;
        while (fin1 >> categorie >> denumire >> s) {
            if (s == id_sport && categorie == categoria_introdusa) {
                found = true;
                break;
            }
        }
        fin1.close();
        if (found) {
            count++;
            sum_varsta += varsta;
        }
    }
    fin.close();
    if (count == 0) {
        cout << red << "Nu exista sportivi inregistrati in aceasta categorie." << white << endl;
    } else {
        float average = (float)sum_varsta / count;
        cout << green << "Varsta medie a sportivilor din categoria " << categoria_introdusa << " este: " << average << " ani." << white << endl;
    }
    cin.get();
    cin.ignore();
    system("clear");
    main();
}

void minimax()
{
    ifstream fin("Athlete.txt");
    string nume, prenume;
    char gen;
    float greutate, inaltime, min_greutate , max_greutate ;
    int varsta, id_sport;
    string min_greutate_nume, min_greutate_prenume, max_greutate_nume, max_greutate_prenume;
    while (fin >> nume >> prenume >> gen >> greutate >> inaltime >> varsta >> id_sport) {
        if (greutate < min_greutate) {
            min_greutate = greutate;
            min_greutate_nume = nume;
            min_greutate_prenume = prenume;
        }
        if (greutate > max_greutate) {
            max_greutate = greutate;
            max_greutate_nume = nume;
            max_greutate_prenume = prenume;
        }
    }
    fin.close();
    cout << green << "Sportivul cu greutatea minima: " << min_greutate_nume << " " << min_greutate_prenume << " cu " << min_greutate << " Kg" << white << endl;
    cout << green << "Sportivul cu greutatea maxima: " << max_greutate_nume << " " << max_greutate_prenume << " cu " << max_greutate << " Kg" << white << endl;
    cin.get();
    cin.ignore();
    system("clear");
    main();
}

void afiseaza_alfabetic()
{
    float inaltime_max;
    cout << "Introdu inaltimea maxima: ";
    cin >> inaltime_max;
    ifstream fin("Athlete.txt");
    string nume, prenume;
    char gen;
    float greutate, inaltime;
    int varsta, id_sport;
    string athlete[100]; 
    int count = 0;
    while (fin >> nume >> prenume >> gen >> greutate >> inaltime >> varsta >> id_sport)
    {
        if (inaltime <= inaltime_max)
        {
            athlete[count] = nume + " " + prenume;
            count++;
        }
    }
    fin.close();
    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (athlete[i] > athlete[j])
            {
                string temp = athlete[i];
                athlete[i] = athlete[j];
                athlete[j] = temp;
            }
        }
    }
    cout << "Sportivii cu inaltimea de pana la " << inaltime_max << " cm sunt:" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << athlete[i] << endl;
    }
    cin.get();
    cin.ignore();
    system("clear");
    main();
}

void total_sport()
{
    ifstream fin("Athlete.txt");
    ofstream fout("Total.txt");
    string categorie, denumire, id;
    cout << green << "Fisierul Total.txt a fost creat cu succes." << white << endl;
    cout<<"Informatia din fisierul Total.txt:"<<endl;
    while (fin >> categorie >> denumire >> id) {
        bool isNew = true;
        ifstream finCheck("Athlete.txt"); 
        string checkCategorie, checkDenumire, checkId;

        while (finCheck >> checkCategorie >> checkDenumire >> checkId) {
            if (checkDenumire == denumire && checkId != id) {
                isNew = false;
                break;
            }
        }
        finCheck.close();
        if (isNew) {
            int count = 1; 
            ifstream finCount("Athlete.txt");
            string countCategorie, countDenumire, countId;

            while (finCount >> countCategorie >> countDenumire >> countId) {
                if (countDenumire == denumire && countId != id) {
                    count++;
                }
            }
            finCount.close();
            fout << denumire << " " << count << endl;
            cout<< denumire << " " << count << endl;
        }
    }
    fin.close();
    fout.close();
    fin.close();
    cin.get();
    cin.ignore();
    system("clear");
    main();
}


void actualizeaza_sport() {
    string denumire, categorie;
    int id_sport;
    string categorie_copy, denumire_copy;
    int id_copie;
    string categorie_txt, denumire_txt;
    int id_txt;
    cout << "Introdu categoria sportului: ";
    cin >> categorie;
    cout << "Introdu denumirea sportului: ";
    cin >> denumire;
    cout << "Introdu ID-ul sportului: ";
    cin >> id_sport;
    ifstream fin("Sport.txt");
    bool sport_found = false;
    while (fin >> categorie_copy >> denumire_copy >> id_copie) {
        if (categorie == categorie_copy && denumire == denumire_copy && id_sport == id_copie) {
            sport_found = true;
            break;
        }
    }
    if (!sport_found) {
        cout << red << "Acest sport nu este inregistrat in baza de date." << white << endl;
        fin.close();
        cin.get();
        cin.ignore();
        system("clear");
        main();
    }
    fin.close();
    int n;
    cout << "Introdu optiunea de actualizare a sportului " << denumire << ":" << endl;
    cout << "[1] Categorie" << endl;
    cout << "[2] Denumire" << endl;
    cout << "[3] ID" << endl;
    cout<<endl<<"Introdu optiunea:";
    cin >> n;
    fin.open("Sport.txt"); 
    ofstream fout("Sport_copy.txt", ios::app);
    switch (n) 
    {
            case 1:
            cout << "Introdu categoria noua: ";
            cin >> categorie_copy;
            cout << green << "Ai schimbat categoria de la " << categorie << " la " << categorie_copy << " cu succes!" << endl;
            while (fin >> categorie_txt >> denumire_txt >> id_txt) {
                if (categorie_txt == categorie && denumire_txt == denumire && id_txt == id_sport) {
                    fout << categorie_copy << " " << denumire_txt << " " << id_txt << endl;
                } else {
                    fout << categorie_txt << " " << denumire_txt << " " << id_txt << endl;
                }
            }
            cin.get();
            cin.ignore();
            system("clear");
            main();
            break;

            case 2:
            cout << "Introdu denumirea noua: ";
            cin >> denumire_copy;
            cout << green << "Ai schimbat denumirea de la " << denumire << " la " << denumire_copy << " cu succes!" << endl;
            while (fin >> categorie_txt >> denumire_txt >> id_txt) {
                if (categorie_txt == categorie && denumire_txt == denumire && id_txt == id_sport) {
                    fout << categorie_txt << " " << denumire_copy << " " << id_txt << endl;
                } else {
                    fout << categorie_txt << " " << denumire_txt << " " << id_txt << endl;
                }
            }
            cin.get();
            cin.ignore();
            system("clear");
            main();
            break;

            case 3:
            cout << "Introdu ID-ul nou: ";
            cin >> id_copie;
            while (fin >> categorie_txt >> denumire_txt >> id_txt) {
                if (id_txt == id_copie) {
                    cout << red << "Acest ID este deja existent, foloseste altul!" << endl;
                    fin.close();
                    fout.close();
                    remove("Sport_copy.txt");
                    cin.get();
                    cin.ignore();
                    system("clear");
                    main();
                }
            }
            fin.clear(); 
            fin.seekg(0, ios::beg); 
            cout << green << "Ai schimbat ID-ul de la " << id_sport << " la " << id_copie << " cu succes!" << white << endl;
            while (fin >> categorie_txt >> denumire_txt >> id_txt) {
                if (categorie_txt == categorie && denumire_txt == denumire && id_txt == id_sport) {
                    fout << categorie_txt << " " << denumire_txt << " " << id_copie << endl;
                } else {
                    fout << categorie_txt << " " << denumire_txt << " " << id_txt << endl;
                }
            }
            cin.get();
            cin.ignore();
            system("clear");
            main();
            break;
        default:
            cout << red << "Optiune invalida!" << white << endl;
            fin.close();
            fout.close();
            remove("Sport_copy.txt");
            cin.get();
            cin.ignore();
            system("clear");
            main();
    }
    fin.close();
    fout.close();
    remove("Sport.txt");
    rename("Sport_copy.txt", "Sport.txt");
    cin.get();
    cin.ignore();
    system("clear");
    main();
}


void actualizeaza_sportiv()
{
    ifstream fin1("Sport.txt");
    string categorie,denumire,categorie1,denumire1;
    int s,s1;
    int z;
    string nume,prenume;
    char gen;
    float greutate,inaltime;
    int id_sport,varsta,id_sport1;
    string nume1,prenume1;
    char gen1;
    float greutate1 , inaltime1;
    int varsta1;
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
    ifstream fin("Athlete.txt");
    bool athlete_found = false;
    while (fin >> nume1 >> prenume1 >> gen1 >> greutate1 >> inaltime1 >> varsta1 >> id_sport1)
    {
        if (nume == nume1 && prenume == prenume1 && gen == gen1 && greutate == greutate1 && inaltime == inaltime1 && varsta == varsta1 && id_sport == id_sport1)
        {
            athlete_found = true;
            break;
        }
    }
    if (!athlete_found) {
        cout << red << "Acest sportiv nu este inregistrat in baza de date." << white << endl;
        cin.get();
        cin.ignore();
        system("clear");
        main();
    }
    fin.close();
    int n;
    cout<<endl<<"Introdu optiunea de actualizare a sportivului "<<nume<<" "<<prenume<<endl;
    cout<<endl<<"[1] Greutate"<<endl;
    cout<<"[2] Inaltime"<<endl;
    cout<<"[3] Varsta"<<endl;
    cout<<"[4] Sportul Practicat"<<endl;
    cout<<endl<<"Introdu optiunea:";
    string nume_copie,prenume_copie;
    float inaltime_copie,greutate_copie;
    char gen_copie;
    int id_copie,varsta_copie;
    ifstream fein("Athlete.txt");
    ofstream fout2("Athlete_copy.txt",ios::app);
    ofstream fout("Athlete.txt",ios::app);
    cin>>n;
    float g;
    switch(n)
    {
        case 1 : 
        cout<<"Introdu greutatea noua:";
        cin>>g;
        cout<<green<<"Ai schimbat greutatea de la "<<greutate<<" la "<<g<<" cu succes."<<white<<endl;
        while(fein>>nume_copie>>prenume_copie>>gen_copie>>greutate_copie>>inaltime_copie>>varsta_copie>>id_copie)
        {
            if(nume_copie != nume || prenume_copie != prenume || gen_copie != gen || greutate_copie != greutate || inaltime_copie != inaltime || varsta_copie != varsta || id_copie != id_sport)
            {
                fout2<<nume_copie<<" "<<prenume_copie<<" "<<gen_copie<<" "<<greutate_copie<<" "<<inaltime_copie<<" "<<varsta_copie<<" "<<id_copie<<endl;
            }
        }
        fout2<<nume<<" "<<prenume<<" "<<gen<<" "<<g<<" "<<inaltime<<" "<<varsta<<" "<<id_sport<<endl;
        fein.close();
        fout2.close();
        fout.close();
        remove("Athlete.txt");
        rename("Athlete_copy.txt","Athlete.txt");
        cin.get();
        cin.ignore();
        system("clear");
        main();
        break;
        case 2:
        cout<<"Introdu Inaltimea noua:";
        cin>>g;
        cout<<green<<"Ai schimbat inaltimea de la "<<inaltime<<" la "<<g<<" cu succes."<<white<<endl;
        while(fein>>nume_copie>>prenume_copie>>gen_copie>>greutate_copie>>inaltime_copie>>varsta_copie>>id_copie)
        {
            if(nume_copie != nume || prenume_copie != prenume || gen_copie != gen || greutate_copie != greutate || inaltime_copie != inaltime || varsta_copie != varsta || id_copie != id_sport)
            {
                fout2<<nume_copie<<" "<<prenume_copie<<" "<<gen_copie<<" "<<greutate_copie<<" "<<inaltime_copie<<" "<<varsta_copie<<" "<<id_copie<<endl;
            }
        }
        fout2<<nume<<" "<<prenume<<" "<<gen<<" "<<greutate<<" "<<g<<" "<<varsta<<" "<<id_sport<<endl;
        fein.close();
        fout2.close();
        fout.close();
        remove("Athlete.txt");
        rename("Athlete_copy.txt","Athlete.txt");
        cin.get();
        cin.ignore();
        system("clear");
        main();
        break;
        case 3:
        int p;
        cout<<"Introdu varsta noua:";
        cin>>p;
        cout<<green<<"Ai schimbat varsta de la "<<varsta<<" la "<<p<<" cu succes."<<white<<endl;
        while(fein>>nume_copie>>prenume_copie>>gen_copie>>greutate_copie>>inaltime_copie>>varsta_copie>>id_copie)
        {
            if(nume_copie != nume || prenume_copie != prenume || gen_copie != gen || greutate_copie != greutate || inaltime_copie != inaltime || varsta_copie != varsta || id_copie != id_sport)
            {
                fout2<<nume_copie<<" "<<prenume_copie<<" "<<gen_copie<<" "<<greutate_copie<<" "<<inaltime_copie<<" "<<varsta_copie<<" "<<id_copie<<endl;
            }
        }
        fout2<<nume<<" "<<prenume<<" "<<gen<<" "<<greutate<<" "<<inaltime<<" "<<p<<" "<<id_sport<<endl;
        fein.close();
        fout2.close();
        fout.close();
        remove("Athlete.txt");
        rename("Athlete_copy.txt","Athlete.txt");
        cin.get();
        cin.ignore();
        system("clear");
        main();
        break;
        case 4:
        cout<<"Introdu ID-ul sportului nou practicat:";
        cin>>z;
        while(fin1 >> categorie >> denumire >> s)
        {
            if(g!=s)
            {
                cout<<red<<"Sport inexistent,creeaza un sport nou din meniul cu numarul 4"<<white<<endl;
                cin.get();
                cin.ignore();
                system("clear");
                main();
            }
            else
            {
                break;
            }
        }
        while(fin1>>categorie1>>denumire1>>s1)
        {
            if(z==s1)
            {
                break;
            }
        }
        cout<<green<<"Ai schimbat sportul de la "<<denumire1<<" la "<<denumire<<" cu succes."<<white<<endl;
        while(fein>>nume_copie>>prenume_copie>>gen_copie>>greutate_copie>>inaltime_copie>>varsta_copie>>id_copie)
        {
            if(nume_copie != nume || prenume_copie != prenume || gen_copie != gen || greutate_copie != greutate || inaltime_copie != inaltime || varsta_copie != varsta || id_copie != id_sport)
            {
                fout2<<nume_copie<<" "<<prenume_copie<<" "<<gen_copie<<" "<<greutate_copie<<" "<<inaltime_copie<<" "<<varsta_copie<<" "<<id_copie<<endl;
            }
        }
        fout2<<nume<<" "<<prenume<<" "<<gen<<" "<<greutate<<" "<<inaltime<<" "<<varsta<<" "<<z<<endl;
        fein.close();
        fout2.close();
        fout.close();
        remove("Athlete.txt");
        rename("Athlete_copy.txt","Athlete.txt");
        cin.get();
        cin.ignore();
        system("clear");
        main();
        break;
        default : 
        cout<<red<<"Introdu o varianta existenta!"<<white<<endl; 
        cin.get();
        cin.ignore();
        system("clear");
        main();
    }
}

void delete_sport()
{
    string denumire, categorie;
    int id_sport;
    string categorie_copy, denumire_copy;
    int id_copie;
    string categorie_txt, denumire_txt;
    int id_txt;
    cout << "Introdu categoria sportului: ";
    cin >> categorie;
    cout << "Introdu denumirea sportului: ";
    cin >> denumire;
    cout << "Introdu ID-ul sportului: ";
    cin >> id_sport;
    ifstream fin("Sport.txt");
    bool sport_found = false;
    while (fin >> categorie_copy >> denumire_copy >> id_copie) {
        if (categorie == categorie_copy && denumire == denumire_copy && id_sport == id_copie) {
            sport_found = true;
            break;
        }
    }
    fin.clear(); 
    fin.seekg(0, ios::beg); 
    if (!sport_found) {
        cout << "Acest sport nu este inregistrat in baza de date." << endl;
        fin.close();
        cin.get();
        cin.ignore();
        system("clear");
        main();
        return;
    }
    ofstream fout("Sport_copy.txt",ios::app);
    while (fin >> categorie_txt >> denumire_txt >> id_txt) {
        cout << categorie_txt << " " << denumire_txt << " " << id_txt << endl;
        if (!(categorie_txt == categorie && denumire_txt == denumire && id_txt == id_sport)) {
            fout << categorie_txt << " " << denumire_txt << " " << id_txt << endl;
        }
    }
    fin.close();
    fout.close();
    remove("Sport.txt");
    rename("Sport_copy.txt", "Sport.txt");
    cout << green << "Ai sters cu succes!" << white << endl;
    cin.get();
    cin.ignore();
    system("clear");
    main();

}

void delete_sportiv()
{
    ifstream fin1("Sport.txt");
    string categorie,denumire,categorie1,denumire1;
    string nume,prenume;
    char gen;
    float greutate,inaltime;
    int id_sport,varsta,id_sport1;
    string nume1,prenume1;
    char gen1;
    float greutate1 , inaltime1;
    int varsta1;
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
    ifstream fin("Athlete.txt");
    float inaltime_copie,greutate_copie;
    char gen_copie;
    int id_copie,varsta_copie;
    string nume_copie,prenume_copie;
    ifstream fein("Athlete.txt");
    ofstream fout2("Athlete_copy.txt",ios::app);
    ofstream fout("Athlete.txt",ios::app);
    bool athlete_found = false;
    while (fin >> nume1 >> prenume1 >> gen1 >> greutate1 >> inaltime1 >> varsta1 >> id_sport1) 
    {
        if (nume == nume1 && prenume == prenume1 && gen == gen1 && greutate == greutate1 && inaltime == inaltime1 && varsta == varsta1 && id_sport == id_sport1) 
        {
            athlete_found = true;
            break;
        }
    }

    fin.close();

    if (!athlete_found) {
        cout << red << "Acest sportiv nu este inregistrat in baza de date." << white << endl;
        cin.get();
        cin.ignore();
        system("clear");
        main();
    }

    cout<<green<<"Ai eliminat sportivul cu succes!"<<white<<endl;
    while(fein>>nume_copie>>prenume_copie>>gen_copie>>greutate_copie>>inaltime_copie>>varsta_copie>>id_copie)
        {
            if(nume_copie != nume || prenume_copie != prenume || gen_copie != gen || greutate_copie != greutate || inaltime_copie != inaltime || varsta_copie != varsta || id_copie != id_sport)
            {
                fout2<<nume_copie<<" "<<prenume_copie<<" "<<gen_copie<<" "<<greutate_copie<<" "<<inaltime_copie<<" "<<varsta_copie<<" "<<id_copie<<endl;
            }
        }
    fein.close();
    fout2.close();
    fout.close();
    remove("Athlete.txt");
    rename("Athlete_copy.txt","Athlete.txt");
    cin.get();
    cin.ignore();
    system("clear");
    main();
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
    string categorie,denumire;
    ifstream fin1("Sport.txt");
    bool sportGasit = false;
    ifstream fiin("Athlete.txt");
    while (fin1 >> categorie >> denumire >> s) 
    {
        if (s == id_sport) 
        {
            sportGasit = true;
            break;
        }
    }
    if (!sportGasit) {
        cout << red << "Sport inexistent, creeaza un sport nou din meniul cu numarul 4" << white << endl;
        return;
    }
    fout<<nume<<" "<<prenume<<" "<<gen<<" "<<greutate<<" "<<inaltime<<" "<<varsta<<" "<<id_sport<<endl;
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
        case 7 : actualizeaza_sport(); break;
        case 8 : actualizeaza_sportiv(); break;
        case 9 : total_sport(); break;
        case 10 : afiseaza_alfabetic(); break;
        case 11 : minimax(); break;
        case 12 : average_age(); break;
        case 99 : system("clear"); return 0;
        default : cout<<red<<"Re-introdu optiune deoarece "<<n<<" nu este o optiune valida."<<white; cin.get(); cin.ignore(); main();
    }
}

