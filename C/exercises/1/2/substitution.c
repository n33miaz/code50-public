#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[]) // solicita a cifra
{
    // verificar se foi digitado algo
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }
    // verificar o tamanho da cifra
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    char letra[25];

    // padroniza a case da key
    for (int i = 0; i <= 25; i++)
    {
        letra[i] = argv[1][i];

        // verificar são letras do alfabeto
        if (!isalpha(letra[i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }

        letra[i] = toupper(letra[i]);
    }

    // verificar se as letras são repetidas
    for (int i = 0; i <= 25; i++)
    {
        for (int j = i + 1; j <= 25; j++)
        {
            if (letra[i] == argv[1][j])
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }

    // solicitação do texto a ser criptografado
    string texto = get_string("plaintext:  ");

    printf("ciphertext: ");

    char letra_texto;
    // criptografar o texto
    for (int i = 0; texto[i] != '\0'; i++)
    {
        letra_texto = texto[i];

        // preservação da case
        if (isupper(letra_texto))
        {
            printf("%c", letra[letra_texto - 'A']);
        }
        else if (islower(letra_texto))
        {
            printf("%c", tolower(letra[letra_texto - 'a']));
        }
        else // caractere especial
        {
            printf("%c", texto[i]);
        }
    }
    printf("\n");

    return 0;
}
