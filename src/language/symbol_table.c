#include "include/symbol_table.h"

size_t djb2_hash(const char * value) {
  size_t value_len = strnlen(value, MAX_SYMBOL_BYTES);
  size_t hash_value = DJB2_HASH_VALUE;
  for(size_t i = 0; i < value_len; i++)
    hash_value = (hash_value * DJB2_HASH_MULTIPLE) ^ (size_t)value[i];
  return hash_value % QTY_BUCKETS;
}

symbol_table add_symbol_to_table(symbol_table st, const char * name,
    symbol the_symbol) {
  size_t key = djb2_hash(name);
  st.values[key] = update_symbol_ll(st.values[key],
      init_symbol_ll_from_symbol(name, the_symbol));
  return st;
}

symbol find_symbol(symbol_table st, const char * name) {
  size_t hash_value = djb2_hash(name);
  return symbol_in_list(st.values[hash_value], name);
}

void debug_symbol_table(symbol_table st) {
  for(int i = 0; i < QTY_BUCKETS; i++) {
    printf("%d: ", i);
    debug_symbol_ll(st.values[i]);
    printf("\n");
  }
}

void free_symbol_table(symbol_table st) {
  for(int i = 0; i < QTY_BUCKETS; i++)
    free_symbol_ll(st.values[i]);
}
