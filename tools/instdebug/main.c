#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define COMPILING_INSTDEBUG 1

extern void     asmError_setDesc(const char *failureDesc);

#include "../../src/instruction/instruction.h"

int main(int argc, char **argv)
{
    uint8_t numInst[12];
	uint32_t regQtd;
    TYPE_R tipo_r;
	TYPE_ESP_BEQZ tipo_esp_beqz;
	int i;
	int tmpValue;
	uint8_t tmpType;

	if(argc == 1)
	{
		printf("Insira um arquivo de entrada...\n");
		return (EXIT_FAILURE);
	}

    FILE *file = fopen(argv[1], "rb+");

	fread(&regQtd, sizeof(uint32_t), 1, file);

	printf("qtd regs: %u\n\n", regQtd);

	//Exibe o cabeçalho
	for(i = 0; i < regQtd; i++)
	{
		printf("Reg %u:\n", i);

		fread(&tmpType, sizeof(uint8_t), 1, file);
		printf("  Type : %i\n", tmpType);

		fread(&tmpValue, sizeof(int), 1, file);
		printf("  Value: %i\n\n", tmpValue);
	}

    fread(numInst, sizeof(TYPE_R), 1, file);
    INSTRUCTION_SETINST(tipo_r, numInst);
    
	while (!feof(file))
    {

        if (tipo_r.opcode >= 1 && tipo_r.opcode <= 22)
        {
            INSTRUCTION_SETINST(tipo_r, numInst);

            printf("opcode   : %d\n", tipo_r.opcode);
            printf("reg      : %d\n", tipo_r.reg);
            printf("address  : %d\n\n", tipo_r.address);
        }

		else if (tipo_r.opcode == 56)
		{
			INSTRUCTION_SETINST(tipo_esp_beqz, numInst);

			printf("opcode	 : %d\n", tipo_esp_beqz.opcode);
			printf("register : %d\n", tipo_esp_beqz.reg);
			printf("address_t: %d\n", tipo_esp_beqz.address_t);
			printf("address_f: %d\n\n", tipo_esp_beqz.address_f);

		}

		else
		{
			printf("Instrução inválida!\n");
		}
        
		fread(numInst, sizeof(TYPE_R), 1, file);
        INSTRUCTION_SETINST(tipo_r, numInst);
    }

    fclose(file);

    return 0;
}

void asmError_setDesc(const char *failureDesc)
{
	printf("Ocorreu um erro ao alocar uma nova instrução...\n");
}
