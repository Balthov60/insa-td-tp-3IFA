/*************************************************************************
                           Ensemble  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Ensemble> (fichier Ensemble.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Ensemble.h"

//------------------------------------------------------------- Constantes

/*********************************/
/******** Public - Methods *******/
/*********************************/

void Ensemble::Afficher()
{
    cout << currentSize << "\r\n";
    cout << maxSize << "\r\n";

    cout << "{";
    for (unsigned int i = 0; i < currentSize; i++)
    {
        cout << array[i] << ((i != currentSize - 1) ? "," : "" );
    }
    cout << "}\r\n";
}

bool Ensemble::EstEgal(const Ensemble &unEnsemble) const
{
    if (this->currentSize != unEnsemble.currentSize)
        return false;

    for (unsigned int i = 0; i < currentSize; i++)
    {
        if (unEnsemble.array[i] != this->array[i])
            return false;
    }

    return true;
}

RetourInclusion Ensemble::EstInclus(const Ensemble &unEnsemble) const
{
    if (unEnsemble.currentSize < this->currentSize)
        return NON_INCLUSION;

    if (this->EstEgal(unEnsemble))
        return INCLUSION_LARGE;

    for (unsigned int i = 0; i < this->currentSize; i++)
    {
        bool existInUnEnsemble = false;

        for (unsigned int j = 0; j < unEnsemble.currentSize; j++)
        {
            if (this->array[i] == unEnsemble.array[j])
            {
                existInUnEnsemble = true;
                break;
            }
        }

        if (!existInUnEnsemble)
            return NON_INCLUSION;
    }

    return INCLUSION_STRICTE;
}

RetourAjout Ensemble::Ajouter(int aAjouter)
{
    if (exist(aAjouter))
        return DEJA_PRESENT;

    if (currentSize == maxSize)
        return PLEIN;

    array[currentSize] = aAjouter;
    currentSize++;

    bubbleSort();
    return AJOUTE;
}

unsigned int Ensemble::Ajuster(int delta)
{
    if (delta == 0)
        return maxSize;

    int * values = new int[this->currentSize];              // Save Values
    for (unsigned int i = 0; i < currentSize; i++)
        values[i] = array[i];

    if (delta > 0)                                          // Change maxSize
    {
        this->maxSize += delta;
    }
    else if (delta < 0)
    {
        int signedMaxSize = maxSize;

        if (signedMaxSize + delta < (int)currentSize)
            signedMaxSize = currentSize;

        else
            signedMaxSize += delta;

        this->maxSize = (unsigned int) signedMaxSize;
    }

    array = new int[maxSize];                               // Update Tab Size

    for (unsigned int i = 0 ; i < currentSize; i++)         // Fill tab with saved values
        array[i] = values[i];

    delete[] values;

    return maxSize;
}

/*********************************/
/** Constructeurs - destructeur **/
/*********************************/

Ensemble::Ensemble(unsigned int cardMax)
{
    maxSize = cardMax;
    currentSize = 0;

    array = new int[cardMax];
}

Ensemble::Ensemble(int t[], unsigned int nbElements)
{
    maxSize = nbElements;
    currentSize = 0;
    array = new int[maxSize];

    for (unsigned int i = 0; i < nbElements; i++)
    {
        if (!exist(t[i]))
        {
            array[currentSize] = t[i];
            currentSize++;
        }
    }

    selectionSort();
}

Ensemble::~Ensemble()
{
    delete[] array;
}


/*********************************/
/******* Private - Methods *******/
/*********************************/

void Ensemble::selectionSort()
{
    for (unsigned int i = 0; i < currentSize; i++)
    {
        int minValue = array[i];
        int minIndex = i;

        for (unsigned int j = i; j < currentSize; j++)
        {
            if (minValue > array[j])
            {
                minValue = array[j];
                minIndex = j;
            }
        }

        swap(i, minIndex);
    }
}

void Ensemble::bubbleSort()
{
    bool didSwap = true;

    while(didSwap)
    {
        didSwap = false;
        for (unsigned int i = 0; i < currentSize - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                swap(i, i + 1);
                didSwap = true;
            }
        }
    }
}


void Ensemble::swap(int firstIndex, int secondIndex)
{
    int temp = array[firstIndex];
    array[firstIndex] = array[secondIndex];
    array[secondIndex] = temp;
}

bool Ensemble::exist(int value)
{
    for (unsigned int i = 0; i < currentSize; i++)
    {
        if (value == array[i])
            return true;
    }

    return false;
}
