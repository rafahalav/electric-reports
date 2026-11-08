/*
 * ============================================================
 * CORRENTE.C
 *
 * Objetivo:
 *   Capturar tres medicoes de corrente eletrica.
 * ============================================================
 */

#include <stdio.h>

#include "corrente.h"
#include "terminal_theme.h"

/*
 * ============================================================
 * FUNCAO: ler_corrente
 *
 * Objetivo:
 *   Ler um unico valor de corrente informado pelo operador.
 * ============================================================
 */

float ler_corrente(void)
{
    float valor;

    while (1)
    {
        printf(TEMA_VERDE "  Current (A): " TEMA_RESET);

        if (scanf("%f", &valor) == 1)
        {
            while (getchar() != '\n')
            {
                /* descarta o restante da linha */
            }

            return valor;
        }

        while (getchar() != '\n')
        {
            /* descarta a entrada invalida */
        }

        printf("\n");
        printf(TEMA_AMBAR TEMA_NEGRITO
               "[ ERROR ]"
               TEMA_RESET "\n");

        printf(TEMA_AMBAR
               "  Invalid current value.\n"
               TEMA_RESET);
    }
}

/*
 * ============================================================
 * FUNCAO: ler_todas_correntes
 *
 * Objetivo:
 *   Capturar tres valores de corrente e armazenar na estrutura.
 * ============================================================
 */

void ler_todas_correntes(struct Corrente *corrente)
{
    printf("\n");

    printf(TEMA_AMARELO TEMA_NEGRITO
           "[ CURRENT MEASUREMENTS ]"
           TEMA_RESET "\n\n");

    printf(TEMA_CIANO "  Measurement 1\n" TEMA_RESET);
    corrente->corrente_1 = ler_corrente();

    printf(TEMA_CIANO "  Measurement 2\n" TEMA_RESET);
    corrente->corrente_2 = ler_corrente();

    printf(TEMA_CIANO "  Measurement 3\n" TEMA_RESET);
    corrente->corrente_3 = ler_corrente();
}
