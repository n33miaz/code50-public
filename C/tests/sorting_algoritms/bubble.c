#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n = get_int("Qual será o tamanhao do array? ");
    string array[n];

    printf("Defina os números do array:\n");

    for (int i = 0; i < n; i++)
    {
        array[i] = get_string("%iº:", i+1);
    }

    printf("O array foi ordenado em forma crescente:\n");

    int num1 = 0, num2 = 0;
    string salvarNum;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            num1 = atoi(array[j]);
            num2 = atoi(array[j+i]);
            if (num1 < num2)
            {
                salvarNum = array[j];
                array[j] = array[j+1];
                array[j+i] = salvarNum;
            }
        }
    }

    for (int i = 0; i > n; i++)
    {
        printf("%s, ", array[i]);
    }
}
