# ⚡ ELECTRIC_REPORTS - Sistema de Medição e Análise Elétrica em C

[![C Programming](https://img.shields.io/badge/Language-C-blue.svg)](https://devdocs.io/c/)
[![Version](https://img.shields.io/badge/Version-0.5-orange.svg)](https://github.com/rafahalav/electric-reports)
[![Platform](https://img.shields.io/badge/Platform-Linux%2FUnix-green.svg)](https://www.linux.org/)
[![Domain](https://img.shields.io/badge/Domain-Electrical_Engineering-red.svg)](https://www.ieee.org/)

**Sistema Profissional de Medição Elétrica Trifásica com Análise Estatística e Geração de Relatórios em Terminal**

---

## 🚀 Quick Start

Clone o repositório e acesse a pasta do projeto:
```bash
git clone https://github.com/rafahalav/electric-reports.git
cd electric-reports
```

---

## 🎯 Sobre o Projeto

O **ELECTRIC_REPORTS** é uma aplicação desenvolvida em C puro para processamento e análise de parâmetros elétricos em sistemas trifásicos. Focado em precisão técnica e usabilidade em ambiente de terminal, o sistema recebe medições de campo e gera relatórios completos com análise estatística automática (média, máximo, mínimo e variação).

### 🔌 Por Que Isso Importa?
Em ambientes industriais e de telecomunicações, a qualidade da energia elétrica é crítica. Desenvolvi este projeto para consolidar competências essenciais da engenharia moderna:
1. **Domínio Técnico Real:** Aplicação prática de cálculos de engenharia elétrica (sistemas trifásicos, análise de qualidade de energia).
2. **Programação de Baixo Nível:** C puro, sem dependências externas, otimizado para rodar em qualquer hardware limitado.
3. **Interface Profissional:** UX em terminal com tabelas ASCII, cores ANSI e formatação tipo "dashboard industrial".
4. **Arquitetura Modular:** Separação rigorosa entre headers (`include/`), implementação (`src/`) e binários (`bin/`).

---

## ⚙️ Fluxo de Trabalho: Do Campo ao Relatório

Diferente de simuladores teóricos, o **ELECTRIC_REPORTS** foi desenhado para se integrar à rotina prática de engenharia em campo. O sistema opera como uma **ferramenta de pós-processamento e análise**, seguindo este fluxo:

1. **Coleta em Campo (Manual):** Utilizo instrumentos físicos de medição (multímetros, alicates amperímetros, analisadores de rede) para coletar os dados reais das instalações elétricas.
2. **Entrada de Dados (Digital):** De posse das anotações de campo, insiro os valores no terminal do programa. A interface interativa guia a configuração do sistema (tensão nominal, frequência) e a entrada das medições.
3. **Processamento e Análise (Automático):** O motor em C calcula automaticamente as médias, variações, picos e vales de cada parâmetro elétrico.
4. **Geração do Relatório (Output):** O sistema entrega um relatório técnico padronizado, formatado em ASCII, pronto para ser copiado, salvo em `.txt` ou anexado a laudos técnicos.

> **Nota sobre Escalabilidade:** A versão atual (v0.5) opera via entrada manual de teclado para garantir portabilidade total e zero dependências em qualquer terminal Linux/Unix. No entanto, sua arquitetura modular em C puro foi propositalmente projetada para futura integração direta com hardware (leitura via porta serial/UART de microcontroladores como ESP32/Arduino, transformando-o em um sistema de telemetria em tempo real).

---

## ✨ Features Principais

### 📊 Medições Suportadas
- **Tensão:** L1-L2, L2-L3, L3-L1 (sistema trifásico)
- **Corrente:** Medições em Amperes (A)
- **Resistência:** Medições em Ohms (Ω)
- **Potência:** Medições em Watts (W)
- **Energia:** Medições em Watt-hora (Wh)
- **Frequência:** Medições em Hertz (Hz)

### 📈 Análise Estatística Automática
Para cada parâmetro medido, o sistema calcula:
- Média Aritmética
- Valor Máximo e Mínimo
- Variação Total (Δ = Máx - Mín)

### 🎨 Interface Terminal Profissional
- **Configuração Interativa:** Seleção de tensão nominal (127V/220V/380V) e frequência (50Hz/60Hz)
- **Relatórios Formatados:** Tabelas ASCII com bordas e alinhamento preciso
- **Cores e Destaque:** Códigos ANSI para melhor legibilidade
- **Report ID Único:** Identificador `EL-YYYY-NNNN` para rastreabilidade de laudos

---

## 🏗️ Arquitetura do Projeto

```text
ELECTRIC_MEASUREMENT-V5/
├── bin/                    # Executáveis compilados
│   └── electric_reports
├── build/                  # Arquivos objeto (.o)
│   ├── calculos.o, corrente.o, energia.o, frequencia.o
│   ├── main.o, medicao.o, potencia.o, relatorio.o, resistencia.o
├── include/                # Headers (interfaces públicas)
│   ├── calculos.h         # Funções matemáticas
│   ├── corrente.h         # Módulo de corrente
│   ├── energia.h          # Módulo de energia
│   ├── frequencia.h       # Módulo de frequência
│   ├── medicao.h          # Estruturas de medição
│   ├── potencia.h         # Módulo de potência
│   ├── relatorio.h        # Geração de relatórios
│   ├── resistencia.h      # Módulo de resistência
│   └── terminal_theme.h   # Tema visual do terminal (cores ANSI)
├── src/                    # Implementação (.c)
│   ├── calculos.c, corrente.c, energia.c, frequencia.c
│   ├── main.c             # Ponto de entrada
│   ├── medicao.c, potencia.c, relatorio.c, resistencia.c
├── scripts/
│   └── start.sh           # Script de inicialização
├── REPORTS/                # Relatórios gerados (cópia manual do terminal)
├── Makefile                # Automação de build
└── README.md
```

### Decisões de Engenharia
| Decisão | Justificativa |
|---|---|
| **Separação `src/` e `include/`** | Segue padrão industrial de projetos C (ex: Linux kernel), garantindo baixo acoplamento. |
| **Diretório `build/` separado** | Mantém o código fonte limpo e facilita o comando `make clean`. |
| **Headers modulares** | Cada módulo possui uma interface bem definida, facilitando a manutenção e futura expansão. |
| **Makefile customizado** | Automação completa e padronizada de compilação e linking. |

---

## 🚀 Instalação e Compilação

## Pré-requisitos
- Sistema Linux/Unix (testado em MX Linux)
- GCC (GNU Compiler Collection)
- Make

> **Dica:** No Debian/Ubuntu/MX Linux, instale tudo com um comando:
> ```bash
> sudo apt install build-essential
> ```
> Isso instala o GCC, Make e outras ferramentas essenciais de compilação.

### Executar
```bash
# O script verifica dependências, compila automaticamente se necessário e executa
./scripts/start.sh

# Ou diretamente (se já estiver compilado)
./bin/electric_reports

### Limpar Build
```bash
make clean
```

---

## 💬 Exemplo de Uso

### 1. Configuração Inicial
```text
[ NETWORK CONFIGURATION ]
  [1] 127 V
  [2] 220 V
  [3] 380 V
  Select nominal voltage: 2

[ NOMINAL FREQUENCY ]
  [1] 50 Hz
  [2] 60 Hz
  Select nominal frequency: 1
```

### 2. Relatório Final (Output)
```text
┌─────────────────────────────────────────────────────────────┐
│      E L E C T R I C _ R E P O R T S  v 0 . 5               │
└─────────────────────────────────────────────────────────────┘

[ SYSTEM ]
  Application .......... ELECTRIC_REPORTS
  Version .............. 0.5
  Report ID ............ EL-2026-0001
  Network .............. THREE-PHASE
  Nominal Voltage ...... 220 V
  Nominal Frequency .... 50 Hz
  Timestamp ............ 2026-11-08 10:30:15

[ ANALYSIS ]
┌── ANALYSIS ─────────────────────────────────────────────────┐
│  Average Voltage             223.67           V             │
│  Maximum Voltage             232.00           V             │
│  Minimum Voltage             219.00           V             │
│  Variation                    13.00           V             │
└─────────────────────────────────────────────────────────────┘
```

---

## 🧠 Contexto Profissional e Domínio Técnico

Este projeto reflete minha trajetória multidisciplinar na interseção entre **Energia, Telecomunicações e Tecnologia**. Desenvolvi o `ELECTRIC_REPORTS` para consolidar competências que considero essenciais:

- **Programação de Baixo Nível:** Implementação em C puro com gerenciamento de memória e compilação modular.
- **Engenharia Elétrica Aplicada:** Modelagem de sistemas trifásicos e análise estatística de qualidade de energia.
- **Arquitetura de Software:** Separação rigorosa de responsabilidades, seguindo padrões da indústria.

### Visão Integrada: Hardware + Software + IA
O `ELECTRIC_REPORTS` complementa meu ecossistema de projetos, demonstrando uma visão 360° da tecnologia:

| Camada | Projeto | Tecnologia |
|---|---|---|
| **Hardware / Baixo Nível** | ELECTRIC_REPORTS | C, Makefile, Terminal |
| **Software / Automação** | CIPHER AUDIT | Python, Streamlit, JSON |
| **Inteligência Artificial** | CIPHER IA v2 | LLMs, Groq API, Ollama |

Essa combinação me permite atuar em cenários complexos que exigem conhecimento tanto do **nível físico** (transistores, medições elétricas) quanto do **nível lógico** (APIs, IA, automação), uma competência valorizada em Automação Industrial, Smart Grids, Sistemas Embarcados e AI Training para domínios especializados.

---

## 📁 Estrutura de Código (Destaques)

**`medicao.h`: Estruturas de dados para medições**
```c
typedef struct {
    float tensao_l1_l2;
    float tensao_l2_l3;
    float tensao_l3_l1;
    float corrente_fase[3];
    float resistencia[3];
    float potencia[3];
    float energia[3];
    float frequencia[3];
} MedicaoEletrica;
```

**`terminal_theme.h`: Tema visual**
```c
#define COLOR_HEADER "\033[1;33m"    // Amarelo
#define COLOR_VALUE "\033[0;32m"     // Verde
#define COLOR_RESET "\033[0m"
```

---

## 🔗 Projetos Relacionados

- **CIPHER AUDIT:** Auditoria automatizada de hardening Linux - [github.com/rafahalav/cipher-audit](https://github.com/rafahalav/cipher-audit)
- **CIPHER IA v2:** Assistente de cibersegurança com IA híbrida - [github.com/rafahalav/cipher-ia-v2](https://github.com/rafahalav/cipher-ia-v2)
- **PAI Code Reviewer:** Analisador de código Python assistido por IA - [github.com/rafahalav/pai-code-reviewer](https://github.com/rafahalav/pai-code-reviewer)

---

## 🧑‍💻 Autor

**Rafael Halav**  
Technology Professional | Energy • Electrical Technology • Telecommunications • IT • Python • C • AI • Data  
🔗 [LinkedIn](https://www.linkedin.com/in/rafael-halav) | ✉️ [Contato](mailto:rafa.halav83@gmail.com)

*Desenvolvido com foco em aprendizado contínuo e aplicação prática de programação de baixo nível e alta performance em cenários de recursos limitados e engenharia elétrica.*

---

**Status:** Active Development  
**Versão Atual:** 0.5  
**Última atualização:** Novembro 2026
```
https://github.com/rafahalav/electric-reports.git
