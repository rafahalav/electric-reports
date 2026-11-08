/*
 * ============================================================
 * RELATORIO.H
 *
 * Objetivo:
 *   Declarar as funcoes responsaveis por apresentar o
 *   relatorio de medicoes eletricas no terminal, com a
 *   estetica retro de fosforo verde definida em
 *   terminal_theme.h.
 *
 * Observacao:
 *   Este modulo cuida apenas de FORMATACAO e EXIBICAO.
 *   Nenhuma logica de calculo ou captura de dados deve
 *   viver aqui.
 * ============================================================
 */

#ifndef RELATORIO_H
#define RELATORIO_H

#include "medicao.h"
#include "corrente.h"
#include "resistencia.h"
#include "potencia.h"
#include "energia.h"
#include "frequencia.h"
#include "calculos.h"
#include "relatorio.h"

/*
 * imprimir_cabecalho
 *
 * Exibe o cabecalho do relatorio (titulo em reverse video,
 * bloco [ SYSTEM ] com versao, Report ID e timestamp atual).
 *
 * Parametros:
 *   report_id - identificador do relatorio (ex.: "EL-2026-0001").
 */
void imprimir_cabecalho(
    const char *report_id,
    const struct ConfiguracaoRede *configuracao
);

/*
 * imprimir_secao_medicoes
 *
 * Exibe a tabela com os tres valores de tensao medidos.
 */
void imprimir_secao_medicoes(const struct Medicao *medicao);

/*
 * imprimir_secao_analise
 *
 * Exibe o bloco de analise: media, maior, menor e variacao.
 */
void imprimir_secao_analise(
    const struct ResultadoAnalise *resultado
);

void imprimir_secao_analise_corrente(
    const struct ResultadoAnalise *resultado
);

void imprimir_secao_analise_resistencia(
    const struct ResultadoAnalise *resultado
);

void imprimir_secao_analise_potencia(
    const struct ResultadoAnalise *resultado
);

void imprimir_secao_analise_energia(
    const struct ResultadoAnalise *resultado
);

void imprimir_secao_analise_energia(
    const struct ResultadoAnalise *resultado
);

void imprimir_secao_analise_frequencia(
    const struct ResultadoAnalise *resultado
);

void imprimir_status(void);

/*
 * imprimir_status
 *
 * Exibe o bloco final de status da medicao/analise.
 */
void imprimir_status(void);

/*
 * imprimir_rodape
 *
 * Exibe a linha de fechamento (EOF) do relatorio.
 */
void imprimir_rodape(void);

#endif /* RELATORIO_H */
