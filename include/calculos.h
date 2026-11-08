/*
 * ============================================================
 * CALCULOS.H
 *
 * Objetivo:
 *   Declarar as funcoes de calculo estatistico sobre as
 *   medicoes de tensao, e a estrutura que consolida os
 *   resultados dessa analise.
 * ============================================================
 */

#ifndef CALCULOS_H
#define CALCULOS_H

#include "medicao.h"
#include "corrente.h"
#include "resistencia.h"
#include "potencia.h"
#include "energia.h"
#include "frequencia.h"
/*
 * ESTRUTURA: ResultadoAnalise
 *
 * Consolida os resultados derivados das tres medicoes de
 * tensao, servindo como contrato de dados entre calculos.c
 * e relatorio.c.
 */
struct ResultadoAnalise
{
    float media;
    float maior;
    float menor;
    float variacao;
};

/*
 * calcular_media / encontrar_maior / encontrar_menor
 *
 * Operacoes basicas sobre as tres medicoes de tensao.
 */
float calcular_media(float valor1, float valor2, float valor3);
float encontrar_maior(float valor1, float valor2, float valor3);
float encontrar_menor(float valor1, float valor2, float valor3);

/*
 * calcular_analise
 *
 * Objetivo:
 *   A partir de uma struct Medicao, calcular media, maior
 *   valor, menor valor e variacao (amplitude), retornando
 *   tudo consolidado em uma struct ResultadoAnalise.
 *
 * Parametros:
 *   medicao - ponteiro constante para as medicoes de entrada.
 *
 * Retorno:
 *   struct ResultadoAnalise preenchida.
 */
struct ResultadoAnalise calcular_analise(const struct Medicao *medicao);
/*
 * ============================================================
 * FUNCAO: calcular_analise_corrente
 *
 * Objetivo:
 *   Calcular media, maior valor, menor valor e variacao
 *   das tres medicoes de corrente.
 * ============================================================
 */

struct ResultadoAnalise calcular_analise_corrente(
    const struct Corrente *corrente
);

struct ResultadoAnalise calcular_analise_resistencia(
    const struct Resistencia *resistencia
);

struct ResultadoAnalise calcular_analise_potencia(
    const struct Potencia *potencia
);

struct ResultadoAnalise calcular_analise_energia(
    const struct Energia *energia
);

struct ResultadoAnalise calcular_analise_frequencia(
    const struct Frequencia *frequencia
);

#endif /* CALCULOS_H */
