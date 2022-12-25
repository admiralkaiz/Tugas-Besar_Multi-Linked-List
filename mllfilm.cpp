#include "mllfilm.h"

// Fungsionalitas dasar
// Untuk menginisialisasi list atau elemen baru
listSutradara createParentList()
{
    listSutradara L;
    first(L) = nil;
    return L;
}

adrSutradara createElmSutradara(string newSutradara)
{
    adrSutradara p = new elmSutradara;
    info(p) = newSutradara;
    nextSutradara(p) = nil;
    child(p) = nil;
    return p;
}

adrFilm createElmFilm(string newFilm)
{
    adrFilm p = new elmFilm;
    info(p) = newFilm;
    nextFilm(p) = nil;
    return p;
}

// Subprogram tambahan untuk memudahkan pekerjaan
bool isEmptyList(listSutradara L)
{
    return first(L)==nil;
}

bool isNoChild(listSutradara L, adrSutradara p)
{
    return child(p)==nil;
}

// Primitif dasar untuk SLL listSutradara
void addSutradara(listSutradara &L, adrSutradara p)
{
    ;
}

adrSutradara findSutradara(listSutradara L, string sutradara)
{
    ;
}

void showListSutradara(listSutradara L)
{
    ;
}

// Primitif dasar untuk MLL
void addFilmToSutradara(listSutradara &L, string sutradara, adrFilm p)
{
    ;
}

void deleteFilm(listSutradara &L, string sutradara, string film)
{
    ;
}

void deleteSutradara(listSutradara &L, string sutradara)
{
    ;
}

void showAllData(listSutradara L)
{
    ;
}

int filmCount(listSutradara L, adrSutradara p)
{
    int n = 0;
    if (!isNoChild(L, p))
    {
        adrFilm q = child(p);
        while (q!=nil)
        {
            n++;
            q = nextFilm(q);
        }
    }
    return n;
}

void printCount(listSutradara L)
{
    if (!isEmptyList(L))
    {
        adrSutradara p = first(L);
        while (p!=nil)
        {
            cout << info(p) << ": " << filmCount(L, p) << " film" << endl;
            p = nextSutradara(p);
        }
    }
    else cout << "List Kosong" << endl;
}

void mostFilms(listSutradara L)
{
    ;
}

void leastFilms(listSutradara L)
{
    ;
}
