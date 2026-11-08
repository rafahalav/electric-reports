/*
 * ============================================================
 * MEDICAO.H
 *
 * Objetivo:
 *   Definir a estrutura de armazenamento das medicoes de
 *   tensao e declarar as funcoes responsaveis pela captura
 *   dessas medicoes via terminal.
 * ============================================================
 */

#ifndef MEDICAO_H
#define MEDICAO_H

/*
 * ESTRUTURA: ConfiguracaoRede
 *
 * Define os parametros nominais da rede eletrica que sera
 * monitorada pelo sistema.
 */
struct ConfiguracaoRede
{
    float tensao_nominal;
    float frequencia_nominal;
};

/*
 * ESTRUTURA: Medicao
 *
 * Armazena as tres tensoes de linha medidas em um sistema
 * trifasico (L1-L2, L2-L3, L3-L1).
 */
struct Medicao
{
    float tensao_l1_l2;
    float tensao_l2_l3;
    float tensao_l3_l1;
};

/*
 * ler_tensao
 *
 * Le um unico valor de tensao do usuario, validando o tipo
 * de entrada (rejeita nao-numericos) e limpando o buffer.
 *
 * Retorno:
 *   Valor de tensao informado (float).
 */
float ler_tensao(void);

/*
 * ler_todas_medicoes
 *
 * Orquestra a leitura das tres tensoes de linha, preenchendo
 * a struct Medicao apontada por 'medicao'.
 *
 * Parametros:
 *   medicao - ponteiro para a struct a ser preenchida.
 */
/*
 * ler_configuracao_rede
 *
 * Permite selecionar a tensao nominal da rede que sera
 * monitorada pelo sistema.
 *
 * Opcoes:
 *   127 V
 *   220 V
 *   380 V
 *
 * Retorno:
 *   Estrutura ConfiguracaoRede preenchida.
 */
struct ConfiguracaoRede ler_configuracao_rede(void);

void ler_todas_medicoes(struct Medicao *medicao);

#endif /* MEDICAO_H */
