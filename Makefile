# ============================================================
# Makefile - ELECTRIC_REPORTS v0.5
# ============================================================

CC = gcc

CFLAGS = -Wall -Wextra -Wpedantic -std=c17
CPPFLAGS = -Iinclude

TARGET = bin/electric_reports

SRC_DIR = src
BUILD_DIR = build

SRCS = $(SRC_DIR)/main.c \
       $(SRC_DIR)/medicao.c \
       $(SRC_DIR)/corrente.c \
       $(SRC_DIR)/resistencia.c \
       $(SRC_DIR)/potencia.c \
       $(SRC_DIR)/energia.c \
       $(SRC_DIR)/frequencia.c \
       $(SRC_DIR)/calculos.c \
       $(SRC_DIR)/relatorio.c
       

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

.PHONY: all clean debug

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

debug: CFLAGS += -g -fsanitize=address
debug: clean all

clean:
	rm -f $(BUILD_DIR)/*.o
	rm -f $(TARGET)
