#include <stdio.h>
#include "resistencia.h"

float ler_resistencia(void)
{
    float valor;

    while (1)
    {
        printf("  Resistance (Ohm): ");

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

void ler_todas_resistencias(struct Resistencia *resistencia)
{
    printf("\n");
    printf("[ RESISTANCE MEASUREMENTS ]\n\n");

    printf("  Measurement 1\n");
    resistencia->resistencia_1 = ler_resistencia();

    printf("\n  Measurement 2\n");
    resistencia->resistencia_2 = ler_resistencia();

    printf("\n  Measurement 3\n");
    resistencia->resistencia_3 = ler_resistencia();
}
