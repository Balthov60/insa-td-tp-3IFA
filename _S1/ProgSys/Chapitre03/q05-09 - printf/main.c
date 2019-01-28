#include <stdio.h>
#include <errno.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

void putCh(char c)
{
    write(STDOUT_FILENO, &c, 1);
}
int extractInt(int val, char result[100])
{
    int i = 0;
    
    while (val / 10 != 0)
    {
        result[i++] = 48 + (val % 10);
        val = val / 10;
    }
    result[i] = 48 + (val % 10);
    
    return i;
}
void understood_printf(char * toPrint, ...)
{
    va_list param_pointer;
    va_start(param_pointer, toPrint);
    
    char c = toPrint[0];
    int i = 0;
    
    while (c != '\0')
    {
        i++;
        
        if (c == '%')
        {
            char type = toPrint[i];
            
            switch (type)
            {
                case 'd':
                {
                    char temp[100];
                    
                    int size = extractInt(va_arg(param_pointer, int), temp);
                    
                    for (;size >= 0; size--)
                        putCh(temp[size]);
                    
                    break;
                }
                    
                case 'f':
                {
                    char temp[100];
                    float val = va_arg(param_pointer, double);
                    
                    int size = extractInt((int)val, temp);
                    for (;size >= 0; size--)
                        putCh(temp[size]);
                    
                    putCh('.');
                    
                    val = val - ((int)val);
                    val = val * 100;
                    
                    size = extractInt((int)val, temp);
                    for (;size >= 0; size--)
                        putCh(temp[size]);
                    
                    break;
                }
                
                case 'c':
                {
                    putCh((char)va_arg(param_pointer, int));
                    break;
                }
                
                case 's':
                {
                    char * val = va_arg(param_pointer, char *);
                    
                    int j = 0;
                    char val_c = val[0];
                    do
                    {
                        putCh(val_c);
                        val_c = val[++j];
                    }
                    while (val_c != '\0');
                    
                    break;
                }

                default:
                    putCh(c);
                    putCh(type);
                    break;
            }
            
            i++;
        }
        else
        {
            putCh(c);
        }
        
        c = toPrint[i];
    }
                        
    va_end(param_pointer);
    putCh('\n');
}

// %d (decimal) %f (float) %c (char) %s (string)
int main(int argc, char const *argv[])
{
    understood_printf("Salut ! j'ai %d %s, ma lettre préféré est le %c et je vend %d %s à %f euro", 10, "ans", 'd', 20, "truc", 4.56);
    return 0;
}

