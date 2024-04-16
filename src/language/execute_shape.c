#include "include/execute_shape.h"

symbol_table execute_shape_assignment(ast head, symbol_table * st) {
  return add_symbol_to_table(*st, head.children[0].the_token.literal,
      execute_shape(head.children[2], st));
}

symbol execute_shape(ast head, symbol_table * st) {
  switch(head.category) {
    case IN_LINE_DECLARATION:
      line the_line = (line){
        (coord_2d){DEFAULT_X, DEFAULT_Y},         // to
        (coord_2d){2 * DEFAULT_X, 2 * DEFAULT_Y}, // from
        (pixel){DEFAULT_R, DEFAULT_G, DEFAULT_B},
        DEFAULT_LINE_THICKNESS
      };
      execute_line_parameters(head, st, &the_line);
      return init_symbol(&the_line, NCL_LINE);
    case IN_ELLIPSE_DECLARATION:
      ellipse the_ellipse = (ellipse){
        (coord_2d){DEFAULT_X, DEFAULT_Y},
        (pixel){DEFAULT_R, DEFAULT_G, DEFAULT_B},
        DEFAULT_ELLIPSE_MAJOR_AXIS,
        DEFAULT_ELLIPSE_MINOR_AXIS,
        DEFAULT_ELLIPSE_THICKNESS,
      };
      execute_ellipse_parameters(head, st, &the_ellipse);
      return init_symbol(&the_ellipse, NCL_ELLIPSE);
    case IN_RECTANGLE_DECLARATION:
      rectangle the_rectangle = (rectangle){
        (coord_2d){DEFAULT_X, DEFAULT_Y},
        (pixel){DEFAULT_R, DEFAULT_G, DEFAULT_B},
        DEFAULT_RECTANGLE_HEIGHT,
        DEFAULT_RECTANGLE_WIDTH,
        DEFAULT_RECTANGLE_THICKNESS,
      };
      execute_rectangle_parameters(head, st, &the_rectangle);
      return init_symbol(&the_rectangle, NCL_RECTANGLE);
    case IN_POINT_DECLARATION:
      return execute_point_declaration(head, st);
    case IN_COLOR_DECLARATION:
      return execute_color_declaration(head, st);
  }
  return (symbol){0};
}

void execute_line_parameters(ast head, symbol_table * st, line * params) {
  switch(head.category) {
    case IN_FROM_DECLARATION:
      params->from = shape_center(execute_unary_shape(head, st));
      break;
    case IN_TO_DECLARATION:
      params->to = shape_center(execute_unary_shape(head, st));
      break;
    case IN_COLOR_DECLARATION:
      symbol color = execute_color_declaration(head, st);
      params->color = (pixel){color.value.the_color.r,
                              color.value.the_color.g,
                              color.value.the_color.b};
      break;
    case IN_THICKNESS_DECLARATION:
      params->thickness = size_t_from_symbol(execute_unary_expression(head, st),
          "EXECUTE_LINE_PARAMETERS", "thickness");
      break;
  }
  for(size_t i = 0; i < head.qty_children; i++)
    execute_line_parameters(head.children[i], st, params);
}

coord_2d shape_center(symbol the_symbol) {
  switch(the_symbol.type) {
    case NCL_ELLIPSE:
      return the_symbol.value.the_ellipse.center;
    case NCL_RECTANGLE:
      return the_symbol.value.the_rectangle.center;
    case NCL_POINT:
      return the_symbol.value.the_point;
    default:
      fprintf(stderr, "[SHAPE_CENTER]: Unable to draw line to/from type `%s`, "
          "Exiting\n", ncl_type_to_string(the_symbol.type));
      exit(1);
  }
}

void execute_ellipse_parameters(ast head, symbol_table * st, ellipse * params) {
  switch(head.category) {
    case IN_MAJOR_AXIS_DECLARATION:
      params->major_axis = size_t_from_symbol(execute_unary_expression(head, st),
          "EXECUTE_ELLIPSE_PARAMETERS", "major_axis");
      break;
    case IN_MINOR_AXIS_DECLARATION:
      params->minor_axis = size_t_from_symbol(execute_unary_expression(head, st),
          "EXECUTE_ELLIPSE_PARAMETERS", "minor_axis");
      break;
    case IN_THICKNESS_DECLARATION:
      params->thickness = size_t_from_symbol(execute_unary_expression(head, st),
          "EXECUTE_ELLIPSE_PARAMETERS", "thickness");
      break;
    case IN_COLOR_DECLARATION:
      symbol color = execute_color_declaration(head, st);
      params->color = (pixel){color.value.the_color.r,
                              color.value.the_color.g,
                              color.value.the_color.b};
      break;
    case IN_POINT_DECLARATION:
      symbol point = execute_point_declaration(head, st);
      params->center = (coord_2d){point.value.the_point.x,
                                  point.value.the_point.y};
      break;
  }
  for(size_t i = 0; i < head.qty_children; i++)
    execute_ellipse_parameters(head.children[i], st, params);
}

void execute_rectangle_parameters(ast head, symbol_table * st, rectangle * params) {
  switch(head.category) {
    case IN_HEIGHT_DECLARATION:
      params->height = size_t_from_symbol(execute_unary_expression(head, st),
          "EXECUTE_REACTANGLE_PARAMETERS", "height");
      break;
    case IN_WIDTH_DECLARATION:
      params->width = size_t_from_symbol(execute_unary_expression(head, st),
          "EXECUTE_REACTANGLE_PARAMETERS", "width");
      break;
    case IN_THICKNESS_DECLARATION:
      params->thickness = size_t_from_symbol(execute_unary_expression(head, st),
          "EXECUTE_REACTANGLE_PARAMETERS", "thickness");
      break;
    case IN_COLOR_DECLARATION:
      symbol color = execute_color_declaration(head, st);
      params->color = (pixel){color.value.the_color.r,
                              color.value.the_color.g,
                              color.value.the_color.b};
      break;
    case IN_POINT_DECLARATION:
      symbol point = execute_point_declaration(head, st);
      params->center = (coord_2d){point.value.the_point.x,
                                  point.value.the_point.y};
      break;
  }
  for(size_t i = 0; i < head.qty_children; i++)
    execute_rectangle_parameters(head.children[i], st, params);
}

size_t size_t_from_symbol(symbol the_symbol, const char * where,
    const char * what) {
  switch(the_symbol.type) {
    case NCL_INT:
      return (size_t)the_symbol.value.the_integer;
    case NCL_DOUBLE:
      return (size_t)the_symbol.value.the_double;
    default:
      fprintf(stderr, "[%s]: Unsupported `%s` type\n", where, what);
      exit(1);
  }
}

symbol execute_point_declaration(ast head, symbol_table * st) {
  return init_symbol(&((coord_2d){
    execute_expression(head.children[0], st).value.the_double,
    execute_expression(head.children[1], st).value.the_double
  }), NCL_POINT);
}

symbol execute_color_declaration(ast head, symbol_table * st) {
  symbol r = execute_expression(head.children[0], st);
  symbol g = execute_expression(head.children[1], st);
  symbol b = execute_expression(head.children[2], st);
  if(r.type == NCL_INT && g.type == NCL_INT && b.type == NCL_INT) {
    pixel the_color = (pixel){r.value.the_integer,
                              g.value.the_integer,
                              b.value.the_integer};
    return init_symbol(&the_color, NCL_COLOR);
  } else {
    fprintf(stderr, "[EXECUTE_COLOR_DECLARATION]: Only int type is supported "
        "for color declartion. Types are r: `%s` g: `%s` b: `%s`, Exiting\n",
        ncl_type_to_string(r.type), ncl_type_to_string(g.type),
        ncl_type_to_string(b.type));
    exit(1);
  }
}

symbol execute_unary_shape(ast head, symbol_table * st) {
  return execute_shape(head.children[0], st);
}
