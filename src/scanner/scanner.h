/*
 * ==========================================================================
 *
 * Nome do Arquivo:  scanner.h
 *
 *       Descricao:  Método para geração de tokens para o assembler.
 *
 *          Versao:  1.0
 *       Criado em:  14/03/2015 20:37:32
 *         Revisao:  none
 *      Compilador:  gcc
 *
 *           Autor:  Cristian Costa Mello, Gustavo Freitas de Amorim
 *     Organizacao:  VY Cannis Majoris
 *
 * =========================================================================
 */

#ifndef SCANNER_HEADER
#define SCANNER_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "tokens/tokens.h" /* incluir o TAD TOKENS (Conjunto de TOKENS) */


#define SCANNER_SBCLS               0x20        /* Space Bar */

#define SCANNER_ERROR               NULL
#define SCANNER_ERROR_MSG           "Falha na operação de scanner."


TOKENS *scanner_scan(const char *sentence,
                     char **ignoreList,
                     char *delims,
                     uint64_t n_ignore);

#endif /* SCANNER_HEADER */
