#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int populacaoInicial, populacaoFinal, populacaoAtual, qntdMortos, qntdNasc, contador = 0;

    // solicita um número que seja no mínino 9
    do
    {
        populacaoInicial = get_int("População inicial: ");
    }
    while (populacaoInicial < 9);

    populacaoAtual = populacaoInicial; // começa com a população inicial

    // solicita um número que seja no mínino igual ao anterior
    do
    {
        populacaoFinal = get_int("População final: ");
    }
    while (populacaoFinal < populacaoInicial);

    // calculo de crescimento de população médio por ano
    while (populacaoAtual < populacaoFinal)
    {
        qntdMortos = populacaoAtual / 4;
        qntdNasc = populacaoAtual / 3;
        populacaoAtual += qntdNasc - qntdMortos;

        contador++;
    }

    printf("Years: %i\n", contador);
}
