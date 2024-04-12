#include "include/symbol_table.h"

size_t djb2_hash(const char * value) {
  size_t value_len = strnlen(value, MAX_SYMBOL_BYTES);
  size_t hash_value = DJB2_HASH_VALUE;
  for(size_t i = 0; i < value_len; i++)
    hash_value = (hash_value * DJB2_HASH_MULTIPLE) ^ (size_t)value[i];
  return hash_value % QTY_BUCKETS;
}

symbol_table add_entry(symbol_table map, const char * name, const void * value,
    ncl_type type) {
  size_t key = djb2_hash(value);
  map.values[key] = append_symbol_ll(map.values[key], init_symbol_ll(name, value, type));
  return map;
}

void debug_symbol_table(symbol_table map) {
  for(int i = 0; i < QTY_BUCKETS; i++) {
    printf("%d: ", i);
    debug_symbol_ll(map.values[i]);
    printf("\n");
  }
}

void free_symbol_table(symbol_table map) {
  for(int i = 0; i < QTY_BUCKETS; i++)
    free_symbol_ll(map.values[i]);
}
