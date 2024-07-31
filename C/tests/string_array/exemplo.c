#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // string s = "HI!";
    // printf("%s\n", s);

    string s = "HI!";

    printf("%i %i %i\n", s[0], s[1], s[2]); // ASCII

    // é possível olhar outros espaços da mémoria:
    // ("%i %i %i %i %i\n", s[0], s[1], s[2], s[3], s[400])
    // a partir de (s + 1) você está olhando espaços preenchidos por outros programas
}
