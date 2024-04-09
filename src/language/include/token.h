#ifndef TOKEN_H
#define TOKEN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main/include/constants_macros.h"

extern const char * token_type_to_string(size_t category);

typedef struct TOKEN_T {
  char * literal;
  size_t type;
} token;

token init_token(const char * literal, size_t type);
void debug_token(token the_token);
void free_token(token the_token);

#endif
