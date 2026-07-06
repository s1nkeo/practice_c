#include <stdio.h>

const char* get_reg_name(int code) {
	switch (code & 0x03) {
        	case 0: return "A";
        	case 1: return "B";
        	case 2: return "C";
        	case 3: return "D";
        	default: return "?";
    }
}

int read_hex() {
	unsigned byte;
	int imm;

	while (scanf("%x", &byte) == 1) {
		if ((byte & 0x80) == 0) {
			imm = byte & 0x7F;
			printf("MOVI %d\n", imm);
		} else if ((byte & 0xC0) == 0x80) {
            		int op = (byte >> 4) & 0x03;
            		int reg1 = (byte >> 2) & 0x03;
            		int reg2 = byte & 0x03;

            		switch (op) {
                		case 0: printf("ADD %s, %s\n", get_reg_name(reg1), get_reg_name(reg2)); break;
                		case 1: printf("SUB %s, %s\n", get_reg_name(reg1), get_reg_name(reg2)); break;
                		case 2: printf("MUL %s, %s\n", get_reg_name(reg1), get_reg_name(reg2)); break;
                		case 3: printf("DIV %s, %s\n", get_reg_name(reg1), get_reg_name(reg2)); break;
            		}
        	} else if ((byte & 0xFC) == 0xC0) {
            		int reg = byte & 0x03;
            		printf("IN %s\n", get_reg_name(reg));
        	} else if ((byte & 0xFC) == 0xC4) {
            		int reg = byte & 0x03;
            		printf("OUT %s\n", get_reg_name(reg));
        	} else {
            		printf("ERROR\n");
			break;
        	}
    	}

    return 0;
}

int main() {
	read_hex();

	return 0;
}	
