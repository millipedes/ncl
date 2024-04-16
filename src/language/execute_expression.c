#include "include/execute_expression.h"

symbol_table execute_expression_assignment(ast head, symbol_table * st) {
  return add_symbol_to_table(*st, head.children[0].the_token.literal,
      execute_expression(head.children[2], st));
}

symbol execute_expression(ast head, symbol_table * st) {
  symbol return_symbol = {0};
  if(!head.children)
    return execute_symbol(head, st);
  switch(head.children[1].the_token.type) {
    case PLUS:
      return add_symbol(execute_expression(head.children[0], st),
          execute_expression(head.children[2], st));
    case MINUS:
      return sub_symbol(execute_expression(head.children[0], st),
          execute_expression(head.children[2], st));
    case INTEGER: // This is for unary minus
      return_symbol.type = NCL_INT;
      return_symbol.value.the_integer = -atoi(head.children[1].the_token.literal);
      break;
    case DOUBLE:  // This is for unary minus
      return_symbol.type = NCL_DOUBLE;
      return_symbol.value.the_integer = -atof(head.children[1].the_token.literal);
      break;
    case STAR:
      return mult_symbol(execute_expression(head.children[0], st),
          execute_expression(head.children[2], st));
    case SLASH:
      return div_symbol(execute_expression(head.children[0], st),
          execute_expression(head.children[2], st));
    case PERCENT:
      return mod_symbol(execute_expression(head.children[0], st),
          execute_expression(head.children[2], st));
    case LESS:
      return less_symbol(execute_expression(head.children[0], st),
          execute_expression(head.children[2], st));
    case GREATER:
      return great_symbol(execute_expression(head.children[0], st),
          execute_expression(head.children[2], st));
    case LESSEQUAL:
      return less_equal_symbol(execute_expression(head.children[0], st),
          execute_expression(head.children[2], st));
    case GREATEREQUAL:
      return great_equal_symbol(execute_expression(head.children[0], st),
          execute_expression(head.children[2], st));
  }
  return return_symbol;
}

symbol execute_symbol(ast head, symbol_table * st) {
  symbol return_symbol = {0};
  switch(head.the_token.type) {
  case STRING:
    return_symbol = init_symbol(head.the_token.literal, NCL_STRING);
    break;
  case FALSE:
    return_symbol.type = NCL_BOOL;
    return_symbol.value.the_bool = 0;
    break;
  case TRUE:
    return_symbol.type = NCL_BOOL;
    return_symbol.value.the_bool = 1;
    break;
  case DOUBLE:
    return_symbol.type = NCL_DOUBLE;
    return_symbol.value.the_double = atof(head.the_token.literal);
    break;
  case INTEGER:
    return_symbol.type = NCL_INT;
    return_symbol.value.the_integer = atoi(head.the_token.literal);
    break;
  case NAME:
    return_symbol = find_symbol(*st, head.the_token.literal);
    if(return_symbol.type)
      return return_symbol;
    fprintf(stderr, "[EXECUTE_EXPRESSION]: Unknown Variable: `%s`, Exiting\n",
        head.the_token.literal);
    exit(1);
  }
  return return_symbol;
}

symbol execute_unary_expression(ast head, symbol_table * st) {
  return execute_expression(head.children[0], st);
}
