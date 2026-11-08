#!/bin/bash

# ============================================================
# ELECTRIC_REPORTS v0.5
# Script de inicialização
# ============================================================

PROJECT_DIR="$(cd "$(dirname "$0")/.." && pwd)"
PROGRAM="$PROJECT_DIR/bin/electric_reports"

clear

printf '%s\n' "=============================================="
printf '%s\n' "          ELECTRIC_REPORTS v0.5"
printf '%s\n' "=============================================="
printf '\n'

if [ ! -x "$PROGRAM" ]; then
    printf '%s\n' "[ERROR] Executable not found."
    printf '%s\n' ""
    printf '%s\n' "Run 'make' before starting the program."
    exit 1
fi

printf '%s\n' "[SYSTEM] Starting ELECTRIC_REPORTS..."
printf '\n'

"$PROGRAM"

STATUS=$?

printf '\n'
printf '%s\n' "[SYSTEM] Program finished with status: $STATUS"

exit "$STATUS"
