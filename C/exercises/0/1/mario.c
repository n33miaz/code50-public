#include <stdio.h>
#include <cs50.h>

void torreOutput(void);

int main(void) {
    torreOutput();
}

void torreOutput(void) {
    int altura, espacos;

    do {
        altura = get_int("Qual será a altura da torre? ");
    } while (altura < 1 || altura > 8);

    for (int i = 0; i < altura; i++) { // i = linha

        for (espacos = 0; espacos < (altura - i - 1); espacos++) {
            printf(" "); // trocar o espaço vazio por "." para melhor visualização
        }

        for (int j = 0; j <= i; j++) { // j = coluna
            printf("#");
        }

        for (espacos = 0; espacos < 2; espacos++) {
            printf(" "); // trocar o espaço vazio por "." para melhor visualização
        }

        for (int j = 0; j <= i; j++) { // piramide virada para a esquerda
            printf("#");
        }

        printf("\n");
    }
}
