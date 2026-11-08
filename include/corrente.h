/*
 * ============================================================
 * CORRENTE.H
 *
 * Objetivo:
 *   Definir a estrutura de armazenamento das medicoes de
 *   corrente eletrica e declarar as funcoes de captura.
 * ============================================================
 */

#ifndef CORRENTE_H
#define CORRENTE_H

struct Corrente
{
    float corrente_1;
    float corrente_2;
    float corrente_3;
};

float ler_corrente(void);

void ler_todas_correntes(struct Corrente *corrente);

#endif /* CORRENTE_H */
