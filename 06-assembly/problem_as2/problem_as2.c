#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "problem_mk.h"

int decode_command(unsigned char cmd, struct instr_t *instr) {
     if ((cmd >> 7) == 0) {
        instr->opcode = MOVI;
        instr->opnd.imm = cmd & 0x7F;
        return 1;
    }

    if ((cmd >> 6) == 3) { 
        unsigned mode = (cmd >> 2) & 1;
        unsigned r = cmd & 3;

        instr->opnd.rop = r;
        instr->opcode = (mode == 0) ? IN : OUT;
        return 1;
    }

    unsigned op = cmd >> 4;
    unsigned rd = (cmd >> 2) & 3;
    unsigned rs = cmd & 3;

    instr->opnd.ops.rd = rd;
    instr->opnd.ops.rs = rs;

    switch (op) {
        case 8: instr->opcode = ADD; return 1;
        case 9: instr->opcode = SUB; return 1;
        case 10: instr->opcode = MUL; return 1;
        case 11: instr->opcode = DIV; return 1;
        default: return 0;
    }
}

const char *regnames[] = {"A", "B", "C", "D"};
const char *arithnames[] = {"ADD", "SUB", "MUL", "DIV"};

void print_instr(struct instr_t instr) {
    switch(instr.opcode) {
        case MOVI:
            printf("MOVI %d\n", instr.opnd.imm);
            break;
        case IN:
            printf("IN %s\n", regnames[instr.opnd.rop]);
            break;
        case OUT:
            printf("OUT %s\n", regnames[instr.opnd.rop]);
            break;
        case ADD:
        case SUB:
        case MUL:
        case DIV:
            printf("%s %s, %s\n", arithnames[instr.opcode - 8], 
                                 regnames[instr.opnd.ops.rd],
                                 regnames[instr.opnd.ops.rs]);
            break;
        default: 
            fprintf(stderr, "Unsupported inst\n");
            abort();
            break;
    }
}

int main() {
    unsigned command;

    while (scanf("%x", &command) == 1) {
        unsigned char cmd = command & 0xFF;

        if (cmd != command) {
            printf("ERROR\n");
            return 0;
        }

        struct instr_t instr;

        if (!decode_command(cmd, &instr)) {
            printf("ERROR\n");
            return 0;
        }

        print_instr(instr);
    }
}