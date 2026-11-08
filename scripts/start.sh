#!/bin/bash

GREEN='\033[0;32m'
YELLOW='\033[1;33m'
RED='\033[0;31m'
BLUE='\033[0;34m'
NC='\033[0m'

PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
BINARY="$PROJECT_ROOT/bin/electric_reports"

echo -e "${BLUE}╔══════════════════════════════════════════════════╗${NC}"
echo -e "${BLUE}║         ELECTRIC_REPORTS v0.5 Launcher          ║${NC}"
echo -e "${BLUE}╚══════════════════════════════════════════════════╝${NC}"
echo ""

if ! command -v gcc &> /dev/null; then
    echo -e "${RED}[ERRO] GCC não encontrado. Instale: sudo apt install build-essential${NC}"
    exit 1
fi

if ! command -v make &> /dev/null; then
    echo -e "${RED}[ERRO] Make não encontrado. Instale: sudo apt install make${NC}"
    exit 1
fi

if [ ! -f "$BINARY" ]; then
    echo -e "${YELLOW}[INFO] Binário não encontrado. Compilando projeto...${NC}"
    echo ""
    cd "$PROJECT_ROOT"
    if make all; then
        echo ""
        echo -e "${GREEN}[OK] Compilação concluída com sucesso!${NC}"
        echo ""
    else
        echo -e "${RED}[ERRO] Falha na compilação.${NC}"
        exit 1
    fi
else
    echo -e "${GREEN}[OK] Binário encontrado. Pronto para executar.${NC}"
    echo ""
fi

echo -e "${BLUE}Iniciando ELECTRIC_REPORTS...${NC}"
echo -e "${BLUE}──────────────────────────────────────────────────${NC}"
echo ""

"$BINARY"
