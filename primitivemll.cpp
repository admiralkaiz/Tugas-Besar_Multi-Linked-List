#include "headers/primitivemll.h"
#include "headers/master.h"

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
    if (isEmptyList(L))
    {
        first(L) = p;
    }
    else
    {
        adrSutradara q = first(L);
        while (nextSutradara(q)!=nil) q = nextSutradara(q);
        nextSutradara(q) = p;    
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
        adrSutradara p = first(L);
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
    if (!isEmptyList(L)){
        adrSutradara pS = first(L);
        int count = 1;
        while (pS!=nil)
        {
            cout << "Sutradara " << count << ": " << info(pS) << endl;
            count++;
            pS = nextSutradara(pS);
        }
        cout << endl;
    }
    else
    {
        cout<<"List kosong."<<endl;
    }
}

// Primitif dasar untuk MLL
void addFilmToSutradara(listSutradara &L, string sutradara, adrFilm pF)
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
        if (isNoChild(L,pSutradara)) child(pSutradara) = pF;
        else
        {
            adrFilm q  = child(pSutradara);
            while (nextFilm(q)!=nil) q = nextFilm(q);
            nextFilm(q) = pF;
        }
    }
    else cout << "Maaf, sutradara " << sutradara << " tidak ditemukan." << endl;
}

void deleteFirstSutradara(listSutradara &L, adrSutradara &p)
/*
I.S. terdefinisi listSutradara L (mungkin kosong) dan p sebagai pointer to elmSutradara
F.S elemen pertama dalam listSutradara L dihapus dari L, p menyimpan alamat elemen tersebut
*/
{
    if (!isEmptyList(L))
    {
        p = first(L);
        first(L) = nextSutradara(p);
        nextSutradara(p) = nil;
    }
}

void deleteFirstFilm(listSutradara &L, adrSutradara pS, adrFilm &pF)
/*
I.S. terdefinisi listSutradara L (mungkin kosong), pS sebagai pointer to elmSutradara
    dan pF sebagai pointer to elmFilm
F.S elemen film pertama dalam list child elmSutradara yang ditunjuk pS 
    dihapus dari list child, pF menyimpan alamat elemen tersebut
*/

{
    if (!isEmptyList(L) && !isNoChild(L,pS))
    {
        pF = child(pS);
        child(pS) = nextFilm(pF);
        nextFilm(pF) = nil;
    }
}

void deleteAfterSutradara(listSutradara &L, adrSutradara prev, adrSutradara &p)
/*
I.S. terdefinisi listSutradara L (mungkin kosong) serta prev dan p sebagai pointer to elmSutradara
F.S elemen sutradara setelah elemen yang ditunjuk pointer prev dihapus dari listSutradara L,
    p menyimpan alamat elemen tersebut
*/
{
    if (!isEmptyList(L))
    {
        p = nextSutradara(prev);
        nextSutradara(prev) = nextSutradara(p);
        nextSutradara(p) = nil;
    }
}

void deleteAfterFilm(listSutradara &L, adrSutradara pS, adrFilm prev, adrFilm &pF)
/*
I.S. terdefinisi listSutradara L (mungkin kosong), pS sebagai pointer to elmSutradara,
    serta prev dan pF sebagai pointer to elmFilm
F.S elemen film setelah elemen yang ditunjuk pointer prev dihapus dari list child(pS),
    pF menyimpan alamat elemen tersebut
*/
{
    if (!isEmptyList(L) && !isNoChild(L,pS))
    {
        pF = nextFilm(prev);
        nextFilm(prev) = nextFilm(pF);
        nextFilm(pF) = nil;
    }
}

void emptyChild(listSutradara &L, adrSutradara pS, adrFilm &pF)
/*
I.S terdefinisi listSutradara L, pointer to elmSutradara pS, dan pointer to elmFilm pF
    Asumsi listSutradara L dan list child(pS) tidak kosong 
F.S elemen yang ditunjuk pS tidak memiliki child (list child(pS) menjadi kosong)
*/
{
    while (child(pS)!=nil) deleteFirstFilm(L, pS, pF);
}

void deleteFilm(listSutradara &L, string sutradara, string film, adrFilm &p)
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
                    if (info(nextFilm(q))==film)
                    {
                        deleteAfterFilm(L,pSutradara,q,p);
                        return;
                    } 
                    q = nextFilm(q);
                }
                cout << "Maaf, film " << film << " tidak ditemukan." << endl;
            }
        }
        else cout << "Maaf, sutradara " << sutradara << " tidak ditemukan." << endl;
    }
    else cout << "List kosong" << endl;
}

void deleteSutradara(listSutradara &L, string sutradara, adrSutradara &p, adrFilm &pF)
/*
I.S. terdefinisi sebuah listSutradara L (mungkin kosong) dan string sutradara
F.S. jika terdapat elemen sutradara dengan infotype sama seperti string sutradara,
elemen tersebut akan dihapus dari listSutradara L.
*/
{
    if (!isEmptyList(L))
    {
        if (findSutradara(L, sutradara)==nil)
        {
            cout << "Maaf, sutradara " << sutradara << " tidak ditemukan." << endl;
            return;
        }

        if (info(first(L))==sutradara)
        {
            p = first(L);
            emptyChild(L, p, pF);
            deleteFirstSutradara(L,p);
        } 
        else
        {
            adrSutradara q = first(L);
            while (q!=nil)
            {
                if (info(nextSutradara(q))==sutradara) 
                {
                    p = nextSutradara(q);
                    emptyChild(L, p, pF);
                    deleteAfterSutradara(L,q,p);
                    return;
                }
                q = nextSutradara(q);
            }
        }
    }
    else cout << "List kosong." << endl;
}

void showAllData(listSutradara L)
/*
I.S. terdefinisi sebuah listSutradara L yang mungkin kosong
F.S. jika L tidak kosong maka cetak ke layar semua elemen parent (sutradara)
dari L beserta elemen child dari masing-masing elemen parent atau "List kosong"
jika L kosong
*/
{
    if(!isEmptyList(L)){
        int countF, countS;
        countS = 1;
        adrSutradara pS = first(L);
        while(pS!=nil)
        {
            countF = 1;
            cout << "Sutradara "<< countS << ": " << info(pS) << endl;
            adrFilm pF = child(pS);
            while (pF!=nil)
            {
                cout << "Film " << countF << ". " << info(pF) << endl;
                countF++;
                pF = nextFilm(pF);
            }
            cout<<endl;
            countS++;
            pS = nextSutradara(pS);
        }
    }else{
        cout<<"List Kosong."<<endl;
    }
}
