#include "headers/menu.h"

void showTitle()
/*
I.S -
F.S tercetak sebuah judul program dan nama pembuatnya
*/
{
    cout << "=============================================" << endl;
    cout << "*       _____ ___ _     __  __  ____        *" << endl;
    cout << "*      |  ___|_ _| |   |  \\/  / ___|        *" << endl;
    cout << "*      | |_   | || |   | |\\/| \\___ \\        *" << endl;
    cout << "*      |  _|  | || |___| |  | |___) |       *" << endl;
    cout << "*      |_|   |___|_____|_|  |_|____/        *" << endl;
    cout << "*                                           *" << endl;
    cout << "*           By: Kaisar and Satya            *" << endl;
    cout << "=============================================" << endl;
    cout << endl;
}

void showMenu()
/*
I.S -
F.S tercetak daftar menu seleksi operasi yang ingin dijalankan user
*/
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

int selectMenu()
/*
Mengembalikan sebuah integer yang menyatakan pilihan operasi yang 
akan dijalankan user. Input akan terus diulang hingga valid apabila
user memasukkan integer yang tidak valid.
*/
{
    int command = -1;
    while (command < 0 || command > 9)
    {
        cout << "> Masukkan command (9 untuk tampilkan list command) % ";
        cin >> command;
        if (command < 0 || command > 9) cout << "Invalid input!" << endl;
    }
    return command;
}
