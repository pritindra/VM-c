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
                AND(instr);
                break;
            case OP_NOT:
                NOT(instr);
                break;
            case OP_BR:
                BR (instr);
                break;
            case OP_JMP:
                JMP(instr);
                break;
            case OP_JSR:
                JSR(instr);
                break;
            case OP_LD:
                LD(instr);
                break;
            case OP_LDI:
                LDI(instr);
                break;
            case OP_LDR:
                LDR(instr);
                break;
            case OP_LEA:
                LEA(instr);
                break;
            case OP_ST:
                ST(instr);
                break;
            case OP_STI:
                STI(instr);
                break;
            case OP_STR:
                STR(instr);
                break;
            case OP_TRAP:
                switch (instr & 0xFF)
                {
                    case TRAP_GETC:
                        GETC();
                        break;
                    case TRAP_OUT:
                        OUT();
                        break;
                    case TRAP_PUTS:
                        PUTS();
                        break;
                    case TRAP_IN:
                        IN();
                        break;
                    case TRAP_PUTSP:
                        PUTSP();
                        break;
                    case TRAP_HALT:
                        HALT(running);
                        break;
                }
                break;
            case OP_RES:
            case OP_RTI:
            default:
                abort();
                break;
        }
    }
    restore_input_buffering();
}



