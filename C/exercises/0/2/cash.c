#include <cs50.h>
#include <math.h>
#include <stdio.h>

void troco(void);

int main (void)
{
    troco();
}

void troco(void)
{
    int qntdMoedas = 0;
    int conversaoInt;
    float valorTroco;

    do
    {
    valorTroco = get_float("Troco Devido: ");
    } while (valorTroco <= 0);

    conversaoInt = round(valorTroco * 100); // para evitar erro nas expressoes aritmeticas

    for (int i = 0; conversaoInt > 0; i++)
    {
        if (conversaoInt >= 25)
        {
            conversaoInt -= 25; // conversaoInt = conversaoInt - 25
            qntdMoedas++;
        }
        else if (conversaoInt >= 10)
        {
            conversaoInt -= 10;
            qntdMoedas++;
        }
        else if (conversaoInt >= 5)
        {
            conversaoInt -= 5;
            qntdMoedas++;
        }
        else
        {
            conversaoInt -= 1;
            qntdMoedas++;
        }
    }

    printf("%i\n", qntdMoedas);
}
