#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Pontos atribuidos a cada letra do alfabeto
int PONTOS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
char ALFABETO[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int calculo_pontos(string palavra);

int main(void)
{
    // Adquirir a palavra de cada jogador
    string palavra1 = get_string("Player 1: ");
    string palavra2 = get_string("Player 2: ");

    // Pontuação de cada palavra
    int pontuacao1 = calculo_pontos(palavra1);
    int pontuacao2 = calculo_pontos(palavra2);

    if (pontuacao1 > pontuacao2)
    {
        printf("Player 1 wins!");
    }
    else if (pontuacao2 > pontuacao1)
    {
        printf("Player 2 wins!");
    }
    else
    {
        printf("Tie!");
    }

    return 0;
}

int calculo_pontos(string palavra)
{
    int pontuacao = 0;
    char letra;

    for (int i = 0; i < strlen(palavra); i++)
    {
        letra = palavra[i];

        // ignora caracteres especiais
        if (!isalpha(letra))
        {
            continue;
        }
        // padroniza a case da letra
        else if (!islower(letra))
        {
            letra = tolower(letra);
        }

        // identifica a letra de acordo com "ALFABETO[]" e compara com "PONTOS[]"
        for (int j = 0; j < 26; j++)
        {
            if (ALFABETO[j] == letra)
            {
                pontuacao += PONTOS[j];
            }
        }
    }
    return pontuacao;
}
