#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int allocated; /* current allocation of array */
    int filled;    /* number of items present in the binheap */
    int *array;    /* array of values */
} BinaryHeap;

/* Init allocates the structure BinaryHeap and
 * also the member array with the given size
 * it also fills allocated (size) and intializes
 * filled to 0 */
BinaryHeap * Init(int size)
{
    BinaryHeap * heap = new BinaryHeap();

    heap->allocated = size;
    heap->filled = 0;
    heap->array = new int[size];

    return heap;
}

void realocateTab(BinaryHeap * heap)
{
    int *temp = heap->array;

    heap->allocated += 10;
    heap->array = new int[heap->allocated];

    for (int i = 0; i < heap->filled; i++)
    {
        heap->array[i] = temp[i];
    }

    delete[] temp;
}

/* InsertValue inserts value into the binary heap
 * the array is reallocated if necessary (allocated changed
 * with respect to the new size)
 * filled is incremented by 1 */
void InsertValue(BinaryHeap * heap, int value)
{
    if (heap->filled == heap->allocated)
        realocateTab(heap);

    heap->array[heap->filled] = value;
    heap->filled++;

    int index = heap->filled - 1;
    int superIndex = (index - 1)/ 2;

    while (index > 0 && heap->array[superIndex] < heap->array[index])
    {
        int temp = heap->array[superIndex];
        heap->array[superIndex] = heap->array[index];
        heap->array[index] = temp;

        index = superIndex;
        superIndex = (index - 1) / 2;
    }
}

void swap(BinaryHeap *heap, int firstIndex, int secondIndex)
{
    int temp = heap->array[secondIndex];
    heap->array[secondIndex] = heap->array[firstIndex];
    heap->array[firstIndex] = temp;
}

/* ExtractMAx returns 0 if the binary heap is empty
 * otherwise it returns 1 and fills *val with the maximum
 * value present in the binary heap
 * filled is decremented by 1  and the max value is removed
 * from the binary heap */
int ExtractMax(BinaryHeap * heap, int * val)
{
    if (heap->filled == 0)
        return 0;

    *val = heap->array[0];

    heap->filled--;
    heap->array[0] = heap->array[heap->filled];

    int index = 0;
    int leftChild = index * 2 + 1;
    int rightChild =index * 2 + 2;

    while (leftChild < heap->filled)
    {
        if ((rightChild >= heap->filled || heap->array[leftChild] > heap->array[rightChild])
                && heap->array[leftChild] > heap->array[index])
        {
            swap(heap, index, rightChild);
            index = leftChild;
        }
        else if (heap->array[rightChild] > heap->array[index])
        {
            swap(heap, index, rightChild);
            index = rightChild;
        }
        else
        {
            return 1;
        }

        leftChild = index * 2 + 1;
        rightChild = index * 2 + 2;
    }

    return 1;
}

/* Destroy frees the structure and the array */
void Destroy(BinaryHeap * heap)
{
    delete[] heap->array;
    delete heap;
}

int main()
{
    char lecture[100];
    int val;
    BinaryHeap * heap;
    heap = Init(10);

    fscanf(stdin,"%99s",lecture);

    while (strcmp(lecture,"bye")!=0)
    {
        if (strcmp(lecture, "display")==0)
        {
            printf("(%d/%d)\r\n", heap->filled, heap->allocated);

            for (int i = 0 ; i < heap->filled; i++)
            {
                printf("%d ", heap->array[i]);
            }

            printf("\r\n");
        }
        if (strcmp(lecture,"insert")==0)
        {
            fscanf(stdin,"%99s",lecture);
            val = strtol(lecture,NULL,10);
            InsertValue(heap,val);
        }
        else if (strcmp(lecture,"extract")==0)
        {
            if(ExtractMax(heap,&val))
            {
                printf("%d\r\n",val);
            }
        }
        fscanf(stdin,"%99s",lecture);
    }

    Destroy(heap);

    return 0;
}