/*
Filename: primitivemll.h
Deskripsi:
File header primitivemll.h berisi prototipe fungsi dan prosedur
primitif dalam mll (createlist, createelement, insert, delete, print).
Implementasi untuk file ini terdapat dalam file primitivemll.cpp
*/

#ifndef MLLFILM_H_INCLUDED
#define MLLFILM_H_INCLUDED

#include "master.h"


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


// Menu and User Interface


#endif 
