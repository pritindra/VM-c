// instructions header file

#ifndef _INSTRUCTION_H
#define _INSTRUCTION_H
#include <stdio.h>
#include <stdint.h>

uint16_t memory[UINT16_MAX];
uint16_t reg[R_COUNT];

// registers
enum
{
    R_R0 = 0,
    R_R1,
    R_R2,
    R_R3,
    R_R4,
    R_R5,
    R_R6,
    R_R7,
    R_PC, /* program counter */
    R_COND,
    R_COUNT
};

// opcodes
enum
{
    OP_BR = 0, /* branch */
    OP_ADD,    /* add  */
    OP_LD,     /* load */
    OP_ST,     /* store */
    OP_JSR,    /* jump register */
    OP_AND,    /* bitwise and */
    OP_LDR,    /* load register */
    OP_STR,    /* store register */
    OP_RTI,    /* unused */
    OP_NOT,    /* bitwise not */
    OP_LDI,    /* load indirect */
    OP_STI,    /* store indirect */
    OP_JMP,    /* jump */
    OP_RES,    /* reserved (unused) */
    OP_LEA,    /* load effective address */
    OP_TRAP    /* execute trap */
};
// sign extend and flags functions

// condition flags
enum
{
    FL_POS = 1 << 0, /* P */
    FL_ZRO = 1 << 1, /* Z */
    FL_NEG = 1 << 2, /* N */
};

uint16_t sign_extend(uint16_t x, int bit_count);
void update_flags(uint16_t r);

// instruction functions
void ADD(uint16_t instr);
void LDI(uint16_t instr);
void NOT(uint16_t instr);
void BR(uint16_t instr);
void JMP(uint16_t instr);
void JSR(uint16_t instr);
void LD(uint16_t instr);
void LDR(uint16_t instr);
void LEA(uint16_t instr);
void ST(uint16_t instr);
void STI(uint16_t instr);
void STR(uint16_t instr);

#endif
