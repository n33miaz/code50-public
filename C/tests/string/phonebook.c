#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string nome;
    string numero;
}
pessoas; // nome da estrutura de dados modificada

int main(void)
{
    pessoas individuo[2]; // nome da string modificada

    // atribuição:
    individuo[0].nome = "Julia";
    individuo[0].numero = "+55-(11)976458909";

    individuo[1].nome = "Matheus";
    individuo[1].numero = "+55-(16)987643321";

    for (int i = 0; i < 2; i++)
    {
        if (strcmp(individuo[i].nome, "Matheus") == 0)
        {
            printf("Encontrado, %s\n", individuo[i].numero);
            return 0;
        }
    }
    printf("Não encontrado");
    return 1;
}
