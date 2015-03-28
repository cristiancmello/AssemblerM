/*
 * ==========================================================================
 *
 * Nome do Arquivo:  dicLoader.h
 *
 *       Descricao:  TAD para carregamento de padrões e opcodes aceitos pelo
 *       			 assembler.
 *
 *          Versao:  1.0
 *       Criado em:  14/03/2015 20:03:08
 *         Revisao:  none
 *      Compilador:  gcc
 *
 *           Autor:  Cristian Costa Mello, Gustavo Freitas de Amorim
 *     Organizacao:  VY Cannis Majoris
 *
 * =========================================================================
 */

#ifndef DICLOADER_HEADER
#define DICLOADER_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "../../asmError.h"
 
#define DICLOADER_MAX_INST_LENGTH   256

#define DICLOADER_EALLOC            NULL
#define DICLOADER_EALLOC_MSG        "Falha ao alocar memória no TAD DICLOADER."

#define DICLOADER_EFOPEN            NULL
#define DICLOADER_EFOPEN_MSG        "Falha ao abrir arquivo de dicionário."


typedef struct _dicLoader
{
    FILE *file;
} DICLOADER;


/* -> DICLOADER *dicLoader_new(const char *filename)
 * 
 * - DESCRIÇÃO: Instancia um novo loader do dicionário que será utilizado na
 *              tradução da linguagem.
 *   
 * - PARÂMETROS: 
 *      -> const char *filename: Nome do arquivo a ser utilizado.
 *
 * - RETORNO: Estrutura do tipo DICLOADER instanciada.
 *   	-> Se NULL    - Erro na operação.
 *   	-> Se != NULL - Sucesso na operação.
 */
DICLOADER *     dicLoader_new(const char *filename);


/* -> void dicLoader_free(DICLOADER *dicLoader)
 * 
 * - DESCRIÇÃO: Destrói uma estrutura existente em memória.
 *
 * - PARÂMETROS: 
 *      -> DICWRITER *dicWriter: Estrutura a ser destruída.
 *
 * - RETORNO: void.
 */
void            dicLoader_free(DICLOADER *dicLoader);


/* -> uint64_t dicLoader_getQtdInst(DICLOADER *dicLoader)
 * 
 * - DESCRIÇÃO: Retorna os 8 próximos bytes do arquivo.
 *
 * - PARÂMETROS: 
 *      -> DICWRITER *dicWriter: Estrutura a ser utilizada para a leitura da 
 *      quantidade de instruções.
 *
 * - RETORNO: Estado da operação.
 *      -> Se 0    - Erro na operação.
 *      -> Se != 0 - Sucesso na operação.
 */
uint64_t        dicLoader_getQtdInst(DICLOADER *dicLoader);


/* -> char *dicLoader_getNextInst(DICLOADER *dicLoader)
 * 
 * - DESCRIÇÃO: Carrega a próxima entrada do arquivo de configurações. 
 *   
 * - PARÂMETROS: 
 *      -> DICWRITER *dicWriter: Estrutura a ser utilizada na leitura.
 *
 * - RETORNO: String contendo a entrada lida.
 *   	-> Se NULL    - Erro na operação.
 *   	-> Se != NULL - Sucesso na operação.
 */
char *          dicLoader_getNextInst(DICLOADER *dicLoader);

#endif /* DICLOADER_HEADER */
