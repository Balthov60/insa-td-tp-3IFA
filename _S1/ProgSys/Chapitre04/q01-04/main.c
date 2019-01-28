#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 20

int main(int argc, char * argv[])
{
    int size = argc;
    
    char ** test = malloc(size * sizeof(char *));
    
    for (int i = 0; i < size; i++)
    {
        test[i] = malloc(MAX_SIZE * sizeof(char));
        memcpy(test[i], argv[i], (strlen(argv[i]) + 1) * sizeof(argv[i]));
        printf("%d : %s\r\n", i, test[i]);
    }
    
    char temp[100];
    scanf("%s", temp);
    
    while (strcmp(temp, "bye") != 0)
    {
        if (strcmp(temp, "!") == 0)
        {
            for (int i = 0; i < size; i++)
            {
                memset(test[i], 98, MAX_SIZE - 1 * sizeof(char));
            }
        }
        else
        {
            size++;
            
            test = realloc((void **)test, size * sizeof(char *));
            test[size - 1] = malloc(MAX_SIZE * sizeof(char));
            
            memcpy(test[size-1], &temp, (strlen(temp) + 1) * sizeof(temp[0]));
            
            for (int i = 0; i < size; i++)
            {
                printf("%d : %s : %p\r\n", i, test[i], (void *)&test[i]);
            }
        }
        
        scanf("%s", temp);
    }
    
    for (int i = 0; i < size; i++)
    {
        printf("%d : %s\r\n", i, test[i]);
    }
    
    free(test);

	return 0;
}
