/*
 * ============================================================
 * TERMINAL_THEME.H
 *
 * ELECTRIC_REPORTS
 * Sistema de identidade visual do terminal.
 *
 * Objetivo:
 *   Centralizar os codigos ANSI utilizados pelo ELECTRIC_REPORTS.
 *
 * Conceito visual:
 *   Terminal tecnico / retro-futurista / instrumentacao
 *   eletrica / desenvolvimento de software.
 *
 * Hierarquia de cores:
 *
 *   AMARELO  -> estrutura e identidade principal
 *   CIANO    -> dados tecnicos e medicoes
 *   LARANJA  -> processamento e analise
 *   AMBAR    -> atencao e elementos auxiliares
 *   ROXO     -> sistema e automacao
 *   VERDE    -> estado normal / concluido
 *   VERMELHO -> erro / estado critico
 *
 * Observacao:
 *   Nenhuma cor de fundo e definida.
 *   O terminal permanece com seu background original.
 *
 * ============================================================
 */

#ifndef TERMINAL_THEME_H
#define TERMINAL_THEME_H

/* ------------------------------------------------------------
 * CONTROLE
 * ------------------------------------------------------------ */

#define TEMA_RESET      "\033[0m"

/* ------------------------------------------------------------
 * ATRIBUTOS
 * ------------------------------------------------------------ */

#define TEMA_NEGRITO    "\033[1m"
#define TEMA_REVERSE    "\033[7m"
#define TEMA_BLINK      "\033[5m"

/* ------------------------------------------------------------
 * PALETA
 * ------------------------------------------------------------ */

/* Destaque / referencia */
#define TEMA_AMARELO    "\033[38;2;255;255;0m"

/* Dados tecnicos */
#define TEMA_CIANO      "\033[38;2;0;255;255m"

/* Analise / processamento */
#define TEMA_LARANJA    "\033[38;2;255;120;0m"

/* Atencao */
#define TEMA_AMBAR      "\033[38;2;255;180;0m"

/* Sistema / automacao */
#define TEMA_ROXO       "\033[38;2;200;0;255m"

/* Estado normal / concluido */
#define TEMA_VERDE      "\033[38;2;0;255;100m"

/* Erro / critico */
#define TEMA_VERMELHO   "\033[38;2;255;40;40m"

/* Informacao neutra */
#define TEMA_BRANCO     "\033[38;2;255;255;255m"

/* ------------------------------------------------------------
 * CARACTERES DE DESENHO
 * ------------------------------------------------------------ */

#define BOX_H       "\u2500"
#define BOX_V       "\u2502"

#define BOX_TL      "\u250C"
#define BOX_TR      "\u2510"
#define BOX_BL      "\u2514"
#define BOX_BR      "\u2518"

#define BOX_TEE_L   "\u251C"
#define BOX_TEE_R   "\u2524"

#define BOX_DH      "\u2550"

#endif /* TERMINAL_THEME_H */
