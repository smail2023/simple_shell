#ifndef SHELL_H
#define SHELL_H

/* Required libraries or other headers should be included here. */
#include <unistd.h>

/* Definition for the info_t struct */
typedef struct info
{
int readfd;
} info_t;

/* Function prototypes */
int a_to_b(char *j);
int is_m_char(int e);
int verify_mode(info_t *u);
int is_n_delim(char e, char *z);

#endif
