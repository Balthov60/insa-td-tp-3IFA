#include <stdio.h>
#include <math.h>

int main()
{
    // INPUT

    int size;
    scanf("%d", &size);

    int valuesQty = 0;
    int values[100];

    do {
        scanf("%d", &values[valuesQty]);

        valuesQty++;
    }
    while (values[valuesQty - 1] != -1);

    valuesQty--;

    // INIT

    int solver[valuesQty + 1][size + 1];

    for (int i = 0; i < valuesQty; i++)
        solver[i][0] = 1;

    for (int i = 1; i < size + 1; i++)
        solver[0][i] = 0;

    // SOLVE

    for (int i = 1; i < valuesQty + 1; i++)
    {
        for (int j = 1; j < size + 1; j++)
        {
            solver[i][j] = 0;

            if (solver[i - 1][j] == 1)
            {
                solver[i][j] = 1;
                continue;
            }

            if (j - values[i] < 0)
                continue;

            if (solver[i - 1][j - values[i]] == 1)
            {
                solver[i][j] = 1;
                continue;
            }
        }
    }

    for (int j = 0; j < size + 1; j++)
    {
        printf("%d ", j);
    }
    printf("\r\n");

    for (int i = 0; i < valuesQty; i++)
    {
        printf("%d ", values[i]);

        for (int j = 0; j < size + 1; j++)
        {
            printf("%d ", solver[i][j]);
        }

        printf("\r\n");
    }

    // RESULT

    printf("%s\r\n", (solver[valuesQty - 1][size] == 1) ? "OUI" : "NON");
    return 0;
}