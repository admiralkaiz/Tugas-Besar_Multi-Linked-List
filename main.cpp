#include "headers/primitivemll.h"
#include "headers/advancedmll.h"
#include "headers/menu.h"

int main() 
{
    listSutradara   L = createParentList();
    adrSutradara    pSutradara;
    adrFilm         pFilm;
    int             n, menuSelection;
    string          namaSutradara, judulFilm;
    char            opt;

    showTitle();
    showMenu();
    menuSelection = selectMenu();

    while (menuSelection!=0)
    {
        switch (menuSelection)
        {
            case 1:
                cout << "Masukkan banyaknya input: ";
                cin >> n;
                for (int i=0; i<n; i++)
                {
                    cout << "Masukkan nama sutradara baru " << i+1 << ": ";
                    cin >> namaSutradara;
                    pSutradara = createElmSutradara(namaSutradara);
                    addSutradara(L, pSutradara);
                }
                cout << endl;
                break;

            case 2:
                cout << "Masukkan nama sutradara yang akan ditambahkan film: ";
                cin >> namaSutradara;
                cout << "Masukkan banyaknya input: ";
                cin >> n;
                for (int i=0; i<n; i++) 
                {
                    cout << "Masukkan judul film "<< i+1 << ": "; 
                    cin >> judulFilm;   
                    pFilm = createElmFilm(judulFilm);   
                    addFilmToSutradara(L, namaSutradara, pFilm);    
                }
                cout << endl;
                break;

            case 3:
                cout << "Masukkan nama sutradara yang akan dihapus: ";
                cin >> namaSutradara;
                deleteSutradara(L,namaSutradara,pSutradara,pFilm);
                cout << endl;
                break;

            case 4:
                cout << "Masukkan nama film yang akan dihapus: ";
                cin >> judulFilm;
                cout << "Masukkan nama sutradara yang memproduksi film " << judulFilm << ": ";
                cin >> namaSutradara;
                deleteFilm(L, namaSutradara, judulFilm, pFilm);
                cout << endl;
                break;

            case 5:
                cout << "Apakah Anda ingin menampilkan data filmnya juga?(Y/N) ";
                cin >> opt;
                while (opt!='Y'&&opt!='N')
                {
                    cout << "Ulangi input. Apakah Anda ingin menampilkan data filmnya juga?(Y/N) ";
                    cin >> opt;
                }
                if (opt=='Y')
                {
                    cout << "Menampilkan list sutradara beserta filmnya..." << endl;
                    showAllData(L);
                }
                else if (opt=='N')
                {
                    cout << "Menampilkan list sutradara (tanpa film)..." << endl;
                    showListSutradara(L);
                }                
                cout << endl;
                break;

            case 6:
                cout << "Menampilkan seluruh sutradara beserta banyaknya film yang dibuat..." << endl;
                printCount(L);
                cout << endl;
                break;

            case 7:
                mostFilms(L);
                cout << endl;
                break;

            case 8:
                leastFilms(L);
                cout << endl;
                break;

            case 9:
                showMenu();
                cout << endl;
                break;
            default:
                cout << "Invalid input!" << endl;
        }
        menuSelection = selectMenu();
    }

    cout << endl << "Anda telah keluar dari program" << endl;
    return 0;
}
