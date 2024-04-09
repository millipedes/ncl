#include "include/token.h"

token init_token(const char * literal, size_t type) {
  token the_token = {0};
  the_token.type = type;
  size_t literal_size = strnlen(literal, MAX_TOK_LEN) + 1;
  the_token.literal = calloc(literal_size, sizeof(char));
  strncpy(the_token.literal, literal, literal_size);
  return the_token;
}

void debug_token(token the_token) {
  printf("%s: `%s`\n", token_type_to_string(the_token.type), the_token.literal);
}

void free_token(token the_token) {
  if(the_token.literal)
    free(the_token.literal);
}
