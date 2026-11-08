#include <stdio.h>
#include "medicao.h"
#include "terminal_theme.h"

/*
 * ============================================================
 * FUNCAO: ler_configuracao_rede
 *
 * Objetivo:
 *   Permitir ao operador selecionar a tensao nominal da rede
 *   que sera monitorada pelo sistema.
 *
 * Opcoes:
 *   1 - 127 V
 *   2 - 220 V
 *   3 - 380 V
 *
 * Retorno:
 *   Estrutura ConfiguracaoRede preenchida.
 * ============================================================
 */
struct ConfiguracaoRede ler_configuracao_rede(void)
{
    struct ConfiguracaoRede configuracao;
    int opcao;

    while (1)
    {
        printf("\n");
        printf(TEMA_AMARELO TEMA_NEGRITO
               "[ NETWORK CONFIGURATION ]"
               TEMA_RESET "\n\n");

        printf(TEMA_CIANO "  [1] 127 V\n" TEMA_RESET);
        printf(TEMA_CIANO "  [2] 220 V\n" TEMA_RESET);
        printf(TEMA_CIANO "  [3] 380 V\n" TEMA_RESET);

        printf("\n");
        printf(TEMA_VERDE "  Select nominal voltage: "
               TEMA_RESET);

        if (scanf("%d", &opcao) == 1)
        {
            while (getchar() != '\n')
            {
                /* descarta o restante da linha */
            }

            if (opcao == 1)
            {
                configuracao.tensao_nominal = 127.0f;
                break;
            }

            if (opcao == 2)
            {
                configuracao.tensao_nominal = 220.0f;
                break;
            }

            if (opcao == 3)
            {
                configuracao.tensao_nominal = 380.0f;
                break;
            }
        }
        else
        {
            while (getchar() != '\n')
            {
                /* descarta a entrada invalida */
            }
        }

        printf("\n");
        printf(TEMA_AMBAR TEMA_NEGRITO
               "[ ERROR ]"
               TEMA_RESET "\n");

        printf(TEMA_AMBAR
               "  Invalid network option.\n"
               TEMA_RESET);
    }

    while (1)
    {
        printf("\n");
        printf(TEMA_AMARELO TEMA_NEGRITO
               "[ NOMINAL FREQUENCY ]"
               TEMA_RESET "\n\n");

        printf(TEMA_CIANO "  [1] 50 Hz\n" TEMA_RESET);
        printf(TEMA_CIANO "  [2] 60 Hz\n" TEMA_RESET);

        printf("\n");
        printf(TEMA_VERDE "  Select nominal frequency: "
               TEMA_RESET);

        if (scanf("%d", &opcao) == 1)
        {
            while (getchar() != '\n')
            {
                /* descarta o restante da linha */
            }

            if (opcao == 1)
            {
                configuracao.frequencia_nominal = 50.0f;
                break;
            }

            if (opcao == 2)
            {
                configuracao.frequencia_nominal = 60.0f;
                break;
            }
        }
        else
        {
            while (getchar() != '\n')
            {
                /* descarta a entrada invalida */
            }
        }

        printf("\n");
        printf(TEMA_AMBAR TEMA_NEGRITO
               "[ ERROR ]"
               TEMA_RESET "\n");

        printf(TEMA_AMBAR
               "  Invalid frequency option.\n"
               TEMA_RESET);
    }

    return configuracao;
}
/*
 * ============================================================
 * FUNCAO: ler_tensao
 *
 * Objetivo:
 *   Receber uma tensao valida do usuario.
 *
 * Funcionamento:
 *   - Aceita valores numericos.
 *   - Rejeita entradas invalidas, exibindo mensagem em ambar.
 *   - Limpa o buffer de entrada.
 *   - Solicita novamente o valor ate obter sucesso.
 * ============================================================
 */
float ler_tensao(void)
{
    float tensao;

    while (1)
    {
        if (scanf("%f", &tensao) == 1)
        {
            while (getchar() != '\n')
            {
                /* descarta o restante da linha */
            }

            return tensao;
        }

        printf("\n" TEMA_AMBAR TEMA_NEGRITO "[ ERROR ]" TEMA_RESET "\n");
        printf(TEMA_AMBAR "  Invalid voltage value.\n" TEMA_RESET);
        printf(TEMA_VERDE "  Enter a numeric value: " TEMA_RESET);

        while (getchar() != '\n')
        {
            /* descarta a entrada invalida */
        }
    }
}

/*
 * ============================================================
 * FUNCAO: ler_todas_medicoes
 *
 * Objetivo:
 *   Solicitar e armazenar as tres tensoes de linha do
 *   sistema trifasico, preenchendo a struct Medicao.
 * ============================================================
 */
void ler_todas_medicoes(struct Medicao *medicao)
{
    printf(TEMA_VERDE "  Tensao L1-L2 (V): " TEMA_RESET);
    medicao->tensao_l1_l2 = ler_tensao();

    printf(TEMA_VERDE "  Tensao L2-L3 (V): " TEMA_RESET);
    medicao->tensao_l2_l3 = ler_tensao();

    printf(TEMA_VERDE "  Tensao L3-L1 (V): " TEMA_RESET);
    medicao->tensao_l3_l1 = ler_tensao();
}
