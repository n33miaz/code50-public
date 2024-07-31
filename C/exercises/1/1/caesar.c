#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool is_valid_key(string key)
{
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!isdigit(key[i]))
        {
            return false; // Se encontrarmos um caractere não numérico, a chave não é válida
        }
    }
    return true; // Se todos os caracteres forem dígitos, a chave é válida
}

int main(int argc, string argv[])
{
    // Verifica se o número correto de argumentos foi fornecido
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Verifica se a chave é válida (todos os caracteres são dígitos)
    if (!is_valid_key(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Converte o argumento da chave para um número inteiro
    int key = atoi(argv[1]);

    // Verifica se a chave é um número positivo
    if (key <= 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Captura o texto do usuário
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");
    char c;

    // Loop para a criptografia do texto
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        c = plaintext[i];

        // Verifica se o caractere é uma letra maiúscula
        if (isupper(c))
        {
            // Aplica a cifra de César para letras maiúsculas
            char encrypted_char = 'A' + (c - 'A' + key) % 26;
            printf("%c", encrypted_char);
        }
        // Verifica se o caractere é uma letra minúscula
        else if (islower(c))
        {
            // Aplica a cifra de César para letras minúsculas
            char encrypted_char = 'a' + (c - 'a' + key) % 26;
            printf("%c", encrypted_char);
        }
        else
        {
            // Mantém caracteres não alfabéticos inalterados
            printf("%c", c);
        }
    }
    printf("\n");

    return 0;
}
