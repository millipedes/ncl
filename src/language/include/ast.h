#ifndef AST_H
#define AST_H

#include "internal_node_type.h"
#include "token.h"

typedef struct AST_T {
  struct AST_T * children;
  token the_token;
  size_t qty_children;
  size_t category;
} ast;

ast init_ast(token the_token, size_t category);
void debug_ast(ast head, size_t level);
ast add_child(ast parent, ast child);
void free_ast(ast head);

#endif
