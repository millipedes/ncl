#include "include/ast.h"

ast init_ast(token the_token, size_t category) {
  ast the_ast = {0};
  the_ast.children = NULL;
  the_ast.the_token = the_token;
  the_ast.category = category;
  the_ast.qty_children = 0;
  return the_ast;
}

void debug_ast(ast head, size_t level) {
  PRINT_C_N(' ', level)
  if(!head.children) {
    printf("[AST] (non-internal): ");
    debug_token(head.the_token);
  } else {
    printf("[AST] (internal): %s\n",
        internal_node_type_to_string(head.category));
    for(size_t i = 0; i < head.qty_children; i++)
      debug_ast(head.children[i], level + 1);
  }
}

ast add_child(ast parent, ast child) {
  if(child.category == IN_NULL)
    return parent;

  parent.qty_children++;
  if(parent.children) {
    parent.children = realloc(parent.children,
        parent.qty_children * sizeof(struct AST_T));
  } else {
    parent.children = calloc(1, sizeof(struct AST_T));
  }
  parent.children[parent.qty_children - 1] = child;
  return parent;
}

void free_ast(ast head) {
  if(head.children) {
    for(size_t i = 0; i < head.qty_children; i++)
      free_ast(head.children[i]);
    free(head.children);
  }
  free_token(head.the_token);
}
