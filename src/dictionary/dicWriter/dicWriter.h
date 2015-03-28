/*
 * ==========================================================================
 *
 * Nome do Arquivo:  dicWriter.h
 *
 *       Descricao:  TAD para a escrita do arquivo de padrões e opcodes
 *                   aceitos pelo assembler.
 *
 *          Versao:  1.0
 *       Criado em:  07/03/2015 17:50:06
 *         Revisao:  none
 *      Compilador:  gcc
 *
 *           Autor:  Cristian Costa Mello, Gustavo Freitas de Amorim
 *     Organizacao:  VY Cannis Majoris
 *
 * =========================================================================
 */

#ifndef DICWRITER_HEADER
#define DICWRITER_HEADER

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "../../asmError.h"

#define DICWRITER_EALLOC            NULL    /* FALHA DE ALOCAÇÃO */
#define DICWRITER_EALLOC_MSG        "Falha na alocação da estrutura DICWRITER."

#define DICWRITER_EFOPEN            NULL
#define DICWRITER_EFOPEN_MSG        "Falha na abertura do arquivo de gravação do dicionário."

#define DICWRITER_SEPARATOR         "&"
#define DICWRITER_TERMINATOR        "\0"

#define DICWRITER_SEPARATOR_CHR		'&'
#define DICWRITER_TERMINATOR_CHR	'\0'


typedef struct _dicWriter
{
    FILE *file; //Ponteiro para o arquivo utilizado nas operações de escrita.
} DICWRITER;


/* -> DICWRITER *dicWriter_new(const char *filename)
 * 
 * - DESCRIÇÃO: Instancia um novo writer do dicionário que será utilizado na
 *              escrita do arquivo de configurações do mesmo.
 *   
 * - PARÂMETROS: 
 *      -> const char *filename: Nome do arquivo a ser utilizado.
 *
 * - RETORNO: Estrutura do tipo DICWRITER instanciada.
 *   	-> Se NULL    - Erro na operação.
 *   	-> Se != NULL - Sucesso na operação.
 */
DICWRITER *     dicWriter_new(const char *filename);


/* -> void dicWriter_free(DICWRITER *dicWriter)
 * 
 * - DESCRIÇÃO: Destrói uma estrutura existente em memória.
 *
 * - PARÂMETROS: 
 *      -> DICWRITER *dicWriter: Estrutura a ser destruída.
 *
 * - RETORNO: void.
 */
void            dicWriter_free(DICWRITER *dicWriter);


/* -> void dicWriter_writeQtdInst(DICWRITER *dicWriter, uint64_t num)
 * 
 * - DESCRIÇÃO: Grava no arquivo a instrução binária recebida como parâmetro.
 *
 * - PARÂMETROS: 
 *      -> DICWRITER *dicWriter: Estrutura a ser utilizada para a escrita da 
 *      quantidade de instruções.
 *      -> uint64_t num: Quantidade de instruções a ser escrita.
 *
 * - RETORNO: void.
 */
void             dicWriter_writeQtdInst(DICWRITER *dicWriter, uint64_t num);


/* -> void dicWriter_writeInst(DICWRITER *dicWriter, const char *instructionPattern, 
 *                               uint32_t opcode)
 * 
 * - DESCRIÇÃO: Grava no arquivo o padrão de instrução recebida como parâmetro.
 *
 * - PARÂMETROS: 
 *      -> ASMWRITER *asmWriter: Estrutura a ser utilizada para a escrita da 
 *      instrução.
 *      -> const char *instPattern: Padrão de instrução a ser escrito.
 *      -> const char *instTranslation: Tradução da instrução a ser escrita.
 *
 * - RETORNO: void.
 */
void             dicWriter_writeInst(DICWRITER *dicWriter, 
										const char *instPattern,
                                        const char *instTranslation);

#endif /* DICWRITER_HEADER */
