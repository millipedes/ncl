#ifndef EXECUTE_H
#define EXECUTE_H

#include "ast.h"
#include "symbol_table.h"
#include "parser.tab.h"

canvas execute_canvas_declaration(ast head, symbol_table st);
void execute_canvas_parameters(ast head, symbol_table st, canvas_parameters * params);
symbol execute_width_declaration(ast head, symbol_table st);
symbol execute_height_declaration(ast head, symbol_table st);
symbol execute_color_declaration(ast head, symbol_table st);
symbol execute_expression(ast head, symbol_table st);
symbol execute_symbol(ast head, symbol_table st);

#endif
