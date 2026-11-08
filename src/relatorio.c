/*
 * ============================================================
 * ELECTRIC_REPORTS
 * Electrical Measurement Report Generator
 *
 * Arquivo:
 *   relatorio.c
 *
 * Versao:
 *   0.5
 *
 * Projeto:
 *   ELECTRIC_MEASUREMENT-V5
 *
 * Modulo:
 *   Geracao e apresentacao do relatorio tecnico.
 *
 * Linguagem:
 *   C (C17)
 *
 * Plataforma:
 *   Linux
 *
 * Descricao:
 *   Responsavel pela apresentacao visual dos dados coletados
 *   pelo sistema de medicao eletrica.
 *
 * ============================================================
 */

#include <stdio.h>
#include <string.h>
#include <time.h>

#include "relatorio.h"
#include "terminal_theme.h"

/* ============================================================
 * CONFIGURACAO
 * ============================================================ */

#define LARGURA_CAIXA 61

/* ============================================================
 * FUNCOES AUXILIARES
 * ============================================================ */

/*
 * ------------------------------------------------------------
 * imprimir_borda
 *
 * Borda estrutural principal.
 * ------------------------------------------------------------
 */

static void imprimir_borda(const char *canto_esquerdo,
                           const char *canto_direito)
{
    int i;

    printf("%s%s", TEMA_AMARELO, canto_esquerdo);

    for (i = 0; i < LARGURA_CAIXA; i++)
    {
        printf("%s", BOX_H);
    }

    printf("%s%s\n", canto_direito, TEMA_RESET);
}

/*
 * ------------------------------------------------------------
 * imprimir_borda_titulo
 *
 * Borda superior de uma secao.
 *
 * A cor e recebida como argumento porque 'cor' e uma
 * variavel, e nao pode ser concatenada diretamente com
 * literais dentro do printf.
 * ------------------------------------------------------------
 */

static void imprimir_borda_titulo(const char *titulo,
                                  const char *cor)
{
    int usados;
    int restante;
    int i;

    usados = 4 + (int)strlen(titulo);

    restante = LARGURA_CAIXA - usados;

    if (restante < 0)
    {
        restante = 0;
    }

    printf("%s%s", cor, TEMA_NEGRITO);

    printf("%s%s%s %s ",
           BOX_TL,
           BOX_H,
           BOX_H,
           titulo);

    for (i = 0; i < restante; i++)
    {
        printf("%s", BOX_H);
    }

    printf("%s%s\n", BOX_TR, TEMA_RESET);
}

/*
 * ------------------------------------------------------------
 * imprimir_linha_cor
 *
 * Estrutura da caixa em amarelo.
 * Conteudo em cor semantica.
 * ------------------------------------------------------------
 */

static void imprimir_linha_cor(const char *conteudo,
                               const char *cor)
{
    printf("%s%s%s",
           TEMA_AMARELO,
           BOX_V,
           TEMA_RESET);

    printf(" %s%-*s%s",
           cor,
           LARGURA_CAIXA - 1,
           conteudo,
           TEMA_RESET);

    printf("%s%s%s\n",
           TEMA_AMARELO,
           BOX_V,
           TEMA_RESET);
}

/*
 * ------------------------------------------------------------
 * timestamp_atual
 * ------------------------------------------------------------
 */

static void timestamp_atual(char *buffer,
                            size_t tamanho)
{
    time_t agora;
    struct tm *info_tempo;

    agora = time(NULL);

    info_tempo = localtime(&agora);

    if (info_tempo != NULL)
    {
        strftime(buffer,
                 tamanho,
                 "%Y-%m-%d %H:%M:%S",
                 info_tempo);
    }
    else
    {
        snprintf(buffer,
                 tamanho,
                 "UNKNOWN");
    }
}

/* ============================================================
 * CABECALHO
 * ============================================================ */

void imprimir_cabecalho(
    const char *report_id,
    const struct ConfiguracaoRede *configuracao)
{
    char timestamp[32];
    int i;

    timestamp_atual(timestamp,
                    sizeof(timestamp));

    printf("\n");

    /*
     * Borda superior.
     */

    printf("%s%s%s",
           TEMA_AMARELO,
           TEMA_NEGRITO,
           BOX_TL);

    for (i = 0; i < LARGURA_CAIXA; i++)
    {
        printf("%s", BOX_H);
    }

    printf("%s%s\n",
           BOX_TR,
           TEMA_RESET);

    /*
     * Identidade.
     */

    printf("%s%s%s",
           TEMA_AMARELO,
           TEMA_NEGRITO,
           BOX_V);

    printf(" %-*s",
           LARGURA_CAIXA - 1,
           "     E L E C T R I C _ R E P O R T S  v 0 . 5");

    printf("%s%s\n",
           BOX_V,
           TEMA_RESET);

    /*
     * Borda inferior.
     */

    printf("%s%s%s",
           TEMA_AMARELO,
           TEMA_NEGRITO,
           BOX_BL);

    for (i = 0; i < LARGURA_CAIXA; i++)
    {
        printf("%s", BOX_H);
    }

    printf("%s%s\n",
           BOX_BR,
           TEMA_RESET);

    printf("\n");

    /*
     * SYSTEM
     */

    printf("%s%s[ SYSTEM ]%s\n",
           TEMA_ROXO,
           TEMA_NEGRITO,
           TEMA_RESET);

    /*
     * Metadados tecnicos.
     */

    printf("%s  Application .......... %sELECTRIC_REPORTS%s\n",
           TEMA_CIANO,
           TEMA_AMARELO,
           TEMA_RESET);

    printf("%s  Version .............. %s0.5%s\n",
           TEMA_CIANO,
           TEMA_AMARELO,
           TEMA_RESET);

    printf("%s  Report ID ............ %s%s%s\n",
           TEMA_CIANO,
           TEMA_AMARELO,
           report_id,
           TEMA_RESET);

    printf("%s  Network .............. %sTHREE-PHASE%s\n",
           TEMA_CIANO,
           TEMA_AMARELO,
           TEMA_RESET);

    printf("%s  Nominal Voltage ...... %s%.0f V%s\n",
           TEMA_CIANO,
           TEMA_AMARELO,
           configuracao->tensao_nominal,
           TEMA_RESET);
   
    printf("%s  Nominal Frequency .... %s%.0f Hz%s\n",
           TEMA_BRANCO,
           TEMA_AMARELO,
           configuracao->frequencia_nominal,
           TEMA_RESET);

    printf("%s  Timestamp ............ %s%s%s\n",
           TEMA_CIANO,
           TEMA_AMARELO,
           timestamp,
           TEMA_RESET);
}

/* ============================================================
 * MEDICOES
 * ============================================================ */

void imprimir_secao_medicoes(const struct Medicao *medicao)
{
    char linha[80];

    printf("\n");

    printf("%s%s[ MEASUREMENTS ]%s\n",
           TEMA_AMARELO,
           TEMA_NEGRITO,
           TEMA_RESET);

    imprimir_borda_titulo("MEASUREMENTS",
                          TEMA_AMARELO);

    imprimir_linha_cor(
        " Parameter               Value          Unit",
        TEMA_AMBAR);

    imprimir_linha_cor(
        " -------------------------------------------",
        TEMA_AMBAR);

    snprintf(linha,
             sizeof(linha),
             " L1-L2                   %8.2f           V",
             medicao->tensao_l1_l2);

    imprimir_linha_cor(linha,
                       TEMA_CIANO);

    snprintf(linha,
             sizeof(linha),
             " L2-L3                   %8.2f           V",
             medicao->tensao_l2_l3);

    imprimir_linha_cor(linha,
                       TEMA_CIANO);

    snprintf(linha,
             sizeof(linha),
             " L3-L1                   %8.2f           V",
             medicao->tensao_l3_l1);

    imprimir_linha_cor(linha,
                       TEMA_CIANO);

    imprimir_borda(BOX_BL,
                   BOX_BR);
}

/* ============================================================
 * ANALISE
 * ============================================================ */

void imprimir_secao_analise(
    const struct ResultadoAnalise *resultado)
{
    char linha[80];

    printf("\n");

    printf("%s%s[ ANALYSIS ]%s\n",
           TEMA_LARANJA,
           TEMA_NEGRITO,
           TEMA_RESET);

    imprimir_borda_titulo("ANALYSIS",
                          TEMA_LARANJA);

    /*
     * Todos os rotulos utilizam exatamente 25 caracteres.
     * Isso garante que todos os valores fiquem na mesma coluna.
     */

    snprintf(linha,
             sizeof(linha),
             " %-25s %8.2f           V",
             "Average Voltage",
             resultado->media);

    imprimir_linha_cor(linha,
                       TEMA_LARANJA);

    snprintf(linha,
             sizeof(linha),
             " %-25s %8.2f           V",
             "Maximum Voltage",
             resultado->maior);

    imprimir_linha_cor(linha,
                       TEMA_LARANJA);

    snprintf(linha,
             sizeof(linha),
             " %-25s %8.2f           V",
             "Minimum Voltage",
             resultado->menor);

    imprimir_linha_cor(linha,
                       TEMA_LARANJA);

    snprintf(linha,
             sizeof(linha),
             " %-25s %8.2f           V",
             "Variation",
             resultado->variacao);

    imprimir_linha_cor(linha,
                       TEMA_AMBAR);

    imprimir_borda(BOX_BL,
                   BOX_BR);
}

/* ============================================================
 * STATUS
 * ============================================================ */

void imprimir_status(void)
{
    printf("\n");

    printf("%s%s[ STATUS ]%s\n",
           TEMA_ROXO,
           TEMA_NEGRITO,
           TEMA_RESET);

    imprimir_borda_titulo("STATUS",
                          TEMA_ROXO);

    imprimir_linha_cor(
        " Measurement state : RECORDED",
        TEMA_VERDE);

    imprimir_linha_cor(
        " Analysis state    : COMPLETED",
        TEMA_VERDE);

    imprimir_borda(BOX_BL,
                   BOX_BR);
}

/* ============================================================
 * RODAPE
 * ============================================================ */

void imprimir_rodape(void)
{
    int i;
    int largura_total;
    int espacos_eof;
    int largura_eof = 5;

    largura_total = LARGURA_CAIXA + 2;

    printf("\n");

    /*
     * Linha superior.
     */

    printf("%s%s",
           TEMA_AMARELO,
           TEMA_NEGRITO);

    for (i = 0; i < largura_total; i++)
    {
        printf("%s", BOX_DH);
    }

    printf("%s\n",
           TEMA_RESET);

    /*
     * EOF centralizado.
     */

    espacos_eof =
        (largura_total - largura_eof) / 2;

    if (espacos_eof < 0)
    {
        espacos_eof = 0;
    }

    printf("%s%s",
           TEMA_AMARELO,
           TEMA_NEGRITO);

    for (i = 0; i < espacos_eof; i++)
    {
        printf(" ");
    }

    printf("E O F");

    printf("%s\n",
           TEMA_RESET);

    /*
     * Linha inferior.
     */

    printf("%s%s",
           TEMA_AMARELO,
           TEMA_NEGRITO);

    for (i = 0; i < largura_total; i++)
    {
        printf("%s", BOX_DH);
    }

    printf("%s\n\n",
           TEMA_RESET);
}


/*
 * ============================================================
 * FUNCAO: imprimir_secao_analise_corrente
 *
 * Objetivo:
 *   Exibir os resultados estatisticos das tres medicoes
 *   de corrente eletrica.
 * ============================================================
 */

void imprimir_secao_analise_corrente(
    const struct ResultadoAnalise *resultado)
{
    char linha[80];

    printf("\n");

    printf("%s%s[ CURRENT ANALYSIS ]%s\n",
           TEMA_CIANO,
           TEMA_NEGRITO,
           TEMA_RESET);

    imprimir_borda_titulo("CURRENT ANALYSIS",
                          TEMA_CIANO);

    /*
     * Todos os rotulos utilizam exatamente 25 caracteres.
     * Isso garante que todos os valores fiquem na mesma coluna.
     */

    snprintf(linha,
             sizeof(linha),
             " %-25s %8.2f           A",
             "Average Current",
             resultado->media);

    imprimir_linha_cor(linha,
                       TEMA_CIANO);

    snprintf(linha,
             sizeof(linha),
             " %-25s %8.2f           A",
             "Maximum Current",
             resultado->maior);

    imprimir_linha_cor(linha,
                       TEMA_CIANO);

    snprintf(linha,
             sizeof(linha),
             " %-25s %8.2f           A",
             "Minimum Current",
             resultado->menor);

    imprimir_linha_cor(linha,
                       TEMA_CIANO);

    snprintf(linha,
             sizeof(linha),
             " %-25s %8.2f           A",
             "Variation",
             resultado->variacao);

    imprimir_linha_cor(linha,
                       TEMA_CIANO);

    imprimir_borda(BOX_BL,
                   BOX_BR);
}
                                                       
void imprimir_secao_analise_resistencia(
    const struct ResultadoAnalise *resultado)
{
    char linha[80];

    printf("\n");

    printf("%s%s[ RESISTANCE ANALYSIS ]%s\n",
           TEMA_VERDE,
           TEMA_NEGRITO,
           TEMA_RESET);

    imprimir_borda_titulo("RESISTANCE ANALYSIS",
                          TEMA_VERDE);

    /*
     * Todos os rotulos utilizam exatamente 25 caracteres.
     * Isso garante que todos os valores fiquem na mesma coluna.
     */

    snprintf(linha,
             sizeof(linha),
             " %-25s %8.2f           Ohm",
             "Average Resistance",
             resultado->media);

    imprimir_linha_cor(linha,
                       TEMA_VERDE);

    snprintf(linha,
             sizeof(linha),
             " %-25s %8.2f           Ohm",
             "Maximum Resistance",
             resultado->maior);

    imprimir_linha_cor(linha,
                       TEMA_VERDE);

    snprintf(linha,
             sizeof(linha),
             " %-25s %8.2f           Ohm",
             "Minimum Resistance",
             resultado->menor);

    imprimir_linha_cor(linha,
                       TEMA_VERDE);

    snprintf(linha,
             sizeof(linha),
             " %-25s %8.2f           Ohm",
             "Variation",
             resultado->variacao);

    imprimir_linha_cor(linha,
                       TEMA_VERDE);

    imprimir_borda(BOX_BL,
                   BOX_BR);
}

void imprimir_secao_analise_potencia(
    const struct ResultadoAnalise *resultado)
{
    char linha[80];

    printf("\n");

    printf("%s%s[ POWER ANALYSIS ]%s\n",
           TEMA_AMARELO,
           TEMA_NEGRITO,
           TEMA_RESET);

    imprimir_borda_titulo("POWER ANALYSIS",
                          TEMA_AMARELO);

    /*
     * Todos os rotulos utilizam exatamente 25 caracteres.
     * Isso garante que todos os valores fiquem na mesma coluna.
     */

    snprintf(linha,
             sizeof(linha),
             " %-25s %8.2f           W",
             "Average Power",
             resultado->media);

    imprimir_linha_cor(linha,
                       TEMA_AMARELO);

    snprintf(linha,
             sizeof(linha),
             " %-25s %8.2f           W",
             "Maximum Power",
             resultado->maior);

    imprimir_linha_cor(linha,
                       TEMA_AMARELO);

    snprintf(linha,
             sizeof(linha),
             " %-25s %8.2f           W",
             "Minimum Power",
             resultado->menor);

    imprimir_linha_cor(linha,
                       TEMA_AMARELO);

    snprintf(linha,
             sizeof(linha),
             " %-25s %8.2f           W",
             "Variation",
             resultado->variacao);

    imprimir_linha_cor(linha,
                       TEMA_AMARELO);

    imprimir_borda(BOX_BL,
                   BOX_BR);
}

void imprimir_secao_analise_energia(
    const struct ResultadoAnalise *resultado)
{
    char linha[80];

    printf("\n");

    printf("%s%s[ ENERGY ANALYSIS ]%s\n",
           TEMA_CIANO,
           TEMA_NEGRITO,
           TEMA_RESET);

    imprimir_borda_titulo("ENERGY ANALYSIS",
                          TEMA_CIANO);

    /*
     * Todos os rotulos utilizam exatamente 25 caracteres.
     * Isso garante que todos os valores fiquem na mesma coluna.
     */

    snprintf(linha,
             sizeof(linha),
             " %-25s %8.2f           Wh",
             "Average Energy",
             resultado->media);

    imprimir_linha_cor(linha,
                       TEMA_CIANO);

    snprintf(linha,
             sizeof(linha),
             " %-25s %8.2f           Wh",
             "Maximum Energy",
             resultado->maior);

    imprimir_linha_cor(linha,
                       TEMA_CIANO);

    snprintf(linha,
             sizeof(linha),
             " %-25s %8.2f           Wh",
             "Minimum Energy",
             resultado->menor);

    imprimir_linha_cor(linha,
                       TEMA_CIANO);

    snprintf(linha,
             sizeof(linha),
             " %-25s %8.2f           Wh",
             "Variation",
             resultado->variacao);

    imprimir_linha_cor(linha,
                       TEMA_CIANO);

    imprimir_borda(BOX_BL,
                   BOX_BR);
}

void imprimir_secao_analise_frequencia(
    const struct ResultadoAnalise *resultado)
{
    char linha[80];

    printf("\n");

    printf("%s%s[ FREQUENCY ANALYSIS ]%s\n",
           TEMA_BRANCO,
           TEMA_NEGRITO,
           TEMA_RESET);

    imprimir_borda_titulo("FREQUENCY ANALYSIS",
                          TEMA_BRANCO);

    /*
     * Todos os rotulos utilizam exatamente 25 caracteres.
     * Isso garante que todos os valores fiquem na mesma coluna.
     */

    snprintf(linha,
             sizeof(linha),
             " %-25s %8.2f           Hz",
             "Average Frequency",
             resultado->media);

    imprimir_linha_cor(linha,
                       TEMA_BRANCO);

    snprintf(linha,
             sizeof(linha),
             " %-25s %8.2f           Hz",
             "Maximum Frequency",
             resultado->maior);

    imprimir_linha_cor(linha,
                       TEMA_BRANCO);

    snprintf(linha,
             sizeof(linha),
             " %-25s %8.2f           Hz",
             "Minimum Frequency",
             resultado->menor);

    imprimir_linha_cor(linha,
                       TEMA_BRANCO);

    snprintf(linha,
             sizeof(linha),
             " %-25s %8.2f           Hz",
             "Variation",
             resultado->variacao);

    imprimir_linha_cor(linha,
                       TEMA_BRANCO);

    imprimir_borda(BOX_BL,
                   BOX_BR);
}
