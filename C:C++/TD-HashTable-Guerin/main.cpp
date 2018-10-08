#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

/**********/
/** HASH **/
/**********/

enum HashStatus
{
    EMPTY,
    FILLED,
    REMOVED
};

typedef char * Key;

typedef struct
{
    HashStatus status;

    Key key;
    Key value;

} HashCell;

typedef struct
{
    HashCell * array;

    unsigned int size;

} HashTable;

unsigned int HashFunction(Key key, unsigned int size);

void error(void);

/***************/
/** LifeCycle **/
/***************/

HashTable * Init(int size)
{
    HashTable * table = new HashTable();

    table->size = size;
    table->array = new HashCell[size];

    for (unsigned int i = 0; i < table->size; i++)
    {
        table->array[i].status = EMPTY;
    }

    return table;
}

void Destroy(HashTable * table)
{
    delete[] table->array;
    delete table;
}

/**************/
/** Function **/
/**************/

void InsertValue(HashTable * table, char* key, char* value)
{
    unsigned int index = HashFunction(key, table->size);

    while (index < table->size && table->array[index].status == FILLED)
    {
        if (strcmp(table->array[index].key, key) == 0)
            break;

        index++;
    }

    if (index >= table->size)
        return;

    table->array[index].status = FILLED;
    table->array[index].key = key;
    table->array[index].value = value;
}

void QueryValue(HashTable *table, char * key)
{
    unsigned int index = HashFunction(key, table->size);

    while (index < table->size && table->array[index].status != EMPTY) {
        if (table->array[index].status == FILLED && table->array[index].key != NULL && strcmp(table->array[index].key, key) == 0)
            break;

        index++;
    }

    if (index >= table->size || table->array[index].status == EMPTY)
    {
        printf("Not found\r\n");
        return;
    }

    printf("%s\r\n", table->array[index].value);
}

void DeleteValue(HashTable *table, char *key)
{
    unsigned int index = HashFunction(key, table->size);

    while (index < table->size && table->array[index].status != EMPTY) {
        if (table->array[index].status == FILLED && table->array[index].key != NULL && strcmp(table->array[index].key, key) == 0)
            break;

        index++;
    }

    if (index >= table->size || table->array[index].status == EMPTY)
    {
        return;
    }

    table->array[index].status = REMOVED;
}

void Stats(HashTable * table)
{
    int empty = 0, deleted = 0, used = 0;

    for (unsigned int i = 0; i < table->size; i++)
    {
        switch(table->array[i].status)
        {
            case EMPTY:
                empty++;
                break;

            case REMOVED:
                deleted++;
                break;

            case FILLED:
                used++;
                break;
        }
    }

    printf("size    : %d\r\n", table->size);
    printf("empty   : %d\r\n", empty);
    printf("deleted : %d\r\n", deleted);
    printf("used    : %d\r\n", used);
}

/**********/
/** MAIN **/
/**********/

int main()
{
    int size;
    char lecture[100];
    char * key;
    char * val;

    HashTable *hashTable = new HashTable();

    if (fscanf(stdin,"%99s",lecture)!=1)
        error();

    while (strcmp(lecture,"bye")!=0)
    {
        if (strcmp(lecture,"init")==0)
        {
            if (fscanf(stdin,"%99s",lecture)!=1)
                error();
            size = atoi(lecture);

            Destroy(hashTable);

            hashTable = Init(size);
        }
        else if (strcmp(lecture,"insert")==0)
        {
            if (fscanf(stdin,"%99s",lecture)!=1)
                error();
            key = strdup(lecture);
            if (fscanf(stdin,"%99s",lecture)!=1)
                error();
            val = strdup(lecture);

            InsertValue(hashTable, key, val);
        }
        else if (strcmp(lecture,"delete")==0)
        {
            if (fscanf(stdin,"%99s",lecture)!=1)
                error();
            key = strdup(lecture);

            DeleteValue(hashTable, key);
        }
        else if (strcmp(lecture,"query")==0)
        {
            if (fscanf(stdin,"%99s",lecture)!=1)
                error();
            key = strdup(lecture);

            QueryValue(hashTable, key);
        }
        else if (strcmp(lecture,"destroy")==0)
        {
            Destroy(hashTable);
        }
        else if (strcmp(lecture,"stats")==0)
        {
            Stats(hashTable);
        }
        else if (strcmp(lecture, "display")==0)
        {
            for (unsigned int i = 0; i < hashTable->size; i++)
            {
                printf("%d %s %s %d\r\n", i, hashTable->array[i].value, hashTable->array[i].key,  hashTable->array[i].status);
            }
        }

        if (fscanf(stdin,"%99s",lecture)!=1)
            error();
    }
    return 0;
}

/* fonction de décalage de bit circulaire */
unsigned int shift_rotate(unsigned int val, unsigned int n)
{
    n = n%(sizeof(unsigned int)*8);
    return (val<<n) | (val>> (sizeof(unsigned int)*8-n));
}

/* fonction d'encodage d'une chaîne de caractères */
unsigned int Encode(Key key)
{
    unsigned int i;
    unsigned int val = 0;
    unsigned int power = 0;
    for (i=0;i<strlen(key);i++)
    {
        val += shift_rotate(key[i],power*7);
        power++;
    }
    return val;
}

/* fonction de hachage simple qui prend le modulo */
unsigned int Hash(unsigned int val, unsigned int size)
{
    return val%size;
}

/* fonction de hachage complète à utiliser */
unsigned int HashFunction(Key key, unsigned int size)
{
    return Hash(Encode(key), size);
}

/* placer ici vos définitions (implémentations) de fonctions ou procédures */

void error(void)
{
    printf("input error\r\n");
    exit(0);
}
