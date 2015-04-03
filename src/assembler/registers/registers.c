/*
 * ==========================================================================
 *
 * Nome do Arquivo:  registers.c
 *
 *       Descricao:  Implementação do TAD REGISTERS.
 *
 *          Versao:  1.0
 *       Criado em:  21/03/2015 09:44:45
 *         Revisao:  none
 *      Compilador:  gcc
 *
 *           Autor:  Cristian Costa Mello, Gustavo Freitas de Amorim
 *     Organizacao:  VY Cannis Majoris
 *
 * =========================================================================
 */

#include "registers.h"

REGISTERS *registers_new(long int maxQtd)
{
	REGISTERS *novo;

    if((novo = (REGISTERS*)malloc(sizeof(REGISTERS))) == NULL)
	{
		asmError_setDesc(REGISTERS_EALLOC_MSG);
		return (REGISTERS_EALLOC);
	}

    if((novo->regs = (REG**)malloc(sizeof(REG*) * maxQtd)) == NULL)
	{
		free(novo);
		asmError_setDesc(REGISTERS_EALLOC_MSG);
		return (REGISTERS_EALLOC);
	}
	
	novo->qtdRegs = 0;
	novo->maxQtd = maxQtd;

	return novo;
}

void registers_free(REGISTERS *regs)
{

	if(regs->qtdRegs > 0)
	{
		for(--regs->qtdRegs; regs->qtdRegs > 0; regs->qtdRegs--)
		{
			reg_free(regs->regs[regs->qtdRegs]);
		}
	}
	
	free(regs);
}

long int registers_addReg(REGISTERS *regs, char *regName, uint8_t type)
{
	REG *novo;

	if(regs->qtdRegs >= (regs->maxQtd - 1)){
		asmError_setDesc(REGISTERS_EDECOVERFLOW_MSG);
		return (REGISTERS_EDECOVERFLOW);
	}

	if((novo = reg_new(regName, type)) == REG_EALLOC)
	{
		//Erro de alocação
		asmError_setDesc(REGISTERS_EALLOC_MSG);
		return(-1);
	}

	regs->regs[regs->qtdRegs] = novo;
	regs->qtdRegs++;
	return (regs->qtdRegs - 1); //Retorna a posição onde foi adicionado
}

long int registers_regSearch(REGISTERS *regs, char *name)
{
	
	long int i;
	for(i = 0; i < regs->qtdRegs; i++){
		if(strcmp(reg_getName(regs->regs[i]), name) == 0){
			return (i);
		}
	}
	
	return (-1);
}

uint32_t registers_getQtdRegs(REGISTERS *regs)
{
	return (regs->qtdRegs);
}
