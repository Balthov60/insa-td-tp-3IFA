/*************************************************************************
                           Ensemble  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//-------- Interface de la classe <Ensemble> (fichier Ensemble.h) --------
#if ! defined ( Ensemble_H )
#define Ensemble_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

#define CARD_MAX 5

/*********************************/
/********** Enum - Types *********/
/*********************************/

enum RetourInclusion
{
    NON_INCLUSION,              // Non Inclus
    INCLUSION_LARGE,            // confondu
    INCLUSION_STRICTE           // inclus
};

enum RetourAjout
{
    DEJA_PRESENT,
    PLEIN,
    AJOUTE
};

class Ensemble
{
/*********************************/
/******** Public - Methods *******/
/*********************************/

public:

    /**
     * Display ensemble content, max size & current size;
     *
     * Format : currentSize
     *          maxSize
     *          { content }
     */
    void Afficher();

    /**
     * Test l'egalité, entre le contenu et la taille courante.
     *
     * @param unEnsemble
     *
     * @return true SI (currentSize et le contenu de array son identique) ELSE false
     */
    bool EstEgal(const Ensemble &unEnsemble) const;

    /**
     * Vérifie si un ensemble est inclus dans l'autre ou égal à l'autre.
     *
     * @param unEnsemble
     *
     * @return TypeInclusion (Consulter la definition de TypeInclusion)
     */
    RetourInclusion EstInclus(const Ensemble &unEnsemble) const;

    /**
     * Ajoute une valeur dans l'ensemble si possible.
     *
     * @param aAjouter
     * @return CF l'enum Retour Ajout.
     */
    RetourAjout Ajouter(int aAjouter);

    /**
     * Ajuste la taille du tableau.
     *
     * SI DELTA > 0 : TAILLE + DELTA
     * SI DELTA < 0 : TAILLE - DELTA (Si la place est disponible on ne doit pas perdre de valeurs)
     * SI DELTA = 0 : RIEN NE SE PASSE
     *
     * @param delta
     * @return Cardinalité max actuelle.
     */
    unsigned int Ajuster(int delta);

/*********************************/
/** Constructeurs - destructeur **/
/*********************************/

    /**
     * Init ensemble with specific sized (can be left blank for default value).
     *
     * @param cardMax size of the ensemble
     */
    Ensemble(unsigned int cardMax = CARD_MAX);

    /**
     * Init ensemble with tab (can be left
     *
     * @param t
     * @param nbElements
     */
    Ensemble(int t[], unsigned int nbElements);

    /**
     * Destroy dynamic memory allocation.
     */
    virtual ~Ensemble();

/*********************************/
/******* Private - Methods *******/
/*********************************/

private:

    /**
     * Sort tab using selection sort.
     */
    void selectionSort();

    /**
     * Sort tab using bubble sort.
     */
    void bubbleSort();

    /**
     * Swap values at firstIndex & secondIndex
     *
     * @param firstIndex
     * @param secondIndex
     */
    void swap(int firstIndex, int secondIndex);

    /**
     *
     * Check if value exist in ensemble;
     *
     * @param value
     * @return true if exist false elsewhere
     */
    bool exist(int value);

/*********************************/
/****** Private - Attributes *****/
/*********************************/

private:

    unsigned int maxSize;
    unsigned int currentSize;
    int * array;

};

//-------------------------------- Autres définitions dépendantes de <Ensemble>

#endif // Ensemble_H

