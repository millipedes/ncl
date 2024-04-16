#ifndef EXECUTE_EXPRESSION_H
#define EXECUTE_EXPRESSION_H

#include "ast.h"
#include "symbol_table.h"
#include "parser.tab.h"

symbol_table execute_expression_assignment(ast head, symbol_table * st);
symbol execute_expression(ast head, symbol_table * st);
symbol execute_symbol(ast head, symbol_table * st);
symbol execute_unary_expression(ast head, symbol_table * st);

#endif
