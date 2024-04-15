#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "language/include/symbol.h"

typedef struct SYMBOL_LL_T {
  char * name;
  symbol value;
  struct SYMBOL_LL_T * next;
} symbol_ll;

symbol_ll init_symbol_ll_from_data(const char * name, const void * value,
    ncl_type type);
symbol_ll init_symbol_ll_from_symbol(const char * name, symbol the_symbol);
symbol symbol_in_list(symbol_ll the_symbol_ll, const char * name);
void debug_symbol_ll(symbol_ll the_symbol_ll);
symbol_ll append_symbol_ll(symbol_ll head, symbol_ll tail);
void free_symbol_ll(symbol_ll the_symbol_ll);

#endif
