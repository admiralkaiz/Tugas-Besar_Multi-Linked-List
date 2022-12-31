#include "headers/primitivemll.h"

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
    if (isEmpty(L))
    {
        first(L) = p;
    }
    else
    {
        next(p) = first(L)
        first(L) = p;    
    }
}

adrSutradara findSutradara(listSutradara L, string sutradara)
/*
Mengembalikan alamat dari elemen parent (sutradara) yang memiliki
infotype sama dengan parameter string sutradara.
Jika tidak ditemukan atau list kosong, fungsi mengembalikan nilai NIL.
*/
{
    if(!isEmptyList(L)){
        adrFilm p = first(L);
        while(p!=nil){
            if (info(p)==sutradara){
                return p;
            }   
            p = nextSutradara(p);
        }
    }
    return nil;
}

void showListSutradara(listSutradara L)
/*
I.S. terdefinisi listSutradara L yang mungkin kosong
F.S. tercetak ke layar konsol infotype dari seluruh elemen
yang terdapat dalam list atau "List kosong" apabila listSutradara L kosong
*/
{
    if (!isEmpty(L)){
        adrSutradara p = first(L);
        while (p!=nil)
        {
            cout << infoSutradara(p) << " ";
            p = next(p);
        }
        cout << endl;
    }
    else
    {
        cout<<"List kosong"<<endl;
    }
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
    adrSutradara pSutradara = findSutradara(L, sutradara);
    if (pSutradara!=nil)
    {
        if (isNoChild(pSutradara)) child(pSutradara) = p;
        else
        {
            adrFilm q  = child(pSutradara);
            while (nextFilm(q)!=nil) q = nextFilm(q);
            nextFilm(q) = p;
        }
    }
}

void deleteFilm(listSutradara &L, string sutradara, string film, adrFilm p)
/*
I.S. terdefinisi sebuah listSutradara L (mungkin kosong), string sutradara, dan
string film
F.S. jika terdapat elemen sutradara dalam listSutradara L dengan infotype
sama seperti string sutradara dan terdapat elemen list child dari 
elemen parent tersebut memiliki infotype yang sama dengan string film, 
elemen child tersebut akan dihapus dari list child 
*/
{
    if (!isEmptyList(L))
    {
        adrSutradara pSutradara = findSutradara(L, sutradara);
        if (pSutradara!=nil)
        {
            if (info(child(pSutradara))==film) deleteFirstFilm(L,pSutradara,p);
            else
            {
                adrFilm q = child(pSutradara);
                while (q!=nil)
                {
                    if (info(nextFilm(q))==film) deleteAfterFilm(L,pSutradara,q,p);
                    q = nextFilm(q);
                }
            }
        }
    }
}

void deleteSutradara(listSutradara &L, string sutradara, adrSutradara p);
/*
I.S. terdefinisi sebuah listSutradara L (mungkin kosong) dan string sutradara
F.S. jika terdapat elemen sutradara dengan infotype sama seperti string sutradara,
elemen tersebut akan dihapus dari listSutradara L.
*/
{
    if (!isEmptyList(L))
    {
        if (info(first(L))==sutradara) deleteFirstSutradara(L,p);
        else
        {
            adrSutradara q = first(L);
            while (q!=nil)
            {
                if (info(nextSutradara(q))==sutradara) deleteAfterSutradara(L,q,p);
                q = nextSutradara(q);
            }
        }
    }
}

void showAllData(listSutradara L)
/*
I.S. terdefinisi sebuah listSutradara L yang mungkin kosong
F.S. jika L tidak kosong maka cetak ke layar semua elemen parent (sutradara)
dari L beserta elemen child dari masing-masing elemen parent atau "List kosong"
jika L kosong
*/
{
    if(!isEmpty(L)){
        adrSutradara pS = first(L);
        while(pS!=nil)
        {
            cout << "Sutradara: "<< info(pS) << endl << "Film: " << endl;
            adrFilm pF = child(pS);
            while (pF!=nil)
            {
                cout << info(pF) << endl;
                pF = nextFilm(pF);
            }
            cout<<endl;
            pS = nextSutradara(pS);
        }
    }else{
        cout<<"List Kosong"<<endl;
    }
}
