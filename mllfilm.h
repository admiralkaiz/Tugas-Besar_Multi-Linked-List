#ifndef MLLFILM_H_INCLUDED
#define MLLFILM_H_INCLUDED

#include <iostream>
using namespace std;

#define info(p) (p)->info
#define nextSutradara(p) (p)->nextSutradara
#define child(p) (p)->child
#define nextFilm(q) (q)->nextFilm
#define first(L) ((L).first)
#define nil NULL

// Abstract Data Type
typedef string infoSutradara;
typedef string infoFilm;

typedef struct elmSutradara *adrSutradara;
typedef struct elmFilm *adrFilm;

struct elmSutradara {
    infoSutradara info;
    adrSutradara nextSutradara;
    adrFilm child;
};
struct elmFilm {
    infoFilm info;
    adrFilm nextFilm;
};

struct listSutradara {
    adrSutradara first;  
};

// Fungsionalitas dasar
// Untuk menginisialisasi list atau elemen baru
listSutradara createParentList();
adrSutradara createElmSutradara(string newSutradara);
adrFilm createElmFilm(string newFilm);

// Subprogram tambahan untuk memudahkan pekerjaan
bool isEmptyList(listSutradara L);
bool isNoChild(listSutradara L, adrSutradara p);

// Primitif dasar untuk SLL listSutradara
void addSutradara(listSutradara &L, adrSutradara p);
adrSutradara findSutradara(listSutradara L, string sutradara);
void showListSutradara(listSutradara L);

// Primitif dasar untuk MLL
void addFilmToSutradara(listSutradara &L, string sutradara, adrFilm p);
void deleteFilm(listSutradara &L, string sutradara, string film);
void deleteSutradara(listSutradara &L, string sutradara);
void showAllData(listSutradara L);
int filmCount(listSutradara L, adrSutradara p);
void printCount(listSutradara L);
void mostFilms(listSutradara L);
void leastFilms(listSutradara L);

// Menu and User Interface
void showTitle();
void showMenu();
char selectMenu();

#endif 
