#include <cs50.h>
#include <stdio.h>

// maneira de criar uma constante global
// const int quantidade = 3;

float media();

int main(void)
{
    // obtenção da quantidade de "escores"
    int n = get_int("Qntd: ");
    int score[n-1];

    printf("\n");
    // maneira chata de somar (parte 1)
    // int soma = 0;

    // repetição da obtenção do número de cada score
    for (int i = 0; i < n; i++)
    {
        score[i] = get_int("Score %i: ", (i+1));

        // maneira chata de somar (parte 2)
        // soma += score[i];
    }

    printf("\n");                          // maneira chata de somar (parte 3)
    printf("Média: %f", media(n, score));  // soma / (float) n
    printf("\n");
}

// função para somar e fazer a media
// nome + (parametro1, parametro2) {}
float media(int quantidade, int array[])
{
    int soma = 0;

    for (int i = 0; i < quantidade; i++)
    {
        soma += array[i];
    }

    return soma / (float) quantidade;
}
