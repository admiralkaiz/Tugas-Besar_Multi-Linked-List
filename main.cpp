#include "mllfilm.h"

int main() 
{
    listSutradara   L = createParentList();
    adrSutradara    pSutradara;
    adrFilm         pFilm;
    char            menuSelection;

    showTitle();
    showMenu();
    menuSelection = selectMenu();

    while (menuSelection!='0')
    {
        switch (menuSelection)
        {
            case '1':
                break;
            case '2':
                break;
            case '3':
                break;
            case '4':
                break;
            case '5':
                break;
                break;
            case '6':
                break;
            case '7':
                break;
            case '8':
                break;
            case '9':
                break;
            default:
                cout << "Invalid input!" << endl;
        }
    }

    cout << "Anda telah keluar dari program" << endl;
    return 0;
}
