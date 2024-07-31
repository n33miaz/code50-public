#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int n = get_int("Qual será o tamanhao do array? ");
    string array[n];

    printf("Defina os números do array:\n");

    for (int i = 0; i < n; i++)
    {
        array[i] = get_string("%iº:", i+1);
    }

    printf("O array foi ordenado em forma crescente:\n");

    // considera o primeiro número do array como o menor para a comparação
    string menor = array[0], troca = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n-i; j++)
        {
            if (strcmp(array[j], menor) == 0)
            {
                troca = menor;
                menor = array[j];
            }
            else {
                continue;
            }
        }
        array[troca] = array[i];
        array[i] = menor;
        n -= i;
    }

    printf("%s", array);
}
