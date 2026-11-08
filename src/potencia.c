#include <stdio.h>
#include "potencia.h"

float ler_potencia(void)
{
    float valor;

    while (1)
    {
        printf("  Power (W): ");

        if (scanf("%f", &valor) == 1)
        {
            return valor;
        }

        printf("  Invalid value. Try again.\n");

        while (getchar() != '\n')
        {
        }
    }
}

void ler_todas_potencias(struct Potencia *potencia)
{
    printf("\n");
    printf("[ POWER MEASUREMENTS ]\n\n");

    printf("  Measurement 1\n");
    potencia->potencia_1 = ler_potencia();

    printf("\n  Measurement 2\n");
    potencia->potencia_2 = ler_potencia();

    printf("\n  Measurement 3\n");
    potencia->potencia_3 = ler_potencia();
}
