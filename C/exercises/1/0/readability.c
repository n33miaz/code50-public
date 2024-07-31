#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    int letras = 0, palavras = 0, sentencas = 0;
    string texto = get_string("Text: ");

    for (int i = 0, n = strlen(texto); i < n; i++)
    {
        // verifica a quantidade de letras
        if (isalpha(texto[i]))
        {
            letras += 1;
        }
        // verifica a quantidade de palavras (palavras + 1)
        else if (isspace(texto[i]))
        {
            // verifica se o proximo caractere é um espaço em branco e se
            // o terminador nulo para não contar como uma nova palavra
            if (!isspace(texto[i + 1]) && texto[i + 1] != '\0')
            {
                palavras += 1;
            }
        }
        // verifica a quantidade de sentenças e adicina uma palavra que havia passado despercebida
        else if (texto[i] == '!' || texto[i] == '?' || texto[i] == '.')
        {
            // verifica se o proximo caractere não é um espaço em branco ou
            // o terminador é nulo para contar como uma nova palavra
            if (!isspace(texto[i + 1]) || texto[i + 1] == '\0')
            {
                palavras += 1;
            }
            sentencas += 1;
        }
    }

    // calcula o nível de leitura com base no indice de Coleman-Liau
    float L = (float) letras / palavras * 100.0;
    float S = (float) sentencas / palavras * 100.0;
    float indice = (0.0588 * L) - (0.296 * S) - 15.8;

    // arredonda ? para o número int mais próximo
    int nivelLeitura = round(indice);

    // mostra ao usuario o nível de leitura do texto
    if (nivelLeitura < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (nivelLeitura > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", nivelLeitura);
    }

    return 0;
}
