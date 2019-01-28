#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node {
    int value;
    Node *next;
} Node;

typedef struct Fifo {
    Node *head;
} Fifo;

void Push(Fifo *fifo, int value)
{
    Node *head = fifo->head;

    Node *node = new Node();
    node->next = head;
    node->value = value;

    fifo->head = node;
}

int Pop(Fifo *fifo, int *val)
{
    Node *previousNode = NULL;
    Node *node = fifo->head;

    if (node == NULL)
        return 0;

    while(node->next != NULL)
    {
        previousNode = node;
        node = node->next;
    }

    if (previousNode == NULL)
    {
        fifo->head = NULL;
    }
    else
    {
        previousNode->next = NULL;
    }

    *val = node->value;
    delete node;

    return 1;
}

/* Destroy frees the structure */
void Destroy(Fifo * fifo)
{
    Node * node = fifo->head;

    if (node != NULL)
    {
        do {
            Node *temp = node->next;

            delete node;
            node = temp;
        } while (node != NULL);
    }

    delete fifo;
}

int main()
{
    char lecture[100];
    int val;
    Fifo * fifo;
    fifo = new Fifo();

    fscanf(stdin,"%99s",lecture);

    while (strcmp(lecture,"bye")!=0)
    {
        if (strcmp(lecture, "display")==0)
        {
            Node *iterate = fifo->head;

            while (iterate != NULL)
            {
                printf("%d ", iterate->value);
                iterate = iterate->next;
            }

            printf("\r\n");
        }
        if (strcmp(lecture,"queue")==0)
        {
            fscanf(stdin,"%99s",lecture);
            val = strtol(lecture, NULL, 10);

            Push(fifo, val);
        }
        else if (strcmp(lecture,"dequeue")==0)
        {
            if(Pop(fifo, &val))
            {
                printf("%d\r\n",val);
            }
        }
        fscanf(stdin,"%99s",lecture);
    }

    Destroy(fifo);

    return 0;
}