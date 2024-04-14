#ifndef SYM_TAB_H
#define SYM_TAB_H

#include "general/include/linked_list.h"

#define DJB2_HASH_VALUE    5381
#define DJB2_HASH_MULTIPLE 33

#define QTY_BUCKETS 37

size_t djb2_hash(const char * value);

typedef struct SYMBOL_TABLE_T {
  symbol_ll values[QTY_BUCKETS];
} symbol_table;

symbol_table init_symbol_table(void);
symbol_table add_entry(symbol_table st, const char * name, const void * value,
    ncl_type type);
symbol find_symbol(symbol_table st, const char * name);
void debug_symbol_table(symbol_table st);
void free_symbol_table(symbol_table st);

#endif
