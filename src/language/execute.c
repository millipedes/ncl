#include "include/execute.h"

canvas execute_canvas_declaration(ast head, symbol_table st) {
  canvas the_canvas = (canvas){0};
  canvas_parameters params = (canvas_parameters){
    (pixel){DEFAULT_R, DEFAULT_G, DEFAULT_B},
    DEFAULT_CANVAS_HEIGHT,
    DEFAULT_CANVAS_WIDTH
  };
  if(head.children)
    execute_canvas_parameters(head.children[0], st, &params);
  the_canvas = init_canvas(params.height, params.width, params.color.r,
      params.color.g, params.color.b);
  return the_canvas;
}

void execute_canvas_parameters(ast head, symbol_table st,
    canvas_parameters * params) {
  switch(head.category) {
    case IN_HEIGHT_DECLARATION:
      symbol height = execute_height_declaration(head, st);
      switch(height.type) {
        case NCL_INT:
          params->height = height.value.the_integer;
          break;
        case NCL_DOUBLE:
          params->height = height.value.the_double;
          break;
        default:
          fprintf(stderr, "[EXECUTE_CANVAS_PARAMETERS]: Unsupported height type"
              "\n");
          exit(1);
      }
      break;
    case IN_WIDTH_DECLARATION:
      symbol width = execute_width_declaration(head, st);
      switch(width.type) {
        case NCL_INT:
          params->width = width.value.the_integer;
          break;
        case NCL_DOUBLE:
          params->width = width.value.the_double;
          break;
        default:
          fprintf(stderr, "[EXECUTE_CANVAS_PARAMETERS]: Unsupported with type"
              "\n");
          exit(1);
      }
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

symbol execute_width_declaration(ast head, symbol_table st) {
  return execute_expression(head.children[0], st);
}

symbol execute_height_declaration(ast head, symbol_table st) {
  return execute_expression(head.children[0], st);
}

symbol execute_color_declaration(ast head, symbol_table st) {
  symbol r = execute_expression(head.children[0], st);
  symbol g = execute_expression(head.children[1], st);
  symbol b = execute_expression(head.children[2], st);
  if(r.type == NCL_INT && g.type == NCL_INT && b.type == NCL_INT) {
    pixel the_color = (pixel){r.value.the_integer, g.value.the_integer, b.value.the_integer};
    return init_symbol(&the_color, NCL_COLOR);
  } else {
    fprintf(stderr, "[EXECUTE_COLOR_DECLARATION]: Only int type is supported "
        "for color declartion. Types are r: `%s` g: `%s` b: `%s`, Exiting\n",
        ncl_type_to_string(r.type), ncl_type_to_string(g.type),
        ncl_type_to_string(b.type));
    exit(1);
  }
}

symbol execute_expression(ast head, symbol_table st) {
  symbol return_symbol = {0};
  if(!head.children)
    return execute_symbol(head, st);
  switch(head.children[1].the_token.type) {
    case PLUS:
      return add_symbol(execute_expression(head.children[0], st),
          execute_expression(head.children[1], st));
    case MINUS:
      return sub_symbol(execute_expression(head.children[0], st),
          execute_expression(head.children[1], st));
    case STAR:
      return mult_symbol(execute_expression(head.children[0], st),
          execute_expression(head.children[1], st));
    case SLASH:
      return div_symbol(execute_expression(head.children[0], st),
          execute_expression(head.children[1], st));
    case PERCENT:
      return mod_symbol(execute_expression(head.children[0], st),
          execute_expression(head.children[1], st));
    case LESS:
      return less_symbol(execute_expression(head.children[0], st),
          execute_expression(head.children[1], st));
    case GREATER:
      return great_symbol(execute_expression(head.children[0], st),
          execute_expression(head.children[1], st));
    case LESSEQUAL:
      return less_equal_symbol(execute_expression(head.children[0], st),
          execute_expression(head.children[1], st));
    case GREATEREQUAL:
      return great_equal_symbol(execute_expression(head.children[0], st),
          execute_expression(head.children[1], st));
  }
  return return_symbol;
}

symbol execute_symbol(ast head, symbol_table st) {
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
    return_symbol = find_symbol(st, head.the_token.literal);
    if(return_symbol.type)
      return return_symbol;
    fprintf(stderr, "[EXECUTE_EXPRESSION]: Unknown Variable: `%s`, Exiting\n",
        head.the_token.literal);
    exit(1);
  }
  return return_symbol;
}
