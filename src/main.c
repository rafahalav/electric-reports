/*
 * ============================================================
 * ELECTRIC_REPORTS
 * Electrical Measurement Report Generator
 * Version 0.5
 *
 * Projeto:
 *   Gerador de Relatorios de Medicoes Eletricas
 *
 * Linguagem:
 *   C (C17)
 *
 * Plataforma:
 *   Linux
 *
 * Descricao:
 *   Sistema para entrada, processamento e apresentacao de
 *   medicoes eletricas em formato de relatorio tecnico, com
 *   estetica de terminal retro (fosforo verde).
 *
 * Estrutura (V5 - modular):
 *   - medicao.h/.c      -> struct Medicao e captura de dados
 *   - calculos.h/.c     -> media, maior, menor, variacao
 *   - relatorio.h/.c     -> apresentacao/formatacao do relatorio
 *   - terminal_theme.h   -> paleta ANSI e caracteres de caixa
 *   - main.c             -> orquestracao do fluxo principal
 * ============================================================
 */

#include "medicao.h"
#include "corrente.h"
#include "calculos.h"
#include "relatorio.h"
#include "resistencia.h"
#include "potencia.h"
#include "energia.h"
#include "frequencia.h"

int main(void)
{
    struct ConfiguracaoRede configuracao;
    struct Medicao medicao;
    struct Corrente corrente;
    struct ResultadoAnalise resultado;
    struct ResultadoAnalise resultado_corrente;
    struct Resistencia resistencia;
    struct ResultadoAnalise resultado_resistencia;
    struct Potencia potencia;
    struct ResultadoAnalise resultado_potencia;    
    struct Energia energia;
    struct ResultadoAnalise resultado_energia;
    struct Frequencia frequencia;
    struct ResultadoAnalise resultado_frequencia;   
    
    const char *report_id = "EL-2026-0001";

    /* 1. Configuracao da rede */
    configuracao = ler_configuracao_rede();

    /* 2. Cabecalho do relatorio */
    imprimir_cabecalho(report_id, &configuracao);

    /* 3. Captura das medicoes de tensao */
    ler_todas_medicoes(&medicao);

    /* 4. Captura das medicoes de corrente */
    ler_todas_correntes(&corrente);
    
    /* 5 Captura das medicoes de resistencia */
    ler_todas_resistencias(&resistencia);
    
    /* 6 Captura das medicoes de potencia */
    ler_todas_potencias(&potencia);
    
    /* 7 Captura das medicoes de energia */
    ler_todas_energias(&energia); 
    
    /* 8 Captura das medicoes de frequencia */
    ler_todas_frequencias(&frequencia);
       
    /* 9. Processamento dos dados */
    resultado = calcular_analise(&medicao);
    resultado_corrente = calcular_analise_corrente(&corrente);
    resultado_resistencia = calcular_analise_resistencia(&resistencia);
    resultado_potencia = calcular_analise_potencia(&potencia);
    resultado_energia = calcular_analise_energia(&energia);
    resultado_frequencia = calcular_analise_frequencia(&frequencia);
    
    /* 10. Apresentacao do relatorio */
    imprimir_secao_medicoes(&medicao);
    imprimir_secao_analise(&resultado);
    imprimir_secao_analise_corrente(&resultado_corrente);
    imprimir_secao_analise_resistencia(&resultado_resistencia);
    imprimir_secao_analise_potencia(&resultado_potencia);
    imprimir_secao_analise_energia(&resultado_energia);
    imprimir_secao_analise_frequencia(&resultado_frequencia);
    imprimir_status();
    imprimir_rodape();
        
    return 0;
}
