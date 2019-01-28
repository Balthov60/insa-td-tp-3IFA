#include <iostream>
#include <stdio.h>
#include <iomanip>

int main()
{
    // INPUT

    int recipientSize;
    scanf("%d", &recipientSize);

    int itemQty = 0;
    int input[101];
    do
    {
        scanf("%d", &input[itemQty]); // weight
        itemQty++;
    }
    while (input[itemQty - 1] != -1);

    itemQty--;

    // INIT

    int solveur[recipientSize + 1][itemQty];    // On cherche si le nombre "i"(0 -> recipientSize)
                                            // est realisable en utilisant 0/1 fois les input[0 -> j(0 -> itemQty)]

    for (int i = 0; i <= recipientSize; i++)         // On va parcourir le tableau via itemQty<recipientSize>
        solveur[i][0] = (i == input[0]) ? 1 : 0;    // On initialise donc la première ligne de recipientSize

    // SOLVE : Peut on remplir le sac completement en utilisant tout ou partie des inputs
    //
    // Pour chaque groupement d'objet (objet 1, 1 et 2, 1 et 2 et 3, ..., 1 et 2 et 3 et ... et itemQty)
    // On regarde si on peut remplir completement i (1 -> recipientSize) en les utilisant 0 ou 1 fois.

    for (int j = 1; j < itemQty; j++)
    {
        for (int i = 1; i <= recipientSize; i++)
        {
            if (solveur[i][j - 1] == 1 || input[j] == i) // Si avec un item de moins c'est ok alors c'est tjr possible
            {                                            // OU Si l'objet fais la taille du sac c'est possible;
                solveur[i][j] = 1;
                continue;
            }

            if (i - input[j] >= 0 && solveur[i - input[j]][j - 1] == 1)  // i - input[j] >> Complement pour atteindre "i" avec input[j]
            {                                                            // SI on peut faire le complement avec j - 1 objets.
                solveur[i][j] = 1;
                continue;
            }

            solveur[i][j] = 0;
        }
    }

    // OUTPUT
    printf("%s\r\n", (solveur[recipientSize][itemQty - 1] == 1) ? "OUI" : "NON");

    return 0;
}