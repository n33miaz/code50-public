#include <cs50.h>
#include <stdio.h>

// maximo de eleitores e candidatos
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferencias[i][j] é a jº preferencia do eleitor i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// candidatos tem nome, contagem de eleitor, status eliminado
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// array dos candidatos
candidate candidates[MAX_CANDIDATES];

// número de eleitores e candidatos
int voter_count;
int candidate_count;

// declaração das funções mais abaixo
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // verifica se o uso do programa é valido
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // preenchimento array dos candidatos
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // consulta todos os votos
    for (int i = 0; i < voter_count; i++)
    {

        // verifica cada classificação
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // registra o voto, a menos que seja inválido
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // continua o loop até que haja um vencedor
    while (true)
    {
        // calcula os votos dados aos candidatos restantes
        tabulate();

        // verifica se a eleição já tem um vencedor
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // elimina os cadidatos em ultimo lugar
        int min = find_min();
        bool tie = is_tie(min);

        // se houve o empate, todos ganham
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // elimina todos os candidatos que tiverem com o minimo de votos
        eliminate(min);

        // reseta a contagem de votos
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// registra a preferencia se o voto for válido
bool vote(int voter, int rank, string name) // 08:00
{
    // verificar o candidato chamado
        // se o candidato for encontrado, atualizar o array de preferencias e retornar true
        // se o candidato não for encontrado, não atualizar nada e retornar false
    return false;
}

// tabula votos para os candidatos não eliminados
void tabulate(void) // 09:30
{
    // atualizar a contagem de votos para os candidatos não eliminados
        // usando o array de preferencias
            // você deve procurar pelo candidato válido mais alto
    return;
}

// exibe o ganhador da eleição, se existir um
bool print_winner(void) // 12:00
{
    // se algum candidato tiver mais da metade dos votos, exiba ele como vencedor e retorne true
    // se nenhum candidato tiver, retornar false
    return false;
}

// retorna o número mínimo de voto que qualquer candidato restante possua
int find_min(void) // 13:00
{
    // retornar o número mínimo de votos de alguém na eleição
    return 0;
}

// retorna true se a eleição estiver empatada, caso contrario false
bool is_tie(int min) // 14:30
{
    // recebe o número mínimo de votos na eleição (func acima)
        // retorna true se todos os candidatos estiverem com o número mínimo de votos (eleição empatada)
        // caso contrario retorna false
    return false;
}

// elimina o candidato (ou candidatos) em ultimo lugar
void eliminate(int min) // 15:30
{
    // elimina da eleição quem tiver o número mínimo de votos
    return;
}
