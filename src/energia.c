#include <stdio.h>
#include "energia.h"

float ler_energia(void)
{
    float valor;

    while (1)
    {
        printf("  Energy (Wh): ");

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

void ler_todas_energias(struct Energia *energia)
{
    printf("\n");
    printf("[ ENERGY MEASUREMENTS ]\n\n");

    printf("  Measurement 1\n");
    energia->energia_1 = ler_energia();

    printf("\n  Measurement 2\n");
    energia->energia_2 = ler_energia();

    printf("\n  Measurement 3\n");
    energia->energia_3 = ler_energia();
}
