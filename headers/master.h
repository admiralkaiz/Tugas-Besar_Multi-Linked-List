/*
Filename: master.h
Deskripsi:
File header master.h berisi ADT dan include file header iostream yang
dibutuhkan sebagai input/output supaya program mll berjalan sebagaimana
mestinya 
*/

#ifndef MASTER_H_INCLUDED
#define MASTER_H_INCLUDED

#include <iostream>
using namespace std;

#define info(p) (p)->info
#define nextSutradara(p) (p)->nextSutradara
#define child(p) (p)->child
#define nextFilm(q) (q)->nextFilm
#define first(L) ((L).first)
#define nil NULL

/******************
ABSTRACT DATA TYPE
******************/
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

#endif
