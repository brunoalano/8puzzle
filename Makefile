# Author: Bruno Alano Medina
# Title: Makefile
# 
# LGPL Licensed
# Version: 1.0.0

# Compiler
CC = gcc

# Compiler Flags
CFLAGS = -Wall -pedantic --std=c99
LDFLAGS = -Iheaders

# Source Files
SOURCE = src/main.c src/game.c src/queue.c src/state.c

# Build
all: compile

compile: ${SOURCE}
	${CC} -o 8puzzle ${SOURCE} ${CFLAGS} ${LDFLAGS} -g