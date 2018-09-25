#include <iostream>

#include "Ensemble.h"

using namespace std;

int main() {

    int t[] = {2, 6, 4, 4, 4, 4, 6, 9};
    Ensemble ensemble1 = Ensemble(t, 8);

    ensemble1.Afficher();
    cout << "TEST  +3 " << ensemble1.Ajuster(3) << "\r\n";
    ensemble1.Afficher();
    cout << "TEST  -5 " << ensemble1.Ajuster(-5) << "\r\n";
    ensemble1.Afficher();
    cout << "TEST   0 " << ensemble1.Ajuster(0) << "\r\n";
    ensemble1.Afficher();
    cout << "TEST -10 " << ensemble1.Ajuster(-10) << "\r\n";

    ensemble1.Afficher();

    return 0;
}
