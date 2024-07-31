#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 9

typedef struct
{
    string nome;
    int voto;
}
candidato;

candidato candidatos[MAX];

// funções declaradas abaixo
bool voto();
void exibir_ganhador();

int main(int argc, string argv[])
{
    // verifica se foi executado corretamente
    if (argc < 2 || argc > MAX + 1)
    {
        printf("Usage: ./plurality [candidate, ...]\n");
        return 1;
    }

    // representa o número total de candidatos
    int n = 0;

    // copia para a estrutura "candidatos"
    for (int i = 1; i < argc; i++)
    {
        candidatos[i - 1].nome = argv[i]; // atribui o nome do candidato
        candidatos[i - 1].voto = 0;       // inicializa o contador de votos
        n++;
    }

    // solicita o número de eleitores
    int m = 0;
    do
    {
        m = get_int("Number of voters: ");
    }
    while (m < 0);

    // recebe os votos e atualiza os contadores
    string contador_votos;
    for (int i = 0; i < m; i++)
    {
        contador_votos = get_string("Vote: ");

        if (!voto(contador_votos))
        {
            printf("Invalid vote.\n");
        }
    }

    // exibe o(s) vencedor(es)
    exibir_ganhador(n);

    return 0;
}

bool voto(string nome)
{
    for (int i = 0; i < MAX; i++)
    {
        if (candidatos[i].nome != NULL && strcmp(candidatos[i].nome, nome) == 0)
        {
            candidatos[i].voto += 1;
            return true;
        }
    }
    return false;
}

void exibir_ganhador(int n)
{
    int maior_qntd = 0;

    // encontra o maior número de votos entre os candidatos
    for (int i = 0; i < n; i++)
    {
        if (candidatos[i].voto > maior_qntd)
        {
            maior_qntd = candidatos[i].voto;
        }
    }

    // exibe todos os candidatos com o maior número de votos
    for (int i = 0; i < n; i++)
    {
        if (candidatos[i].voto == maior_qntd)
        {
            printf("%s\n", candidatos[i].nome);
        }
    }
}
