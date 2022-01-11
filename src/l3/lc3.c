#include "setup.h"
#include "instruction.h"


// main program
int main(int argc, const char* argv[])
{
    if (argc < 2)
    {
        /* show usage string */
        printf("lc3 [image-file1] ...\n");
        exit(2);
    }
    
    for (int j = 1; j < argc; ++j)
    {
        if (!read_image(argv[j]))
        {
            printf("failed to load image: %s\n", argv[j]);
            exit(1);
        }
    }

    signal(SIGINT, handle_interrupt);
    disable_input_buffering();

    /* since exactly one condition flag should be set at any given time, set the Z flag */
    reg[R_COND] = FL_ZRO;

    /* set the PC to starting position */
    /* 0x3000 is the default */
    enum { PC_START = 0x3000 };
    reg[R_PC] = PC_START;

    int running = 1;
    while (running)
    {
        /* FETCH */
        uint16_t instr = mem_read(reg[R_PC]++);
        uint16_t op = instr >> 12;

        switch (op)
        {
            case OP_ADD:
                ADD(instr);
                break;
            case OP_AND:
                {AND, 7}
                break;
            case OP_NOT:
                {NOT, 7}
                break;
            case OP_BR:
                {BR, 7}
                break;
            case OP_JMP:
                {JMP, 7}
                break;
            case OP_JSR:
                {JSR, 7}
                break;
            case OP_LD:
                {LD, 7}
                break;
            case OP_LDI:
                {LDI, 6}
                break;
            case OP_LDR:
                {LDR, 7}
                break;
            case OP_LEA:
                {LEA, 7}
                break;
            case OP_ST:
                {ST, 7}
                break;
            case OP_STI:
                {STI, 7}
                break;
            case OP_STR:
                {STR, 7}
                break;
            case OP_TRAP:
                {TRAP, 8}
                break;
            case OP_RES:
            case OP_RTI:
            default:
                {BAD OPCODE, 7}
                break;
        }
    }
    restore_input_buffering();
}



