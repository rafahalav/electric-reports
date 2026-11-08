#include "calculos.h"

/*
 * ============================================================
 * FUNCAO: calcular_media
 * ============================================================
 */
float calcular_media(float valor1, float valor2, float valor3)
{
    return (valor1 + valor2 + valor3) / 3;
}

/*
 * ============================================================
 * FUNCAO: encontrar_maior
 * ============================================================
 */
float encontrar_maior(float valor1, float valor2, float valor3)
{
    float maior = valor1;

    if (valor2 > maior)
    {
        maior = valor2;
    }

    if (valor3 > maior)
    {
        maior = valor3;
    }

    return maior;
}

/*
 * ============================================================
 * FUNCAO: encontrar_menor
 * ============================================================
 */
float encontrar_menor(float valor1, float valor2, float valor3)
{
    float menor = valor1;

    if (valor2 < menor)
    {
        menor = valor2;
    }

    if (valor3 < menor)
    {
        menor = valor3;
    }

    return menor;
}

/*
 * ============================================================
 * FUNCAO: calcular_analise
 *
 * Objetivo:
 *   Consolidar media, maior, menor e variacao das tres
 *   tensoes de linha em uma unica struct de resultado.
 * ============================================================
 */
struct ResultadoAnalise calcular_analise(const struct Medicao *medicao)
{
    struct ResultadoAnalise resultado;

    resultado.media = calcular_media(
        medicao->tensao_l1_l2,
        medicao->tensao_l2_l3,
        medicao->tensao_l3_l1
    );

    resultado.maior = encontrar_maior(
        medicao->tensao_l1_l2,
        medicao->tensao_l2_l3,
        medicao->tensao_l3_l1
    );

    resultado.menor = encontrar_menor(
        medicao->tensao_l1_l2,
        medicao->tensao_l2_l3,
        medicao->tensao_l3_l1
    );

    resultado.variacao = resultado.maior - resultado.menor;

    return resultado;
}


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
    const struct Corrente *corrente)
{
    struct ResultadoAnalise resultado;

    resultado.media = calcular_media(
        corrente->corrente_1,
        corrente->corrente_2,
        corrente->corrente_3
    );

    resultado.maior = encontrar_maior(
        corrente->corrente_1,
        corrente->corrente_2,
        corrente->corrente_3
    );

    resultado.menor = encontrar_menor(
        corrente->corrente_1,
        corrente->corrente_2,
        corrente->corrente_3
    );

    resultado.variacao = resultado.maior - resultado.menor;

    return resultado;
}

struct ResultadoAnalise calcular_analise_resistencia(
    const struct Resistencia *resistencia)
{
    struct ResultadoAnalise resultado;

    resultado.media = calcular_media(
        resistencia->resistencia_1,
        resistencia->resistencia_2,
        resistencia->resistencia_3
    );

    resultado.maior = encontrar_maior(
        resistencia->resistencia_1,
        resistencia->resistencia_2,
        resistencia->resistencia_3
    );

    resultado.menor = encontrar_menor(
        resistencia->resistencia_1,
        resistencia->resistencia_2,
        resistencia->resistencia_3
    );

    resultado.variacao = resultado.maior - resultado.menor;
    return resultado;
}

    struct ResultadoAnalise calcular_analise_potencia(
    const struct Potencia *potencia)
{
    struct ResultadoAnalise resultado;

    resultado.media = calcular_media(
        potencia->potencia_1,
        potencia->potencia_2,
        potencia->potencia_3
    );

    resultado.maior = encontrar_maior(
        potencia->potencia_1,
        potencia->potencia_2,
        potencia->potencia_3
    );

    resultado.menor = encontrar_menor(
        potencia->potencia_1,
        potencia->potencia_2,
        potencia->potencia_3
    );

    resultado.variacao = resultado.maior - resultado.menor;

    return resultado;
}

struct ResultadoAnalise calcular_analise_energia(
    const struct Energia *energia)
{
    struct ResultadoAnalise resultado;

    resultado.media = calcular_media(
        energia->energia_1,
        energia->energia_2,
        energia->energia_3
    );

    resultado.maior = encontrar_maior(
        energia->energia_1,
        energia->energia_2,
        energia->energia_3
    );

    resultado.menor = encontrar_menor(
        energia->energia_1,
        energia->energia_2,
        energia->energia_3
    );

    resultado.variacao = resultado.maior - resultado.menor;

    return resultado;
}

struct ResultadoAnalise calcular_analise_frequencia(
    const struct Frequencia *frequencia)
{
    struct ResultadoAnalise resultado;

    resultado.media = calcular_media(
        frequencia->frequencia_1,
        frequencia->frequencia_2,
        frequencia->frequencia_3
    );

    resultado.maior = encontrar_maior(
        frequencia->frequencia_1,
        frequencia->frequencia_2,
        frequencia->frequencia_3
    );

    resultado.menor = encontrar_menor(
        frequencia->frequencia_1,
        frequencia->frequencia_2,
        frequencia->frequencia_3
    );

    resultado.variacao = resultado.maior - resultado.menor;

    return resultado;
}
