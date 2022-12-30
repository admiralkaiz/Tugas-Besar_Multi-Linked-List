/*
Filename: advancedmll.h
Deskripsi:
File header advancedmll.h berisi prototipe fungsi dan prosedur
nonprimitif dalam mll, seperti menamilkan banyaknya child untuk
setiap elemen list parent, menampilkan info elemen parent dengan
child terbanyak dan yang paling sedikit.
Implementasi untuk file ini terdapat dalam file advancedmll.cpp
*/

#ifndef ADVANCEDMLL_H_INCLUDED
#define ADVANCEDMLL_H_INCLUDED

#include "primitivemll.h"

int filmCount(listSutradara L, adrSutradara p);
void printCount(listSutradara L);
void mostFilms(listSutradara L);
void leastFilms(listSutradara L);

#endif