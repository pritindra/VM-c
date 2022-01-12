// instructions header file

#ifndef _INSTRUCTION_H
#define _INSTRUCTION_H
#include <stdio.h>
#include <stdint.h>

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

// special registers
enum
{
    MR_KBSR = 0xFE00, /* keyboard status */
    MR_KBDR = 0xFE02  /* keyboard data */
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

// trap flags
enum
{
    TRAP_GETC = 0x20,  /* get character from keyboard, not echoed onto the terminal */
    TRAP_OUT = 0x21,   /* output a character */
    TRAP_PUTS = 0x22,  /* output a word string */
    TRAP_IN = 0x23,    /* get character from keyboard, echoed onto the terminal */
    TRAP_PUTSP = 0x24, /* output a byte string */
    TRAP_HALT = 0x25   /* halt the program */
};

// macros
uint16_t memory[UINT16_MAX];
uint16_t reg[R_COUNT];

// lib functions
uint16_t sign_extend(uint16_t x, int bit_count);
void update_flags(uint16_t r);

void mem_write(uint16_t address, uint16_t val);
uint16_t mem_read(uint16_t address);

// instruction functions
void ADD(uint16_t instr);
void LDI(uint16_t instr);
void AND(uint16_t instr);
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

// trap functions
void GETC();
void OUT();
void PUTS();
void IN();
void PUTSP();
void HALT(int running);

#endif
