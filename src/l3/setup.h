#ifndef _SETUP_H
#define _SETUP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <signal.h>
/* unix */
#include <unistd.h>
#include <fcntl.h>

#include <sys/time.h>
#include <sys/types.h>
#include <sys/termios.h>
#include <sys/mman.h>

struct termios original_tio;

// setup functions
uint16_t check_key();
void disable_input_buffering();
void restore_input_buffering();
void handle_interrupt(int signal);

// loading functions
void read_image_file(FILE *file);
uint16_t swap16(uint16_t x);
int read_image(const char * image_path);


#endif
