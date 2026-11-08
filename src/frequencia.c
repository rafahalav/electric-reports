#include <stdio.h>

#include "frequencia.h"
#include "terminal_theme.h"

float ler_frequencia(void)
{
    float valor;

    while (1)
    {
        printf(TEMA_VERDE "  Frequency (Hz): "
               TEMA_RESET);

        if (scanf("%f", &valor) == 1)
        {
            while (getchar() != '\n')
            {
                /* descarta o restante da linha */
            }

            return valor;
        }

        printf("\n");
        printf(TEMA_AMBAR TEMA_NEGRITO
               "[ ERROR ]"
               TEMA_RESET "\n");

        printf(TEMA_AMBAR
               "  Invalid frequency value. Try again.\n"
               TEMA_RESET);

        while (getchar() != '\n')
        {
            /* limpa a entrada invalida */
        }
    }
}

void ler_todas_frequencias(struct Frequencia *frequencia)
{
    printf("\n");

    printf(TEMA_AMARELO TEMA_NEGRITO
           "[ FREQUENCY MEASUREMENTS ]"
           TEMA_RESET "\n\n");

    printf(TEMA_CIANO
           "  Measurement 1\n"
           TEMA_RESET);

    frequencia->frequencia_1 = ler_frequencia();

    printf("\n");

    printf(TEMA_CIANO
           "  Measurement 2\n"
           TEMA_RESET);

    frequencia->frequencia_2 = ler_frequencia();

    printf("\n");

    printf(TEMA_CIANO
           "  Measurement 3\n"
           TEMA_RESET);

    frequencia->frequencia_3 = ler_frequencia();
}
