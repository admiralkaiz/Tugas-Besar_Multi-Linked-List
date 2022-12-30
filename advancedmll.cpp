#include "headers/advancedmll.h"

int filmCount(listSutradara L, adrSutradara p)
/*
Mengembalikan 
*/
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
    if (!isEmptyList(L))
    {
        adrSutradara p, pMax;
        pMax = first(L);
        p = next(pMax);
        while (p!=nil)
        {
            if (filmCount(L, pMax) < filmCount(L, p)) pMax = p; 
            p = nextSutradara(p);
        }
        cout << "Banyaknya film paling banyak diperoleh oleh sutradara "\
             << info(pMax) << " dengan jumlah film " << filmCount(L, pMax) << endl;
    }
    else cout << "List Kosong" << endl;
}

void leastFilms(listSutradara L)
{
    if (!isEmptyList(L))
    {
        adrSutradara p, pMin;
        pMin = first(L);
        p = next(pMin);
        while (p!=nil)
        {
            if (filmCount(L, pMin) > filmCount(L, p)) pMin = p; 
            p = nextSutradara(p);
        }
        cout << "Banyaknya film paling sedikit diperoleh oleh sutradara "\
             << info(pMin) << " dengan jumlah film " << filmCount(L, pMin) << endl;
    }
    else cout << "List Kosong" << endl;
}
