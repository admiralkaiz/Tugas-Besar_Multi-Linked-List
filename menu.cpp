#include "headers/menu.h"

void showTitle()
{
    cout << "===================================" << endl;
    cout << "*  _____ ___ _     __  __  ____   *" << endl;
    cout << "* |  ___|_ _| |   |  \\/  / ___|   *" << endl;
    cout << "* | |_   | || |   | |\\/| \\___ \\   *" << endl;
    cout << "* |  _|  | || |___| |  | |___) |  *" << endl;
    cout << "* |_|   |___|_____|_|  |_|____/   *" << endl;
    cout << "*                                 *" << endl;
    cout << "*      By: Kaisar and Satya       *" << endl;
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