#include <stdio.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        printf("vous devez passer un fichier en paramètre\n");
        return 0;
    }
    
    printf("File : %s\r\n\r\n", argv[1]);
    FILE * file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("Impossible de lire le fichier... %d\n", errno);
        return 0;
    }
    
    int c;
    for (;;)
    {
        c = fgetc(file);
        
        if (c == EOF)
        {
            fclose(file);
            return 0;
        }
        
        printf("%c", (char)c);
    }

	return 0;
}

