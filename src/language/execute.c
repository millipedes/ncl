#include "include/execute.h"

canvas execute_canvas_declaration(ast head, symbol_table * st) {
  canvas the_canvas = (canvas){0};
  canvas_parameters params = (canvas_parameters){
    (pixel){DEFAULT_R, DEFAULT_G, DEFAULT_B},
    DEFAULT_CANVAS_HEIGHT,
    DEFAULT_CANVAS_WIDTH
  };
  if(head.children) {
    execute_canvas_parameters(head.children[0], st, &params);
    execute_star_newline_stmt(head.children[1], st);
  }

  the_canvas = init_canvas(params.height, params.width, params.color.r,
      params.color.g, params.color.b);
  return the_canvas;
}

void execute_canvas_parameters(ast head, symbol_table * st,
    canvas_parameters * params) {
  switch(head.category) {
    case IN_HEIGHT_DECLARATION:
      params->height = size_t_from_symbol(execute_unary_expression(head, st),
          "EXECUTE_CANVAS_PARAMETERS", "height");
      break;
    case IN_WIDTH_DECLARATION:
      params->width = size_t_from_symbol(execute_unary_expression(head, st),
          "EXECUTE_CANVAS_PARAMETERS", "width");
      break;
    case IN_COLOR_DECLARATION:
      symbol color = execute_color_declaration(head, st);
      params->color = (pixel){color.value.the_color.r,
                              color.value.the_color.g,
                              color.value.the_color.b};
      break;
  }
  for(size_t i = 0; i < head.qty_children; i++)
    execute_canvas_parameters(head.children[i], st, params);
}

void execute_star_newline_stmt(ast head, symbol_table * st) {
  for(size_t i = 0; i < head.qty_children; i++) {
    switch(head.children[i].category) {
      case IN_STAR_NEWLINE_STMT:
        execute_star_newline_stmt(head.children[i], st);
        break;
      case IN_PICK_NEWLINE_STMT:
        execute_pick_newline_stmt(head.children[i], st);
        break;
    }
  }
}

void execute_pick_newline_stmt(ast head, symbol_table * st) {
  switch(head.children[0].category) {
    case IN_EXPRESSION_ASSIGNMENT:
      *st = execute_expression_assignment(head.children[0], st);
      break;
    case IN_SHAPE_ASSIGNMENT:
      *st = execute_shape_assignment(head.children[0], st);
      break;
  }
}
