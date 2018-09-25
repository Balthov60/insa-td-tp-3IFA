#include <iostream>

#include "Ensemble.h"

using namespace std;

int main() {

    int t[] = {2, 4, 4, 4, 6, 9};
    Ensemble ensemble1 = Ensemble(t, 6);

    int t2[] = {20, 60};
    Ensemble ensemble2 = Ensemble(t2, 2);

    ensemble1.Retirer(1);
    cout << "QTY : "<< ensemble1.Intersection(ensemble2) << endl;
    ensemble1.Afficher();

    return 0;
}
