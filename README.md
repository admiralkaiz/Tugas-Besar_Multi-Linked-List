# Tugas Besar Multi-Linked List

## Kelompok
Nama Kelompok: Mogekov Hashasky II

Anggota Kelompok:
- Kaisar Kertarajasa (1301213276)
- Satya Rayyis Baruna (1301213316)

## Rincian Tugas
Membuat implementasi dari _multi-linked list_ dengan ketentuan sebagai berikut:
- Tipe Multi-linked list: Tipe B (1 to N relation)
- Topik: Film
- Deskripsi: Aplikasi yang dibuat mampu merelasikan data sutradara ke film. Seorang sutradara bisa membuat satu atau lebih film, tetapi, asumsi, satu film hanya bisa dibuat oleh seorang sutradara saja.

## Abstract Data Type
```
type infoSutradara   : string
type infoFilm    : string

type adr_Sutradara   : pointer to elmSutradara
type adr_Film    : pointer to elmFilm

type elmSutradara : <
    info   : infoSutradara
    nextSutradara : adr_Sutradara
    child   : adr_Film >

type elmFilm : <
    info   : infoFilm
    nextFilm : adr_Film >
 
type listSutradara <
    first   : adr_Sutradara >
 ```

## Algoritma, Fungsionalitas Dasar, dan Implementasinya
```
function createParentList()-> listSutradara


function createElmSutradara( newSutradara : string)-> adrSutradara

function createElmFilm(newFilm : string)-> adrFilm
 

function isEmpty(L : listSutradara)-> bool

function isNoChild(L : listSutradara, p : adrSutradara)-> bool

procedure addSutradara(in/out L : listSutradara, in p : adrSutradara)

function findSutradara(L : listSutradara, sutradara : string)-> adrSutradara

procedure showListSutradara(in L : listSutradara)

  
procedure addFilmToSutradara(in/out L : listSutradara, in sutradara : string, in film : string)

procedure deleteFilm(in/out L : listSutradara, in sutradara : string, in  film : string)

procedure deleteSutradara(in/out L : listSutradara, in sutradara : string)

procedure showAllData(in L : listSutradara)

function filmCount(L : listSutradara, p : adrSutradara)-> integer

procedure printCount(L : listSutradara)

procedure mostFilm(L : listSutradara)

procedure leastFilm(L : listSutradara)
```
