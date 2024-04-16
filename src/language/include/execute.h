#ifndef EXECUTE_H
#define EXECUTE_H

#include "execute_shape.h"

canvas execute_canvas_declaration(ast head, symbol_table * st);
void execute_canvas_parameters(ast head, symbol_table * st, canvas_parameters * params);
void execute_star_newline_stmt(ast head, symbol_table * st);
void execute_pick_newline_stmt(ast head, symbol_table * st);

#endif
