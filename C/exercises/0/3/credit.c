#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long numeroCartao, verificarBandeira;
    int soma = 0, digito, contador = 0;

    // solicitação do número do cartão
    do {
        numeroCartao = get_long("Número: ");
    }
    while (numeroCartao < 0);

    verificarBandeira = numeroCartao;

    // formula de Luhn
    while (numeroCartao > 0)
    {
        digito = numeroCartao % 10; // pega o ultimo digito do cartão

        if (contador % 2 == 0) // soma os digitos pares
        {
            soma += digito;
        }
        else
        {
            digito *= 2; // multiplica digitos impares
            soma += digito % 10 + digito / 10; // separa o número de dois dígitos em seus dígitos individuais e os soma.
        }

        numeroCartao /= 10;
        contador++;
    }

    if (soma % 10 == 0)
    {
        if ((verificarBandeira > 339999999999999 && verificarBandeira < 349999999999999) || (verificarBandeira > 369999999999999 && verificarBandeira < 379999999999999))
        {
            printf("AMEX\n");
        }
        else if ((verificarBandeira > 3999999999999 && verificarBandeira < 4999999999999) || (verificarBandeira > 3999999999999999 && verificarBandeira < 4999999999999999))
        {
            printf("VISA\n");
        }
        else if (verificarBandeira > 4999999999999999 && verificarBandeira < 5599999999999999)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
