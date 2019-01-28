#include <iostream>
#include <math.h>

using namespace std;

void Premier(int max)
{
    int i,j;

    for (i = 7; i < max; i++)
    {
        for (j = 2; i % j; j++);

        if (i == j)
            cout << i << endl;
    }
}

void Premier_2(int max)
{
    int i,j;

    for (i = 7; i < max; i += 2)
    {
        for (j = 3; i % j; j += 2);

        if (i == j)
            cout << i << endl;
    }
}
void Premier_3(int max)
{
    int i,j;
    int mainStep = 2;

    for (i = 7; i < max; i += (mainStep = 6 - mainStep))
    {
        int step = 4;

        for (j = 5; (i % j) && (j * j <= i); j += (step = 6 - step))

        if (i % j)
            cout << i << endl;
    }
}

void Premier_4(int max)
{
    int * dividers = new int[max / 3];

    dividers[0] = 5;

    int size = 1;
    int mainStep = 2;
    int i, j, test;

    for (i = 7; i < max; i += (mainStep = 6 - mainStep))
    {
        for (test = dividers[j = 0]; (i % test) && (test * test <= i); test = dividers[j++])

        if (i % test)
        {
            cout << i << endl;
            dividers[size++] = i;
        }
    }

    delete[] dividers;
}

void Premier_5(int max)
{
    int * dividers = new int[max / 3];

    dividers[0] = 5;

    int size = 1;
    int mainStep = 2;
    int i, j, test;

    for (i = 7; i < max; i += (mainStep = 6 - mainStep))
    {
        for (test = dividers[j = 0]; (i % test) && (test * test <= i); test = dividers[j++])

            if (i % test)
            {
                cout << i << endl;
                dividers[size++] = i;
            }
    }

    delete[] dividers;
}

int main() {

    Premier_3(100);

    return 0;
}