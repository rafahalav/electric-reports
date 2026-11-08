/*
 * ============================================================
 * FREQUENCIA.H
 *
 * Objetivo:
 *   Definir a estrutura de armazenamento das medicoes de
 *   frequencia e declarar as funcoes responsaveis pela
 *   captura dessas medicoes via terminal.
 * ============================================================
 */

#ifndef FREQUENCIA_H
#define FREQUENCIA_H

/*
 * ESTRUTURA: Frequencia
 *
 * Armazena tres medicoes de frequencia da rede eletrica.
 */
struct Frequencia
{
    float frequencia_1;
    float frequencia_2;
    float frequencia_3;
};

/*
 * ler_frequencia
 *
 * Le um unico valor de frequencia do usuario.
 *
 * Retorno:
 *   Valor de frequencia informado (float).
 */
float ler_frequencia(void);

/*
 * ler_todas_frequencias
 *
 * Orquestra a leitura das tres medicoes de frequencia.
 *
 * Parametros:
 *   frequencia - ponteiro para a struct a ser preenchida.
 */
void ler_todas_frequencias(struct Frequencia *frequencia);

#endif /* FREQUENCIA_H */
