#include "headers/advancedmll.h"
#include "headers/master.h"

int filmCount(listSutradara L, adrSutradara p)
/*
Mengembalikan banyaknya film yang diproduksi sutradara
yang ditunjuk pointer p 
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
/*
I.S. terdefinisi listSutradara L yang mungkin kosong
F.S. tercetak ke layar seluruh elemen sutradara dalam listSutradara L
    beserta banyaknya child dari masing-masing elemen
*/
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
    else cout << "List Kosong." << endl;
}

void mostFilms(listSutradara L)
/*
I.S. terdefinisi listSutradara L yang mungkin kosong
F.S. tercetak ke layar nama sutradara dengan banyaknya film
    terbanyak beserta banyaknya film yang ia buat
*/
{
    if (!isEmptyList(L))
    {
        adrSutradara p, pMax;
        pMax = first(L);
        p = nextSutradara(pMax);
        while (p!=nil)
        {
            if (filmCount(L, pMax) < filmCount(L, p)) pMax = p; 
            p = nextSutradara(p);
        }
        cout << "Banyaknya film paling banyak diperoleh oleh sutradara "\
             << info(pMax) << " dengan jumlah film " << filmCount(L, pMax) << endl;
    }
    else cout << "List Kosong." << endl;
}

void leastFilms(listSutradara L)
/*
I.S. terdefinisi listSutradara L yang mungkin kosong
F.S. tercetak ke layar nama sutradara dengan banyaknya film
    paling sedikit beserta banyaknya film yang ia buat
*/
{
    if (!isEmptyList(L))
    {
        adrSutradara p, pMin;
        pMin = first(L);
        p = nextSutradara(pMin);
        while (p!=nil)
        {
            if (filmCount(L, pMin) > filmCount(L, p)) pMin = p; 
            p = nextSutradara(p);
        }
        cout << "Banyaknya film paling sedikit diperoleh oleh sutradara "\
             << info(pMin) << " dengan jumlah film " << filmCount(L, pMin) << endl;
    }
    else cout << "List Kosong." << endl;
}
