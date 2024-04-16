#ifndef EXECUTE_SHAPE_H
#define EXECUTE_SHAPE_H

#include "execute_expression.h"

symbol_table execute_shape_assignment(ast head, symbol_table * st);
symbol execute_shape(ast head, symbol_table * st);
void execute_line_parameters(ast head, symbol_table * st, line * params);
coord_2d shape_center(symbol the_symbol);
void execute_rectangle_parameters(ast head, symbol_table * st,
    rectangle * params);
void execute_ellipse_parameters(ast head, symbol_table * st, ellipse * params);
size_t size_t_from_symbol(symbol the_symbol, const char * where,
    const char * what);
symbol execute_point_declaration(ast head, symbol_table * st);
symbol execute_color_declaration(ast head, symbol_table * st);
symbol execute_unary_shape(ast head, symbol_table * st);

#endif
