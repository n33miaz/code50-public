#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Antes:  ");
    printf("Depois: ");

    for (int i = 0, n = strlen(s); i <= n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z') // leve em consideração ASCII, 'a' = 97 e 'z' = 122
        {
            printf("%c", s[i] - 32); // a diferença entre as letras Maiú. e minu. é de 32
        }
        else
        {
            printf("%c", s[i]);
        }
    }

    printf("\n");
}
