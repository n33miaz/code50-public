#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
         for (int i = 0, n = strlen(argv[1]); i < n; i++)
         {
            printf("%c\n", argv[1][i]);
         }
    }
    // if (argc == 2)
    // {
           // é coloca o "1", pois o "0" é armazenado o proprio chamado do programa "./argv"
    //     printf("hello, %s\n", argv[1]);
    // }
    // else
    // {
    //     printf("hello, world\n");
    // }
}
