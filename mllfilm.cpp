#include "mllfilm.h"

// Fungsionalitas dasar
// Untuk menginisialisasi list atau elemen baru
listSutradara createParentList()
/*
Mengembalikan sebuah parent list kosong
*/
{
    listSutradara L;
    first(L) = nil;
    return L;
}

adrSutradara createElmSutradara(string newSutradara)
/*
Mengembalikan sebuah elemen parent (sutradara) baru 
dengan infotype berupa string newSutradara
*/
{
    adrSutradara p = new elmSutradara;
    info(p) = newSutradara;
    nextSutradara(p) = nil;
    child(p) = nil;
    return p;
}

adrFilm createElmFilm(string newFilm)
/*
Mengembalikan sebuah pointer ke elemen child (film) baru 
dengan infotype berupa string newFilm
*/
{
    adrFilm p = new elmFilm;
    info(p) = newFilm;
    nextFilm(p) = nil;
    return p;
}

// Subprogram tambahan untuk memudahkan pekerjaan
bool isEmptyList(listSutradara L)
/*
Mengembalikan nilai boolean apakah list L kosong atau tidak
*/
{
    return first(L)==nil;
}

bool isNoChild(listSutradara L, adrSutradara p)
/*
Mengembalikan nilai boolean apakah elemen parent (sutradara)
yang ditunjuk pointer p memiliki child (film) atau tidak
*/
{
    return child(p)==nil;
}

// Primitif dasar untuk SLL listSutradara
void addSutradara(listSutradara &L, adrSutradara p)
/*
I.S. Terdefinisi sebuah listSutradara L (mungkin kosong)
dan pointer ke elemen parent (sutradara) p
F.S. p sudah dimasukkan ke akhir listSutradara
*/
{
    ;
}

adrSutradara findSutradara(listSutradara L, string sutradara)
/*
Mengembalikan alamat dari elemen parent (sutradara) yang memiliki
infotype sama dengan parameter string sutradara.
Jika tidak ditemukan atau list kosong, fungsi mengembalikan nilai NIL.
*/
{
    ;
}

void showListSutradara(listSutradara L)
/*
I.S. terdefinisi listSutradara L yang mungkin kosong
F.S. tercetak ke layar konsol infotype dari seluruh elemen
yang terdapat dalam list atau "List kosong" apabila listSutradara L kosong
*/
{
    ;
}

// Primitif dasar untuk MLL
void addFilmToSutradara(listSutradara &L, string sutradara, adrFilm p)
/*
I.S. terdefinisi listSutradara L (mungkin kosong), string sutradara, dan
pointer ke elemen child (film) p
F.S. p telah ditambahkan ke bagian akhir list child dari elemen parent (sutradara) 
dengan infotype sama dengan parameter string sutradara, 
atau menjadi elemen pertama list child dari jika list child dari elemen parent
tersebut kosong
*/
{
    ;
}

void deleteFilm(listSutradara &L, string sutradara, string film)
/*
I.S. terdefinisi sebuah listSutradara L (mungkin kosong), string sutradara, dan
string film
F.S. jika terdapat elemen sutradara dalam listSutradara L dengan infotype
sama seperti string sutradara dan terdapat elemen list child dari 
elemen parent tersebut memiliki infotype yang sama dengan string film, 
elemen child tersebut akan dihapus dari list child 
*/
{
    ;
}

void deleteSutradara(listSutradara &L, string sutradara)
/*
I.S. terdefinisi sebuah listSutradara L (mungkin kosong) dan string sutradara
F.S. jika terdapat elemen sutradara dengan infotype sama seperti string sutradara,
elemen tersebut akan dihapus dari listSutradara L.
*/
{
    ;
}

void showAllData(listSutradara L)
/*
I.S. terdefinisi sebuah listSutradara L yang mungkin kosong
F.S. jika L tidak kosong maka cetak ke layar semua elemen parent (sutradara)
dari L beserta elemen child dari masing-masing elemen parent atau "List kosong"
jika L kosong
*/
{
    ;
}

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

void showTitle()
{
    cout << "===================================" << endl;
    cout << "*  _____ ___ _     __  __  ____   *" << endl;
    cout << "* |  ___|_ _| |   |  \\/  / ___|   *" << endl;
    cout << "* | |_   | || |   | |\\/| \\___ \\   *" << endl;
    cout << "* |  _|  | || |___| |  | |___) |  *" << endl;
    cout << "* |_|   |___|_____|_|  |_|____/   *" << endl;
    cout << endl;
    cout << "       By: Kaisar and Satya        " << endl;
    cout << "===================================" << endl;
    cout << endl;
}

void showMenu()
{
    cout << "[MENU SELECTION]" << endl;
    cout << "[1] Tambahkan data sutradara" << endl;
    cout << "[2] Tambahkan data film pada sutradara" << endl;
    cout << "[3] Hapus data sutradara" << endl;
    cout << "[4] Hapus data film dari sutradara" << endl;
    cout << "[5] Tampilkan seluruh data sutradara dan film" << endl;
    cout << "[6] Tampilkan data banyaknya film yang dibuat masing-masing sutradara" << endl;
    cout << "[7] Tampilkan data sutradara dengan jumlah film paling banyak" << endl;
    cout << "[8] Tampilkan data sutradara dengan jumlah film paling sedikit" << endl;
    cout << "[9] Tampilkan menu" << endl;
    cout << "[0] Keluar program" << endl;
    cout << endl;
}

char selectMenu()
{
    char command = 'x';
    while (command > '0' || command < '9')
    {
        cout << "Masukkan command (9 untuk tampilkan list command) > ";
        cin >> command;
    }
    return command;
}
