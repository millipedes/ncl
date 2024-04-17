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
    the_canvas = init_canvas(params.height, params.width, params.color.r,
        params.color.g, params.color.b);
    execute_star_newline_stmt(head.children[1], st, &the_canvas);
  }
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

void execute_star_newline_stmt(ast head, symbol_table * st, canvas * the_canvas) {
  for(size_t i = 0; i < head.qty_children; i++) {
    switch(head.children[i].category) {
      case IN_STAR_NEWLINE_STMT:
        execute_star_newline_stmt(head.children[i], st, the_canvas);
        break;
      case IN_PICK_NEWLINE_STMT:
        execute_pick_newline_stmt(head.children[i], st, the_canvas);
        break;
    }
  }
}

void execute_pick_newline_stmt(ast head, symbol_table * st, canvas * the_canvas) {
  switch(head.children[0].category) {
    case IN_EXPRESSION_ASSIGNMENT:
      *st = execute_expression_assignment(head.children[0], st);
      break;
    case IN_SHAPE_ASSIGNMENT:
      *st = execute_shape_assignment(head.children[0], st);
      break;
    case IN_IF_STMT:
      execute_if_stmt(head.children[0], st, the_canvas);
      break;
    case IN_FOR_LOOP:
      execute_for_loop(head.children[0], st, the_canvas);
      break;
    case IN_WRITE:
      execute_write(head.children[0], st, the_canvas);
      break;
  }
}

void execute_if_stmt(ast head, symbol_table * st, canvas * the_canvas) {
  if(symbol_true(execute_expression(head.children[0], st)))
    execute_star_newline_stmt(head.children[1], st, the_canvas);
}

void execute_for_loop(ast head, symbol_table * st, canvas * the_canvas) {
  if(head.qty_children == 3) {
    for(double i = 0; i < symbol_bound(execute_expression(head.children[1], st)); i++) {
      *st = add_symbol_to_table(*st, head.children[0].the_token.literal,
          init_symbol(&i, NCL_NUMBER));
      execute_star_newline_stmt(head.children[2], st, the_canvas);
    }
  } else if(head.qty_children == 4) {
    for(double i = symbol_bound(execute_expression(head.children[1], st));
        i < symbol_bound(execute_expression(head.children[2], st)); i++) {
      *st = add_symbol_to_table(*st, head.children[0].the_token.literal,
          init_symbol(&i, NCL_NUMBER));
      execute_star_newline_stmt(head.children[3], st, the_canvas);
    }
  }
}

void execute_write(ast head, symbol_table * st, canvas * the_canvas) {
  switch(head.children[0].category) {
    case IN_ELLIPSE_DECLARATION:
    case IN_LINE_DECLARATION:
    case IN_RECTANGLE_DECLARATION:
      write_shape_symbol_to_canvas(execute_shape(head.children[0], st), the_canvas);
      break;
    case NAME:
      symbol return_symbol = find_symbol(*st, head.children[0].the_token.literal);
      if(return_symbol.type) {
        write_shape_symbol_to_canvas(return_symbol, the_canvas);
      } else {
        fprintf(stderr, "[EXECUTE_WRITE]: Unknown Variable: `%s`, Exiting\n",
            head.the_token.literal);
        exit(1);
      }
  }
}
