#include "include/linked_list.h"

symbol_ll init_symbol_ll(const char * name, const void * value, ncl_type type) {
  symbol_ll the_symbol_ll = {0};
  size_t name_len = strnlen(name, MAX_SYMBOL_BYTES) + 1;
  the_symbol_ll.name = calloc(name_len, sizeof(char));
  strncpy(the_symbol_ll.name, name, name_len);
  the_symbol_ll.value = init_symbol(value, type);
  the_symbol_ll.next = NULL;
  return the_symbol_ll;
}

symbol symbol_in_list(symbol_ll the_symbol_ll, const char * name) {
  if(!strncmp(the_symbol_ll.name, name, MAX_SYMBOL_BYTES))
    return the_symbol_ll.value;
  else if(the_symbol_ll.next)
    return symbol_in_list(*the_symbol_ll.next, name);
  else
    return (symbol){0};
}

void debug_symbol_ll(symbol_ll the_symbol_ll) {
  if(the_symbol_ll.name) {
    printf("`%s`: ", the_symbol_ll.name);
    debug_symbol(the_symbol_ll.value);
    if(the_symbol_ll.next)
      debug_symbol_ll(*the_symbol_ll.next);
  }
}

symbol_ll append_symbol_ll(symbol_ll head, symbol_ll tail) {
  if(!head.name)
    return tail;
  symbol_ll * tmp = &head;
  while(tmp->next) tmp = tmp->next;
  tmp->next = calloc(1, sizeof(struct SYMBOL_LL_T));
  *tmp->next = tail;
  return head;
}

void free_symbol_ll(symbol_ll the_symbol_ll) {
  free_symbol(the_symbol_ll.value);
  if(the_symbol_ll.name)
    free(the_symbol_ll.name);
  if(the_symbol_ll.next)
    free_symbol_ll(*the_symbol_ll.next);
  if(the_symbol_ll.next)
    free(the_symbol_ll.next);
}
