#include <iostream>
#include <stdio.h>

int MIN(int a, int b)
{
    return (a <= b) ? a : b;
}

int main()
{
    // INPUT

    int recipientSize;               // RECIPIENT SIZE
    scanf("%d", &recipientSize);

    int totalFlaskQty;                // FLASK QTY
    scanf("%d", &totalFlaskQty);

    int type1FlaskQty = 0;
    int inputType1[totalFlaskQty];

    int type2FlaskQty = 0;
    int inputType2[totalFlaskQty];

    int temp[2];
    for (int i = 0; i < totalFlaskQty; i++)
    {
        scanf("%d", &temp[0]);  // SIZE
        scanf("%d", &temp[1]);  // TYPE

        if (temp[1] == 1)
        {
            inputType1[type1FlaskQty] = temp[0];
            type1FlaskQty++;
        }
        else
        {
            inputType2[type2FlaskQty] = temp[0];
            type2FlaskQty++;
        }
    }

    //////////// SOLVER 1

    // INIT

    int solveur1[recipientSize + 1][type1FlaskQty];
    int finalSet1[type1FlaskQty * type1FlaskQty];
    int finalSet1Size = 0;

    for (int i = 0; i <= recipientSize; i++)
    {
        if (i == inputType1[0])
        {
            solveur1[i][0] = 1;
            finalSet1[finalSet1Size] = i;
            finalSet1Size++;
        }
        else
            solveur1[i][0] = 0;
    }

    // SOLVEUR

    for (int j = 1; j < type1FlaskQty; j++)
    {
        for (int i = 1; i <= recipientSize; i++)
        {
            if (inputType1[j] == i)
            {
                solveur1[i][j] = 1;
                finalSet1[finalSet1Size] = i;
                finalSet1Size++;
                continue;
            }
            if (solveur1[i][j - 1] == 1) // Si avec un item de moins c'est ok alors c'est tjr possible
            {                                            // OU Si l'objet fais la taille du sac c'est possible;
                solveur1[i][j] = 1;
                continue;
            }

            if (i - inputType1[j] >= 0 && solveur1[i - inputType1[j]][j - 1] == 1)  // i - input[j] >> Complement pour atteindre "i" avec input[j]
            {                                                            // SI on peut faire le complement avec j - 1 objets.
                solveur1[i][j] = 1;
                finalSet1[finalSet1Size] = i;
                finalSet1Size++;
                continue;
            }

            solveur1[i][j] = 0;
        }
    }

    //////////// SOLVER 2

    // INIT

    int solveur2[recipientSize + 1][type2FlaskQty];
    int finalSet2[type2FlaskQty * type2FlaskQty];
    int finalSet2Size = 0;

    for (int i = 0; i <= recipientSize; i++)
    {
        if (i == inputType2[0])
        {
            solveur2[i][0] = 1;
            finalSet2[finalSet2Size] = i;
            finalSet2Size++;
        }
        else 
            solveur2[i][0] = 0;
    }

    // SOLVEUR

    for (int j = 1; j < type2FlaskQty; j++)
    {
        for (int i = 1; i <= recipientSize; i++)
        {
            if (inputType2[j] == i)
            {
                solveur2[i][j] = 1;
                finalSet2[finalSet2Size] = i;
                finalSet2Size++;

                continue;
            }
            if (solveur2[i][j - 1] == 1) // Si avec un item de moins c'est ok alors c'est tjr possible
            {                                            // OU Si l'objet fais la taille du sac c'est possible;
                solveur2[i][j] = 1;
                continue;
            }

            if (i - inputType2[j] >= 0 && solveur2[i - inputType2[j]][j - 1] == 1)  // i - input[j] >> Complement pour atteindre "i" avec input[j]
            {                                                            // SI on peut faire le complement avec j - 1 objets.
                solveur2[i][j] = 1;
                finalSet2[finalSet2Size] = i;
                finalSet2Size++;

                continue;
            }

            solveur2[i][j] = 0;
        }
    }

    ////// FINAL SOLVING

    int max = 0;
    for (int i = 0; i < finalSet1Size; i++)
    {
        for (int j = 0; j < finalSet2Size; j++)
        {
            if (finalSet1[i] + finalSet2[j] <= recipientSize)
            {
                if (max < MIN(finalSet1[i], finalSet2[j]) * 2)
                    max = MIN(finalSet1[i], finalSet2[j]) * 2;
            }
        }
    }

    printf("%d\r\n", max);

    return 0;
}